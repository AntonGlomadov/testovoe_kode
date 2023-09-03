#pragma once

#include <memory>

#include <Object/Object.hpp>
#include "Object/Impl/Building.hpp"
#include "Object/Impl/Car.hpp"
#include "Object/Impl/Human.hpp"
#include "Object/Impl/Tree.hpp"

class ObjectFactory {
public:
    static std::shared_ptr<Object> createObject(const std::wstring& type) {
        if (type == L"Здание") {
            return std::make_shared<Building>();
        } else if (type == L"Машина") {
            return std::make_shared<Car>();
        } else if (type == L"Человек") {
            return std::make_shared<Human>();
        } else if (type == L"Дерево") {
            return std::make_shared<Tree>();
        } else {
            return nullptr;
        }
    }
    static std::shared_ptr<Object> createObject(const std::wstring& type,std::wstring name, double x, double y,double creationTime) {
        if (type == L"Здание") {
            return std::make_shared<Building> (name,x,y,creationTime);
        } else if (type == L"Машина") {
            return std::make_shared<Car> (name,x,y,creationTime);
        } else if (type == L"Человек") {
            return std::make_shared<Human> (name,x,y,creationTime);
        } else if (type == L"Дерево") {
            return std::make_shared<Tree> (name,x,y,creationTime);
        } else {
            return nullptr;
        }
    }
};


