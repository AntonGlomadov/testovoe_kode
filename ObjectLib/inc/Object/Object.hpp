#pragma once

#include <string>
#include <unordered_map>

#include <Utils/Geo.hpp>

class Object {
public:
    Object();
    int Object::GetId() {
        return _id;
    }
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
    static std::unordered_map<std::wstring, int> type_counts;

private:
    std::wstring _name;
    Point _coordinates{};
    double _creationTime;
    int _id;
    static int _nextId;
};


