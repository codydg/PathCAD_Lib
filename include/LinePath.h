#pragma once

#include "Path.h"

class LinePath : public Path
{
public:
    LinePath(PathElement start, PathElement end, double totalTime);

    virtual PathElement getStateAtPercentage(double percentage);

private:
    PathElement start;
    PathElement end;
};