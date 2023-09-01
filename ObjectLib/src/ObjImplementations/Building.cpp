#pragma once
#include <utility>
#include <ObjImplementations/Building.hpp>

Building::Building(std::string name, double x, double y) : Object(std::move(name), x, y) {
    _type = "Здание";
}

Building::Building() {
    _type = "Здание";
}
