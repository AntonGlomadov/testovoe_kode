#pragma once
#include <Object.hpp>

class Tree : public Object{
public:
    Tree();
    ~Tree();
    Tree(std::wstring name, double x, double y);
};
