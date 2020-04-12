#include "ScaledPath.h"

ScaledPath::ScaledPath(PathId id, double totalTime) : GenericPath(id), totalTime(totalTime) {}

PathElement ScaledPath::getStateAtTime(double time) const
{
    return getStateAtPercentage(time / getTotalTime());
}

double ScaledPath::getTotalTime() const
{
    return totalTime;
}
