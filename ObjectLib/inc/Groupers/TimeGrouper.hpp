#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <Object/Object.hpp>

class TimeGrouper {
public:
    static std::map<std::wstring , std::vector<std::shared_ptr<Object>>> sortByCreationTyme(const std::unordered_map<int,std::shared_ptr<Object>>& data);
};


