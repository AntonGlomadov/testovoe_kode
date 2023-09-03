#include <Groupers/DistanceGrouper.hpp>
#include <algorithm>
#include <iostream>

DistanceGrouper::DistanceGrouper(std::unordered_map<int, std::shared_ptr<Object>>& data)
                                : Grouper<std::vector<std::wstring>>(data) {
    _names.emplace_back(L"До 100 ед");
    _names.emplace_back(L"До 1000 ед");
    _names.emplace_back(L"До 10000 ед");
    _names.emplace_back(L"Слишком далеко");
    _compareFunc = [this](int a, int b) -> bool {
        auto dist1 = _objects[a]->distanceToObject(_pointFrom);
        auto dist2 = _objects[b]->distanceToObject(_pointFrom);
        if (dist1 < dist2) {
            return true;
        } else if (dist1 > dist2) {
            return false;
        } else {
            return a < b;
        }
    };

}

void DistanceGrouper::SetPointFrom(Point pointFrom) {
    _pointFrom = pointFrom;
}

Point DistanceGrouper::GetPointFrom() {
    return _pointFrom;
}

void DistanceGrouper::Group() {
    _groups.clear();
    for(auto& name:_names){
        _groups[name] = std::set<int, decltype(_compareFunc)> {_compareFunc};
    }
    for (const auto &obj: _objects) {
        double distance = obj.second->distanceToObject(_pointFrom);
        AddToGroupByDistance(obj.first,distance);
    }
}

std::vector<int> DistanceGrouper::GetObjectsInGroup(std::wstring groupName) {
    std::vector<int> result;
    auto groupselem = _groups[groupName];
    for(auto& id: groupselem){
        result.emplace_back(id);
    }
    return result;
}

std::vector<int> DistanceGrouper::GetAllObject() {
    std::vector<int> result;
    for(auto& groupName:_names){
        auto groupObjects = _groups[groupName];
        for(auto& id: groupObjects){
            result.emplace_back(id);
        }
    }
    return result;
}

void DistanceGrouper::ObjectAddCall(int i, const std::shared_ptr<Object> &object) {
    double distance = object->distanceToObject(_pointFrom);
    AddToGroupByDistance(i,distance);
}

void DistanceGrouper::AddToGroupByDistance(int id, double distance) {
    if (distance < 100.0) {
        _groups[_names[0]].insert(id);
    } else if (distance < 1000.0) {
        _groups[_names[1]].insert(id);
    } else if (distance < 10000.0) {
        _groups[_names[2]].insert(id);
    } else {
        _groups[_names[3]].insert(id);
    }
}

