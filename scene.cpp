#include "scene.h"

Scene::Scene()
{
    //addRect(-50, -75, 100, 150, QPen(Qt::NoPen), QBrush(Qt::red));
    QPen pen(QBrush(Qt::black), 10);
    addRect(-200, -200, 400, 400, pen, QBrush(Qt::NoBrush));
    addRect(50, 50, 150, 150, QPen(Qt::NoPen), QBrush(Qt::red));

    drawSphere(0, 5.43, 78.345);
    addRect(0, 0, 5, 5, QPen(Qt::NoPen), QBrush(Qt::blue));

}

void Scene::drawSphere(qreal x, qreal y, qreal r)
{
    //qDebug()<<"lol";
    addEllipse(x-r, y-r, 2*r, 2*r, QPen(Qt::NoPen), QBrush(Qt::magenta));
    addRect(x-r, y-r, 2*r, 2*r, QPen(Qt::black), QBrush(Qt::NoBrush));
}
