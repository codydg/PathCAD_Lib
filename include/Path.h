#pragma once

#include <vector>
#include <variant>
#include <string>

class Path
{
public:
    using DataElement = std::variant<bool, long, double, std::string>;
    using PathElement = std::vector<DataElement>;

    PathElement getStateAtTime(double time) const;
    virtual PathElement getStateAtPercentage(double percentage) const = 0;
    double getTotalTime() const;

protected:
    Path(double totalTime);

private:
    double totalTime;
};