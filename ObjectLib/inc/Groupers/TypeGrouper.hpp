#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <Object/Object.hpp>

class TypeGrouper {
public:
    static std::map<std::wstring , std::vector<std::shared_ptr<Object>>> sortByTypeNumber(const std::unordered_map<int,std::shared_ptr<Object>>& data, unsigned int n = 0);
};


