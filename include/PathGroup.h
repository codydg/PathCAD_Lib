#pragma once

#include <memory>
#include <vector>

#include "GenericPath.h"

class PathGroup : public GenericPath
{
public:
    PathGroup();
    virtual ~PathGroup() = default;

    virtual PathElement getStateAtTime(double time) const override;
    virtual PathElement getStateAtPercentage(double percentage) const override;
    virtual double getTotalTime() const override;

    void addPath(std::shared_ptr<GenericPath> newPath);

private:
    std::vector<std::shared_ptr<GenericPath>> paths;
    double totalTime = 0.0;
};
