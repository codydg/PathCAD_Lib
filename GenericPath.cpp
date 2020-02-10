#include "GenericPath.h"

std::mutex GenericPath::counterMutex;
std::unordered_map<PathId, uint64_t> GenericPath::idCounters;
const std::unordered_map<PathId, std::string> GenericPath::defaultPathNames
{
    { PathId::PATH_GROUP, "Path Group" },
    { PathId::LINE_PATH, "Line Path" }
};

GenericPath::GenericPath(PathId id) : id(id)
{
    std::lock_guard<decltype(counterMutex)> counterLock(counterMutex);
    pathName = defaultPathNames.at(id) + " " + std::to_string(++idCounters[id]);
}

std::string GenericPath::getName() const
{
    return pathName;
}

void GenericPath::setName(std::string name)
{
    pathName = name;
}

PathId GenericPath::getId() const
{
    return id;
}