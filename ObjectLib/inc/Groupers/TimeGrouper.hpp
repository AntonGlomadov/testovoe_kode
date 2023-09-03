#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <Object/Object.hpp>
#include <Groupers/Grouper.hpp>

class TimeGrouper: public Grouper<std::vector<std::wstring>> {
public:
    TimeGrouper(std::unordered_map<int, std::shared_ptr<Object>>& data);
    void Group() override;
    std::vector<int> GetObjectsInGroup(std::wstring groupName) override;
    std::vector<int> GetAllObject() override;
    void ObjectAddCall( int i, const std::shared_ptr<Object>& object) override;
private:
    void AddToGroupByTime(int id, double time);

};


