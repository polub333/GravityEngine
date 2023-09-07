#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include "scene.h"
#include "body.h"
#include "settings.h"

class Engine: public QObject
{
    Q_OBJECT
public:
    Engine();
    void setScene(Scene*);
    void addBody(qreal, qreal, qreal, qreal, qreal, QString);
    void drawAllBodies();
    void changeAllBodies();
    void setSettings(Settings);
    std::pair<qreal, qreal> computeForces(qreal, qreal);
    std::vector<Body*> bodies;

    void setForceField(const bool);
    bool getForceField() const;

private:
    Scene* scene;
    Settings settings;
    qreal inter;
    qreal maxVel;
    qreal maxX;
    std::pair<qreal, qreal> cursorPosition;

    bool forceField;
    void drawForces();
private slots:
    void changeCursorPosition(qreal, qreal);
    void mousePressed(qreal, qreal);
signals:
    void setSelectedBody(Body*);
};

#endif // ENGINE_H
