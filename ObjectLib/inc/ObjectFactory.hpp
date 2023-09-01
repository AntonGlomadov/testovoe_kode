#pragma once

#include <memory>
#include <Object.hpp>
#include <ObjImplementations/Building.hpp>
#include <ObjImplementations/Car.hpp>
#include <ObjImplementations/Human.hpp>
#include <ObjImplementations/Tree.hpp>

class ObjectFactory {
public:
    static std::shared_ptr<Object> createObject(const std::string& type) {
        if (type == "Здание") {
            return std::make_shared<Building>();
        } else if (type == "Машина") {
            return std::make_shared<Car>();
        } else if (type == "Человек") {
            return std::make_shared<Human>();
        } else if (type == "Дерево") {
            return std::make_shared<Tree>();
        } else {
            return nullptr;
        }
    }
};


