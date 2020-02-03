#include "PathGroup.h"

PathGroup::PathGroup() {}

GenericPath::PathElement PathGroup::getStateAtTime(double time) const
{
    for (const auto& path : paths)
    {
        double pathTime = path->getTotalTime();
        if (time <= pathTime)
            return path->getStateAtTime(time);
        else
            time -= pathTime;
    }
    // If asked for a time after the Path has ended, return the last known item.
    return paths.back()->getStateAtPercentage(1.0);
}

GenericPath::PathElement PathGroup::getStateAtPercentage(double percentage) const
{
    return getStateAtTime(percentage * totalTime);
}

void PathGroup::addPath(std::shared_ptr<GenericPath> newPath)
{
    paths.push_back(newPath);
    totalTime += newPath->getTotalTime();
}
