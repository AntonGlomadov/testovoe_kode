﻿#pragma once
#include <Object.hpp>

class Human : public Object{
public:
    Human();
    ~Human();
    Human(std::wstring name, double x, double y);
};


