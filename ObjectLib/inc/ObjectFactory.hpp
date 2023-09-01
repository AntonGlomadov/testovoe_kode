﻿#pragma once

#include <memory>
#include <Object.hpp>
#include <ObjImplementations/Building.hpp>
#include <ObjImplementations/Car.hpp>
#include <ObjImplementations/Human.hpp>
#include <ObjImplementations/Tree.hpp>

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
};


