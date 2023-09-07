#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QString>

#include <fstream>
#include <cmath>

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

    void importBodySystem(const QString path);
    void exportBodySystem(const QString path);
    void exportBodySystem();

private:
    Scene* scene;
    Settings settings;
    qreal inter;
    qreal maxVel;
    qreal maxX;
    std::pair<qreal, qreal> cursorPosition;

    bool forceField;
    void drawForces();
    void drawForceFields();
    void clearSystem();
private slots:
    void changeCursorPosition(qreal, qreal);
    void mousePressed(qreal, qreal);
signals:
    void setSelectedBody(Body*);
};

#endif // ENGINE_H
