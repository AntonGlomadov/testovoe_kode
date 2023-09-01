#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <Object.hpp>

class AlphabetGrouper {
public:
    static std::map<wchar_t , std::vector<std::shared_ptr<Object>>> sortByRuAlphabet(const std::vector<std::shared_ptr<Object>>& data);
};


