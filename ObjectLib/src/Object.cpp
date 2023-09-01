#pragma once
#include <Object.hpp>
#include <Utils/Time.hpp>
#include <utility>

Object::Object() {
    _creationTime = utils::getCurrentTimeInMillisecondsDouble();
}

Object::Object(std::string name, double x, double y): _name(std::move(name)), _coordinates({x, y}){
    _creationTime = utils::getCurrentTimeInMillisecondsDouble();

}

void Object::SetName(std::string name) {
    _name = std::move(name);
}

void Object::SetCoordinates(double x, double y) {
    _coordinates._x = x;
    _coordinates._y = y;
}

std::string Object::GetName() {
    return _name;
}

double Object::GetCreationTime() {
    return _creationTime;
}

Point Object::GetCoordinates() {
    return _coordinates;
}

std::string Object::GetType() {
    return _type;
}

std::string Object::toString() {
    return _name+" "+_coordinates.toString()+" "+_type+" "+std::to_string(_creationTime);
}

double Object::distanceToObject(const Point& point) {
    return distanceBetweenPoints(point,_coordinates);
}


