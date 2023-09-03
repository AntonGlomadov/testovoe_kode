#pragma once
#include <Groupers/TimeGrouper.hpp>
#include <chrono>


TimeGrouper::TimeGrouper(std::unordered_map<int, std::shared_ptr<Object>> &data)
                                                : Grouper<std::vector<std::wstring>>(data) {
    _names.emplace_back(L"Сегодня");
    _names.emplace_back(L"Вчера");
    _names.emplace_back(L"На этой недели");
    _names.emplace_back(L"В этом месяце");
    _names.emplace_back(L"В этом году");
    _names.emplace_back(L"Ранее");
    _compareFunc = [this](int a, int b) -> bool {
        auto creationTime1 = _objects[a]->GetCreationTime();
        auto creationTime2 = _objects[b]->GetCreationTime();
        if (creationTime1 < creationTime2) {
            return true;
        } else if (creationTime1 > creationTime2) {
            return false;
        } else {
            return a < b;
        }
    };
    for(auto& name:_names){
        _groups[name] = std::set<int, decltype(_compareFunc)> {_compareFunc};
    }
}

void TimeGrouper::Group() {
    for (const auto &obj: _objects) {
        double time = obj.second->GetCreationTime();
        AddToGroupByTime(obj.first,time);
    }
}

std::vector<int> TimeGrouper::GetObjectsInGroup(std::wstring groupName) {
    std::vector<int> result;
    auto groupObjects = _groups[groupName];
    for(auto& id: groupObjects){
        result.emplace_back(id);
    }
    return result;
}

std::vector<int> TimeGrouper::GetAllObject() {
    std::vector<int> result;
    for(auto& groupName:_names){
        auto groupObjects = _groups[groupName];
        for(auto& id: groupObjects){
            result.emplace_back(id);
        }
    }
    return result;
}

void TimeGrouper::ObjectAddCall(int i, const std::shared_ptr<Object> &object) {
    double time = object->GetCreationTime();
    AddToGroupByTime(i,time);
}

void TimeGrouper::AddToGroupByTime(int id, double time) {
    auto now = std::chrono::system_clock::now();
    auto creationTime = std::chrono::system_clock::from_time_t(static_cast<__time64_t>(time));
    auto hoursSinceCreation = std::chrono::duration_cast<std::chrono::hours>(now - creationTime).count();
    constexpr long long hoursPerDay = 24;
    auto daysSinceCreation = hoursSinceCreation / hoursPerDay;
    if (daysSinceCreation == 0) {
        _groups[_names[0]].insert(id);
    } else if (daysSinceCreation == 1) {
        _groups[_names[1]].insert(id);
    } else if (daysSinceCreation <= 7) {
        _groups[_names[2]].insert(id);
    } else if (daysSinceCreation <= 30) {
        _groups[_names[3]].insert(id);
    } else if (daysSinceCreation <= 365) {
        _groups[_names[4]].insert(id);
    } else {
        _groups[_names[5]].insert(id);
    }
}



