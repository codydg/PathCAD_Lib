#pragma once

#include <vector>
#include <variant>
#include <string>

class GenericPath
{
public:
    GenericPath() {}
    virtual ~GenericPath() {}

    using DataElement = std::variant<bool, long, double, std::string>;
    using PathElement = std::vector<DataElement>;

    virtual PathElement getStateAtTime(double time) const = 0;
    virtual PathElement getStateAtPercentage(double percentage) const = 0;
    virtual double getTotalTime() const = 0;
};