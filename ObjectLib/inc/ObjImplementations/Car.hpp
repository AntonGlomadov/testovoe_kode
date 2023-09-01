#pragma once

#include <Object.hpp>

class Car : public Object{
public:
    Car();
    ~Car();
    Car(std::wstring name, double x, double y);
};




