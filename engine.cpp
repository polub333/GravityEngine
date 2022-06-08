#include "engine.h"

Engine::Engine()
{
    maxVel = 0;
    maxX = 0;
}

void Engine::setScene(Scene* _scene)
{
    scene = _scene;
}

void Engine::setInter(qreal _inter)
{
    inter = _inter / 1000;
}

void Engine::addBody(qreal x, qreal y, qreal velX, qreal velY, qreal mass)
{
    Body* body = new Body();
    body->setCoordinates(x, y);
    body->setVelocity(velX, velY);
    body->setMass(mass);
    bodies.push_back(body);
}

void Engine::drawAllBodies()
{
    scene->clear();
    for(int i=0;i<bodies.size();++i){
        std::pair<qreal, qreal> coordinates = bodies[i]->getCoordinates();
        scene->drawSphere(coordinates.first, coordinates.second, 5);
    }
    qDebug()<<"Max Vel: "<<maxVel<<" Max X Coord: "<<maxX;

}

void Engine::changeAllBodies()
{
    for(int i=0;i<bodies.size();++i){
        std::pair<qreal, qreal> coord = bodies[i]->getCoordinates();
        std::pair<qreal, qreal> force = computeForces(coord.first, coord.second);
        //qDebug()<<"Force: "<<force.first<<" "<<force.second;
        //qDebug()<<"Coord: "<<coord.first<<" "<<coord.second;
        std::pair<qreal, qreal> vel = bodies[i]->getVelocity();
        qreal vel0 = vel.first * vel.first + vel.second * vel.second;
        if(vel0 > maxVel){
            maxVel = vel0;
        }
        if(coord.first > maxX){
            maxX = coord.first;
        }

        bodies[i]->changeCoordinatesDueVelocity(inter);
        bodies[i]->changeVelocityDueForce(force.first, force.second, inter);
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
        //xForce += bodies[i]->getMass() / (dist*dist) * cos;
        yForce += bodies[i]->getMass() / (dist*dist) * sin;
    }
    return std::pair<qreal, qreal>(xForce, yForce);
}
