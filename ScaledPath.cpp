#include "ScaledPath.h"

ScaledPath::ScaledPath(PathId id, double totalTime) : GenericPath(id), totalTime(totalTime) {}

GenericPath::PathElement ScaledPath::getStateAtTime(double time) const
{
    return getStateAtPercentage(time / getTotalTime());
}

double ScaledPath::getTotalTime() const
{
    return totalTime;
}
