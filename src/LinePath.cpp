#include "LinePath.h"

#include <stdexcept>

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

LinePath::LinePath(PathElement start, PathElement end, double totalTime) : ScaledPath(PathId::LINE_PATH, totalTime),
        start(start), end(end) {}

PathElement LinePath::getStateAtPercentage(double percentage) const
{
    if (start.size() != end.size())
        throw std::length_error("Start and End of LinePath must be of equal length!");

    PathElement result;
    for (size_t i = 0; i < start.size(); i++)
    {
        result.push_back(std::make_shared<DataElement>(std::visit(overload{
            [percentage](std::string a, std::string b) -> DataElement { return percentage < 0.5 ? a : b; },
            [percentage](double a, double b) -> DataElement { return (b - a) * percentage + a; },
            [percentage](long a, long b) -> DataElement { return static_cast<long>((b - a) * percentage + a); },
            [percentage](bool a, bool b) -> DataElement { return percentage < 0.5 ? a : b; },
            [percentage](auto a, auto b) -> DataElement { throw std::logic_error("Start and End DataElement are of incompatible types."); }
        }, *start.at(i), *end.at(i))));
    }

    return result;
}
