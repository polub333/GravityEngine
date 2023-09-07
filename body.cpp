#include "body.h"

Body::Body()
{
    isSelected = false;
    maxX = -1e9;
    minX = 1e9;
    maxY = -1e9;
    minY = 1e9;
    maxVelX = -1e9;
    minVelX = 1e9;
    maxVelY = -1e9;
    minVelY = 1e9;
    maxVel = -1e9;
    minVel = 1e9;
    lifetime = 0;
}

void Body::setCoordinates(const qreal _x, const qreal _y)
{
    x = _x;
    y = _y;
}

void Body::setVelocity(const qreal _velX, const qreal _velY)
{
    velX = _velX;
    velY = _velY;
}

void Body::setMass(const qreal _mass)
{
    mass = _mass;
}

void Body::setName(const QString _name)
{
    name = _name;
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

QString Body::getName() const
{
    return name;
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

void Body::setSelected(const bool _isSelected)
{
    isSelected = _isSelected;
}

bool Body::getSelected() const
{
    return isSelected;
}

bool Body::contains(const qreal _x, const qreal _y)
{
    if(sqrt((x - _x) * (x - _x) + (y - _y) * (y - _y)) <= 5){
        return true;
    }
    return false;
}

void Body::updateStatistics(qreal time)
{
    if(x > maxX)
        maxX = x;
    if(x < minX)
        minX = x;
    if(y > maxY)
        maxY = y;
    if(y < minY)
        minY = y;
    if(velX > maxVelX)
        maxVelX = velX;
    if(velX < minVelX)
        minVelX = velX;
    if(velY > maxVelY)
        maxVelY = velY;
    if(velY < minVelY)
        minVelY = velY;
    qreal vel = sqrt(velX * velX + velY * velY);
    if(vel > maxVel)
        maxVel = vel;
    if(vel < minVel)
        minVel = vel;
    lifetime += time;
}

qreal Body::getMaxX() const
{
    return maxX;
}

qreal Body::getMinX() const
{
    return minX;
}

qreal Body::getMaxY() const
{
    return maxY;
}

qreal Body::getMinY() const
{
    return minY;
}

qreal Body::getMaxVelX() const
{
    return maxVelX;
}

qreal Body::getMinVelX() const
{
    return minVelX;
}

qreal Body::getMaxVelY() const
{
    return maxVelY;
}

qreal Body::getMinVelY() const
{
    return minVelY;
}

qreal Body::getMaxVel() const
{
    return maxVel;
}

qreal Body::getMinVel() const
{
    return minVel;
}

qreal Body::getLifetime() const
{
    return lifetime;
}
