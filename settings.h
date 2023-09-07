#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtGlobal>

class Settings
{
public:
    Settings();

    void setResolution(const qreal);
    void setTimeBoost(const qreal);
    void setFps(const qreal);

    qreal getResolution() const;
    qreal getTimeBoost() const;
    qreal getFps() const;
private:
    qreal resolution;
    qreal timeBoost;
    qreal fps;
};

#endif // SETTINGS_H
