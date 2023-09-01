#pragma once
#include <string>
#include <Utils/Geo.hpp>

class Object {
public:
    Object();
    Object(std::string name, double x, double y);
    void SetName(std::string name);
    void SetCoordinates(double x, double y);
    std::string GetName();
    double GetCreationTime();
    Point GetCoordinates();
    std::string GetType();
    std::string toString();
    double distanceToObject(const Point& point);


protected:
    std::string _type;

private:
    std::string _name;
    Point _coordinates{};
    double _creationTime;
};


