#pragma once
#include <utility>
#include "Object/Impl/Building.hpp"

Building::Building(std::wstring name, double x, double y,double creationTime) : Object(std::move(name), x, y,creationTime) {
    if (type_counts.find(L"Здание") == type_counts.end()) {
        type_counts[L"Здание"] = 1;
    } else {
        type_counts[L"Здание"]++;
    }
    _type = L"Здание";

}

Building::Building() {
    if (type_counts.find(L"Здание") == type_counts.end()) {
        type_counts[L"Здание"] = 1;
    } else {
        type_counts[L"Здание"]++;
    }
    _type = L"Здание";
}

Building::~Building() {
        type_counts[L"Здание"]--;

}
