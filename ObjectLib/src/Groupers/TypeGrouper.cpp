//
// Created by Glomadov on 01.09.2023.
//
#include "Groupers/TypeGrouper.hpp"

std::map<std::wstring, std::vector<std::shared_ptr<Object>>>
TypeGrouper::sortByTypeNumber(const std::unordered_map<int,std::shared_ptr<Object>> &data, unsigned int n) {
    std::map<std::wstring, std::vector<std::shared_ptr<Object>>> groupedObjects;
    for (const auto& obj : data) {
        if (obj.second->GetNumberOfObjectWithSameType() >= n){
            groupedObjects[obj.second->GetType()].push_back(obj.second);
        } else{
            groupedObjects[L"Разное"].push_back(obj.second);
        }
    }
    return groupedObjects;
}

