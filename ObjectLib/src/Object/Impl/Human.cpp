#pragma once
#include "Object/Impl/Human.hpp"
#include <utility>

Human::Human(std::wstring name, double x, double y) : Object(std::move(name), x, y) {
    if (type_counts.find(L"Человек") == type_counts.end()) {
        type_counts[L"Человек"] = 1;
    } else {
        type_counts[L"Человек"]++;
    }
    _type = L"Человек";
}

Human::Human() {
    if (type_counts.find(L"Человек") == type_counts.end()) {
        type_counts[L"Человек"] = 1;
    } else {
        type_counts[L"Человек"]++;
    }
    _type = L"Человек";
}

Human::~Human() {
    type_counts[L"Человек"]--;
}
