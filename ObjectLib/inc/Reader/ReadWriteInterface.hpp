#pragma once

#include <Object.hpp>
#include <vector>
#include <memory>

class ReadWriteInterface{
public:
    virtual ~ReadWriteInterface() = default; // Виртуальный деструктор
    virtual std::vector<std::shared_ptr<Object>> GetObjects() = 0;
    virtual void SaveObjects(const std::vector<std::shared_ptr<Object>>& objects) = 0;
    virtual void AppendObjects(const std::vector<std::shared_ptr<Object>>& objects) = 0;
};