#ifndef ENGINE_H
#define ENGINE_H

#include "scene.h"
#include "body.h"

class Engine
{
public:
    Engine();
    void setScene(Scene*);
    void addBody(qreal, qreal, qreal, qreal, qreal);
    void drawAllBodies();
    void changeAllBodies();
    void setInter(qreal);
    std::pair<qreal, qreal> computeForces(qreal, qreal);
private:
    Scene* scene;
    std::vector<Body*> bodies;
    qreal inter;
    qreal maxVel;
    qreal maxX;
};

#endif // ENGINE_H
