#pragma once

#include <vector>
#include <map>
#include <memory>

#include <Object/Object.hpp>

class DistanceGrouper {
public:
    static std::map<double, std::vector<std::shared_ptr<Object>>> sortByDistance(const std::vector<std::shared_ptr<Object>>& data, Point from);
};


