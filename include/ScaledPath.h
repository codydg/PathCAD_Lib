#pragma once

#include "GenericPath.h"

class ScaledPath : public GenericPath
{
public:
    ScaledPath(PathId id, double totalTime);
    virtual ~ScaledPath() = default;

    virtual PathElement getStateAtTime(double time) const override;
    virtual double getTotalTime() const override;

private:
    const double totalTime;
};
