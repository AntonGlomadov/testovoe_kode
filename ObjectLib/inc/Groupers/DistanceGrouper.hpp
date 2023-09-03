#pragma once

#include <vector>
#include <map>
#include <memory>

#include <Object/Object.hpp>
#include <Groupers/Grouper.hpp>

class DistanceGrouper: public Grouper<std::vector<std::wstring>> {
public:
    DistanceGrouper(std::unordered_map<int, std::shared_ptr<Object>>& data);
    void Group() override;
    std::vector<int> GetObjectsInGroup(std::wstring groupName) override;
    std::vector<int> GetAllObject() override;
    void ObjectAddCall( int i, const std::shared_ptr<Object>& object) override;
    void SetPointFrom(Point pointFrom);
    Point GetPointFrom();
private:
    void AddToGroupByDistance(int id, double distance);
private:
    Point _pointFrom{0,0};
};


