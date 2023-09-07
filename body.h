#ifndef BODY_H
#define BODY_H

#include <QtGlobal>
#include <QString>

#include<utility>

class Body
{
public:
    Body();
    void setCoordinates(const qreal, const qreal);
    void setVelocity(const qreal, const qreal);
    void setMass(const qreal);
    void setName(const QString);

    std::pair<qreal, qreal> getCoordinates() const;
    std::pair<qreal, qreal> getVelocity() const;
    qreal getMass() const;
    QString getName() const;

    void changeCoordinatesDueVelocity(const qreal);
    void changeVelocityDueForce(const qreal, const qreal, const qreal);

    void setSelected(const bool);
    bool getSelected() const;

    bool contains(const qreal, const qreal);
    void updateStatistics(qreal);

    qreal getMaxX() const;
    qreal getMinX() const;
    qreal getMaxY() const;
    qreal getMinY() const;
    qreal getMaxVelX() const;
    qreal getMinVelX() const;
    qreal getMaxVelY() const;
    qreal getMinVelY() const;
    qreal getMaxVel() const;
    qreal getMinVel() const;
    qreal getLifetime() const;
private:
    qreal x;
    qreal y;
    qreal velX;
    qreal velY;
    qreal mass;
    QString name;

    qreal maxX;
    qreal minX;
    qreal maxY;
    qreal minY;
    qreal maxVelX;
    qreal minVelX;
    qreal maxVelY;
    qreal minVelY;
    qreal maxVel;
    qreal minVel;
    qreal lifetime;

    bool isSelected;
};

#endif // BODY_H
