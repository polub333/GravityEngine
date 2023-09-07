#include "settings.h"

Settings::Settings()
{

}

void Settings::setResolution(const qreal _resolution)
{
    resolution = _resolution;
}

void Settings::setTimeBoost(const qreal _timeBoost)
{
    timeBoost = _timeBoost;
}

void Settings::setFps(const qreal _fps)
{
    fps = _fps;
}

qreal Settings::getResolution() const
{
    return resolution;
}

qreal Settings::getTimeBoost() const
{
    return timeBoost;
}

qreal Settings::getFps() const
{
    return fps;
}
