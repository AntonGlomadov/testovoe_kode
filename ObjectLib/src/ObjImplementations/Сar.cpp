
#include <ObjImplementations/Car.hpp>
#include <utility>

Car::Car(std::string name, double x, double y) : Object(std::move(name), x, y) {
    _type = "Машина";
}
Car::Car():Object() {
    _type = "Машина";
}