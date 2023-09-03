#pragma once

#include "Object/Object.hpp"
#include <vector>
#include <memory>

class ReadWriteInterface{
public:
    virtual ~ReadWriteInterface() = default; // Виртуальный деструктор
    virtual std::unordered_map<int,std::shared_ptr<Object>> GetObjects() = 0;
    virtual void SaveObjects(const std::unordered_map<int,std::shared_ptr<Object>>& objects) = 0;
    virtual void AppendObjects(const std::unordered_map<int,std::shared_ptr<Object>>& objects) = 0;
    virtual void SaveInSpecifiedOrder(const std::unordered_map<int,std::shared_ptr<Object>>& objects,const std::vector<int>& order) = 0;

};