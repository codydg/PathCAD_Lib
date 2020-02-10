#pragma once

#include <vector>
#include <variant>
#include <string>
#include <unordered_map>
#include <mutex>

enum class PathId {
    PATH_GROUP,
    LINE_PATH
};

class GenericPath
{
public:
    GenericPath(PathId id);
    virtual ~GenericPath() = default;

    using DataElement = std::variant<bool, long, double, std::string>;
    using PathElement = std::vector<DataElement>;

    virtual PathElement getStateAtTime(double time) const = 0;
    virtual PathElement getStateAtPercentage(double percentage) const = 0;
    virtual double getTotalTime() const = 0;
    std::string getName();
    PathId getId();

protected:
    std::string pathName;
private:
    PathId id;
    static std::mutex counterMutex;
    static std::unordered_map<PathId, uint64_t> idCounters;
    static const std::unordered_map<PathId, std::string> defaultPathNames;
};