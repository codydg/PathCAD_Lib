#pragma once

#include "ScaledPath.h"

class LinePath : public ScaledPath
{
public:
    LinePath(PathElement start, PathElement end, double totalTime);

    virtual PathElement getStateAtPercentage(double percentage) const override;

private:
    PathElement start;
    PathElement end;
};