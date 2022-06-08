#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QDebug>

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    void drawSphere(qreal, qreal, qreal);
};

#endif // SCENE_H
