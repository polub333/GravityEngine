#include "engine.h"

Engine::Engine()
{
    maxVel = 0;
    maxX = 0;
    forceField = false;
}

void Engine::setScene(Scene* _scene)
{
    scene = _scene;
    connect(scene, SIGNAL(changeCursorPosition(qreal, qreal)), this, SLOT(changeCursorPosition(qreal, qreal)));
    connect(scene, SIGNAL(mousePressed(qreal, qreal)), this, SLOT(mousePressed(qreal, qreal)));
}

void Engine::setSettings(Settings _settings)
{
    settings = _settings;
}

void Engine::setForceField(const bool _forceField)
{
    forceField = _forceField;
}

bool Engine::getForceField() const
{
    return forceField;
}

void Engine::addBody(qreal x, qreal y, qreal velX, qreal velY, qreal mass, QString name)
{
    Body* body = new Body();
    body->setCoordinates(x, y);
    body->setVelocity(velX, velY);
    body->setMass(mass);
    if(name == "NONE"){
        body->setName("Body #" + QString::number(bodies.size() + 1));
    }
    else{
        body->setName(name);
    }
    bodies.push_back(body);
}

void Engine::drawAllBodies()
{
    scene->clear();
    emit setSelectedBody(nullptr);
    if(cursorPosition.first != 1e8 && cursorPosition.second != 1e8){
        //scene->drawCrosshair(cursorPosition.first, cursorPosition.second);
    }
    if(forceField){
        drawForces();
    }
    for(int i=0;i<bodies.size();++i){
        std::pair<qreal, qreal> coordinates = bodies[i]->getCoordinates();
        scene->drawSphere(coordinates.first, coordinates.second, 5);
        if(bodies[i]->getSelected()){
            scene->drawSelected(coordinates.first, coordinates.second, 5);
            emit setSelectedBody(bodies[i]);
        }
    }
}

void Engine::changeAllBodies()
{
    qreal res = settings.getResolution();
    qreal inter = settings.getTimeBoost() / 1000;

    for(int kol = 0; kol < res; ++kol){
        for(int i=0;i<bodies.size();++i){
        std::pair<qreal, qreal> coord = bodies[i]->getCoordinates();
        std::pair<qreal, qreal> force = computeForces(coord.first, coord.second);
        bodies[i]->updateStatistics(inter / res);

        bodies[i]->changeCoordinatesDueVelocity(inter / res);
        bodies[i]->changeVelocityDueForce(force.first, force.second, inter / res);
    }
    }
}

std::pair<qreal, qreal> Engine::computeForces(qreal x, qreal y)
{
    qreal xForce = 0, yForce = 0;
    for(int i=0;i<bodies.size();++i){
        std::pair<qreal, qreal> coord = bodies[i]->getCoordinates();
        if(coord.first == x && coord.second == y){
            continue;
        }
        qreal dist =  sqrt((coord.first - x)*(coord.first - x) + (coord.second - y)*(coord.second - y));
        qreal cos = (coord.first - x) / dist;
        qreal sin = (coord.second - y) / dist;
        qreal dfx = bodies[i]->getMass();
        dfx /= dist;
        dfx /= dist;
        dfx *= cos;
        xForce += dfx;
        yForce += bodies[i]->getMass() / (dist*dist) * sin;
    }
    return std::pair<qreal, qreal>(xForce, yForce);
}

void Engine::drawForces()
{
    for(int x=-190;x<190;x+=20){
        for(int y=-190;y<190;y+=20){
            std::pair<qreal, qreal> force = computeForces(x, y);
            qreal tg = force.second / force.first;
            if(tg > -sqrt(3)/3 && tg < sqrt(3)/3){
                if(force.first >= 0){
                    scene->drawArrow(x, y, right);
                }
                else{
                    scene->drawArrow(x, y, left);
                }
            }
            else if(tg > sqrt(3)/3 && tg < sqrt(3)){
                if(force.first >= 0){
                    scene->drawArrow(x, y, downright);
                }
                else{
                    scene->drawArrow(x, y, upleft);
                }
            }
            else if(abs(tg) > sqrt(3)){
                if(force.second >= 0){
                    scene->drawArrow(x, y, down);
                }
                else{
                    scene->drawArrow(x, y, up);
                }
            }
            else{
                if(force.first >= 0){
                    scene->drawArrow(x, y, upright);
                }
                else{
                    scene->drawArrow(x, y, downleft);
                }
            }
        }
    }
}

void Engine::changeCursorPosition(qreal x, qreal y)
{
    cursorPosition.first = x;
    cursorPosition.second = y;
}

void Engine::mousePressed(qreal x, qreal y)
{
    for(int i=0;i<bodies.size();++i){
        if(bodies[i]->contains(x, y)){
            for(int i=0;i<bodies.size();++i){
                bodies[i]->setSelected(false);
            }
            bodies[i]->setSelected(true);
            break;
        }
    }
}
#include <direct.h>
void Engine::importBodySystem(const QString path)
{
    clearSystem();
    std::fstream file(path.toStdString(), std::ios_base::in);
    qDebug()<<path;
    char p[FILENAME_MAX];
    _getcwd(p, sizeof(p));
    p[sizeof(p)-1] = '\0';
    //printf("%s", p);
    qDebug()<<p;
    int planetNum;
    file >> planetNum;
    qDebug()<<planetNum;
    for(int i=0;i<planetNum;++i){
        qreal xCoord, yCoord, xVelocity, yVelocity, mass;
        std::string name;
        std::getline(file, name);
        std::getline(file, name);
        file>>xCoord>>yCoord>>xVelocity>>yVelocity>>mass;
        addBody(xCoord, yCoord, xVelocity, yVelocity, mass, QString::fromStdString(name));
        qDebug()<<QString::fromStdString(name)<<xCoord<<yCoord<<xVelocity<<yVelocity<<mass;
        /*
        bodies[i]->setName(QString::fromStdString(name));
        bodies[i]->setCoordinates(xCoord, yCoord);
        bodies[i]->setVelocity(xVelocity, yVelocity);
        bodies[i]->setMass(mass);
        */
    }
    file.close();
}

void Engine::exportBodySystem()
{
    exportBodySystem("Systems/system.txt");
}

void Engine::exportBodySystem(const QString path)
{
    std::fstream file(path.toStdString(), std::ios_base::out);
    int planetNum = bodies.size();
    file<<planetNum<<std::endl;
    for(int i=0; i<planetNum;++i){
        file<<bodies[i]->getName().toStdString()<<std::endl;
        file<<bodies[i]->getCoordinates().first<<std::endl;
        file<<bodies[i]->getCoordinates().second<<std::endl;
        file<<bodies[i]->getVelocity().first<<std::endl;
        file<<bodies[i]->getVelocity().second<<std::endl;
        file<<bodies[i]->getMass()<<std::endl;
    }
    file.close();
}

void Engine::clearSystem()
{
    bodies.clear();
}

void Engine::drawForceFields()
{
    for(int x = -100; x<100;x += 20){
        for(int y=-100; y < 100;y += 20){
            std::pair<qreal, qreal> force = computeForces(x, y);
            qreal angle = force.second / force.second;
            std::pair<qreal, qreal> point = std::make_pair<qreal, qreal>(x, y);
            qreal length = 10;
            scene->drawLine(point, length, angle);
        }
    }
}
