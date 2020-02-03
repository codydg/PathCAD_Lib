#include "ScaledPath.h"

ScaledPath::ScaledPath(double totalTime) : totalTime(totalTime) {}

GenericPath::PathElement ScaledPath::getStateAtTime(double time) const
{
    return getStateAtPercentage(time / getTotalTime());
}

double ScaledPath::getTotalTime() const
{
    return totalTime;
}
