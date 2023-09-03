#pragma once
#include "Object/Object.hpp"
#include "Utils/Time.hpp"
#include <utility>

std::unordered_map<std::wstring, int> Object::type_counts;
int Object::_nextId = 0;

Object::Object() {
    _id =_nextId++;
    _creationTime = utils::getCurrentTimeInMillisecondsDouble();
}

Object::Object(std::wstring name, double x, double y): _name(std::move(name)), _coordinates({x, y}){
    _id =_nextId++;
    _creationTime = utils::getCurrentTimeInMillisecondsDouble();
}

void Object::SetName(std::wstring name) {
    _name = std::move(name);
}

void Object::SetCoordinates(double x, double y) {
    _coordinates._x = x;
    _coordinates._y = y;
}

std::wstring Object::GetName() {
    return _name;
}

double Object::GetCreationTime() {
    return _creationTime;
}

Point Object::GetCoordinates() {
    return _coordinates;
}

std::wstring Object::GetType() {
    return _type;
}

std::wstring Object::toString() {
    return _name+L" "+_coordinates.toString()+L" "+_type+L" "+std::to_wstring(_creationTime);
}

double Object::distanceToObject(const Point& point) {
    return distanceBetweenPoints(point,_coordinates);
}

int Object::GetNumberOfObjectWithSameType() {
    if (type_counts.find(_type) != type_counts.end()) {
        return type_counts[_type];
    }
    return 0;
}


