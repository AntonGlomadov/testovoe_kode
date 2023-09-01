#pragma once
#include <Object.hpp>

class Building : public Object{
public:
    Building();
    ~Building();
    Building(std::wstring name, double x, double y);
};

