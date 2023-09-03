
#include "Object/Impl/Car.hpp"
#include <utility>

Car::Car(std::wstring name, double x, double y,double creationTime) : Object(std::move(name), x, y, creationTime) {
    if (type_counts.find(L"Машина") == type_counts.end()) {
        type_counts[L"Машина"] = 1;
    } else {
        type_counts[L"Машина"]++;
    }
    _type = L"Машина";
}
Car::Car():Object() {
    if (type_counts.find(L"Машина") == type_counts.end()) {
        type_counts[L"Машина"] = 1;
    } else {
        type_counts[L"Машина"]++;
    }
    _type = L"Машина";
}

Car::~Car() {
    type_counts[L"Машина"]--;
}
