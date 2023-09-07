#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPainter>

#include "directions.h"

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    void drawSphere(qreal, qreal, qreal);
    void drawSelected(qreal, qreal, qreal);

    void drawArrow(qreal, qreal, direction);
    void drawCrosshair(qreal, qreal);
    void drawLine(qreal, qreal, qreal, qreal);

    void setSceneSize(qreal, qreal);
private:
    QPainter* painter;
    qreal width;
    qreal height;
private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
signals:
    void changeCursorPosition(qreal, qreal);
    void mousePressed(qreal, qreal);
};

#endif // SCENE_H
