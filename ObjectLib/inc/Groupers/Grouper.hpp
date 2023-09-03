#pragma once

#include <functional>
#include <set>
#include "Object/Object.hpp"

template <typename T>
class Grouper {
public:
    Grouper(std::unordered_map<int, std::shared_ptr<Object>> &objects) : _objects(objects) {}
    virtual void Group() = 0;
    virtual std::vector<int> GetObjectsInGroup(std::wstring groupName) = 0;
    virtual void ObjectAddCall( int i, const std::shared_ptr<Object>& object) = 0;
    virtual std::vector<int> GetAllObject() = 0;
    T GetNames() {
        return _names;
    };

protected:
    T _names;
    std::function<bool(int, int)> _compareFunc;
    std::unordered_map<int, std::shared_ptr<Object>>& _objects;
    std::unordered_map<std::wstring ,std::set<int, decltype(_compareFunc)>> _groups ;
};








