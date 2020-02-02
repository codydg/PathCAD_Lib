#include "Path.h"

Path::Path(double totalTime) : totalTime(totalTime) {}

Path::PathElement Path::getStateAtTime(double time) const
{
    return getStateAtPercentage(time / getTotalTime());
}

double Path::getTotalTime() const
{
    return totalTime;
}
