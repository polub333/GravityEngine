#ifndef BODY_H
#define BODY_H

#include<QtGlobal>

#include<utility>

class Body
{
public:
    Body();
    void setCoordinates(const qreal, const qreal);
    void setVelocity(const qreal, const qreal);
    void setMass(const qreal);

    std::pair<qreal, qreal> getCoordinates() const;
    std::pair<qreal, qreal> getVelocity() const;
    qreal getMass() const;

    void changeCoordinatesDueVelocity(const qreal);
    void changeVelocityDueForce(const qreal, const qreal, const qreal);
private:
    qreal x;
    qreal y;
    qreal velX;
    qreal velY;
    qreal mass;
};

#endif // BODY_H
