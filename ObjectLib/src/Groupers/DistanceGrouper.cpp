#include <Groupers/DistanceGrouper.hpp>
#include <algorithm>

std::map<double, std::vector<std::shared_ptr<Object>>>
DistanceGrouper::sortByDistance(const std::vector<std::shared_ptr<Object>> &data, Point from) {
    std::map<double, std::vector<std::shared_ptr<Object>>> distanceGroups;
    for (const auto& obj : data) {
        double distance = obj->distanceToObject(from);
        if (distance < 100.0) {
            distanceGroups[100.0].push_back(obj);
        } else if (distance < 1000.0) {
            distanceGroups[1000.0].push_back(obj);
        } else if (distance < 10000.0) {
            distanceGroups[10000.0].push_back(obj);
        } else {
            distanceGroups[std::numeric_limits<double>::max()].push_back(obj);
        }
    }
    for (auto& group : distanceGroups) {
        std::sort(group.second.begin(), group.second.end(), [&](const auto& a, const auto& b) {
            return a->distanceToObject(from) < b->distanceToObject(from);
        });
    }
    return distanceGroups;
}
