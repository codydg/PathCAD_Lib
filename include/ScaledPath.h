#pragma once

#include "GenericPath.h"

class ScaledPath : public GenericPath
{
public:
    ScaledPath(double totalTime);

    virtual PathElement getStateAtTime(double time) const override;
    virtual double getTotalTime() const override;

private:
    const double totalTime;
};
