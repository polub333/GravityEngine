#include "pathway.h"

Pathway::Pathway()
{

}

Pathway::Pathway(qreal _x1, qreal _y1, qreal _x2, qreal _y2)
{
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
}

std::pair<qreal, qreal> Pathway::getFirstCoordinates() const
{
    return std::pair<qreal, qreal>(x1, y1);
}

std::pair<qreal, qreal> Pathway::getSecondCoordinates() const
{
    return std::pair<qreal, qreal>(x2, y2);
}

void Pathway::setFirstCoordinates(qreal x, qreal y)
{
    x1 = x;
    y1 = y;
}

void Pathway::setSecondCoordinates(qreal x, qreal y)
{
    x2 = x;
    y2 = y;
}
