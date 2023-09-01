#pragma once
#include <ObjImplementations/Human.hpp>
#include <utility>

Human::Human(std::string name, double x, double y) : Object(std::move(name), x, y) {
    _type = "Человек";
}

Human::Human() {
    _type = "Человек";
}
