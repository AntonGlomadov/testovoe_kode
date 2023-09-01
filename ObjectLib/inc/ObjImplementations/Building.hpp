#pragma once
#include <Object.hpp>

class Building : public Object{
public:
    Building();
    Building(std::string name, double x, double y);
};

