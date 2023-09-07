#include "scene.h"

Scene::Scene()
{
    QPen pen(QBrush(Qt::black), 10);
    addRect(-200, -200, 400, 400, pen, QBrush(Qt::NoBrush));
    addRect(50, 50, 150, 150, QPen(Qt::NoPen), QBrush(Qt::red));

    drawSphere(0, 5.43, 78.345);
    addRect(0, 0, 5, 5, QPen(Qt::NoPen), QBrush(Qt::blue));

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    emit mousePressed(event->scenePos().x(), event->scenePos().y());
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    if(x > -1 * width / 2 && x < width / 2 && y > -1 * height / 2 && y < height / 2){
        //qDebug()<<"Scene event: "<<event->scenePos().x()<<" "<<event->scenePos().y();
        //drawCrosshair(x, y);
        emit changeCursorPosition(x, y);
    }
    else{
        emit changeCursorPosition(1e8, 1e8);
    }
}

void Scene::drawCrosshair(qreal x, qreal y)
{
    addLine(-1 * width / 2, y, width / 2, y, QPen(Qt::red));
    addLine(x, -1 * height / 2, x, height / 2, QPen(Qt::red));
}

void Scene::setSceneSize(qreal _width, qreal _height)
{
    width = _width;
    height = _height;
}

void Scene::drawSphere(qreal x, qreal y, qreal r)
{
    addEllipse(x-r, y-r, 2*r, 2*r, QPen(Qt::NoPen), QBrush(Qt::magenta));
}

void Scene::drawSelected(qreal x, qreal y, qreal r)
{
    addRect(x-r, y-r, 2*r, 2*r, QPen(Qt::black), QBrush(Qt::NoBrush));
}

void Scene::drawArrow(qreal x, qreal y, direction direct)
{
    if(direct == up){
        addRect(x, y-3, 1, 7, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == upleft){
        addRect(x, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+3, y+3, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == left){
        addRect(x-3, y, 7, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == downleft){
        addRect(x, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+3, y-3, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == down){
        addRect(x, y-3, 1, 7, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == downright){
        addRect(x, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-3, y-3, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == right){
        addRect(x-3, y, 7, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else if(direct == upright){
        addRect(x, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-1, y+1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-2, y+2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x-3, y+3, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+2, y-1, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
        addRect(x+1, y-2, 1, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    }
    else{
        qDebug()<<"Unknown direction of an arrow";
    }
}

void Scene::drawLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    addLine(x1, y1, x2, y2);
}
