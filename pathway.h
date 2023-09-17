#ifndef PATHWAY_H
#define PATHWAY_H


#include <QtGlobal>

class Pathway
{
public:
    Pathway();
    Pathway(qreal x1, qreal y1, qreal x2, qreal y2);

    std::pair<qreal, qreal> getFirstCoordinates() const;
    std::pair<qreal, qreal> getSecondCoordinates() const;

    void setFirstCoordinates(qreal x, qreal y);
    void setSecondCoordinates(qreal x, qreal y);

private:
    qreal x1;
    qreal y1;
    qreal x2;
    qreal y2;
};

#endif // PATHWAY_H
