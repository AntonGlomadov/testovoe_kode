#pragma once
#include <Groupers/TimeGrouper.hpp>
#include <ctime>
#include <chrono>

std::map<std::wstring, std::vector<std::shared_ptr<Object>>>
TimeGrouper::sortByCreationTyme(const std::unordered_map<int,std::shared_ptr<Object>> &data) {
    std::map<std::wstring, std::vector<std::shared_ptr<Object>>> groupedObjects;
    for (const auto& obj : data) {
        auto now = std::chrono::system_clock::now();
        auto creationTime = std::chrono::system_clock::from_time_t(obj.second->GetCreationTime());
        auto hoursSinceCreation = std::chrono::duration_cast<std::chrono::hours>(now - creationTime).count();

        constexpr long long hoursPerDay = 24;
        auto daysSinceCreation = hoursSinceCreation / hoursPerDay;

        if (daysSinceCreation == 0) {
             groupedObjects[L"Сегодя"].push_back(obj.second);
        } else if (daysSinceCreation == 1) {
            groupedObjects[L"Вчера"].push_back(obj.second);
        } else if (daysSinceCreation <= 7) {
            groupedObjects[L"На этой неделе"].push_back(obj.second);
        } else if (daysSinceCreation <= 30) {
            groupedObjects[L"В этом месяце"].push_back(obj.second);
        } else if (daysSinceCreation <= 365) {
            groupedObjects[L"В этом году"].push_back(obj.second);
        } else {
            groupedObjects[L"Ранее"].push_back(obj.second);
        }
    }
    return groupedObjects;
}
