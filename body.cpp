#include "body.h"

Body::Body()
{

}

void Body::setCoordinates(qreal _x, qreal _y)
{
    x = _x;
    y = _y;
}

void Body::setVelocity(qreal _velX, qreal _velY)
{
    velX = _velX;
    velY = _velY;
}

void Body::setMass(qreal _mass)
{
    mass = _mass;
}

std::pair<qreal, qreal> Body::getCoordinates() const
{
    return std::pair<qreal, qreal>(x, y);
}

std::pair<qreal, qreal> Body::getVelocity() const
{
    return std::pair<qreal, qreal>(velX, velY);
}

qreal Body::getMass() const
{
    return mass;
}

void Body::changeCoordinatesDueVelocity(const qreal time)
{
    x += velX * time;
    y += velY * time;
}

void Body::changeVelocityDueForce(const qreal forceX, const qreal forceY, const qreal time)
{
    velX += forceX * time;
    velY += forceY * time;
}
