#pragma once
#include <string>
#include <Utils/Geo.hpp>
#include <map>

class Object {
public:
    Object();
    Object(std::wstring name, double x, double y);
    void SetName(std::wstring name);
    void SetCoordinates(double x, double y);
    std::wstring GetName();
    double GetCreationTime();
    Point GetCoordinates();
    std::wstring GetType();
    int GetNumberOfObjectWithSameType();
    std::wstring toString();
    double distanceToObject(const Point& point);


protected:
    std::wstring _type;
    static std::map<std::wstring, int> type_counts;

private:
    std::wstring _name;
    Point _coordinates{};
    double _creationTime;
};


