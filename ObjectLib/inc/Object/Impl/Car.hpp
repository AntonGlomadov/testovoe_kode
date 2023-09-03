#pragma once

#include "Object/Object.hpp"

class Car : public Object{
public:
    Car();
    ~Car();
    Car(std::wstring name, double x, double y,double creationTime);
};




