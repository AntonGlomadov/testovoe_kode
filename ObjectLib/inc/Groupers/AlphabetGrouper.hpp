#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <set>

#include <Object/Object.hpp>
#include <Groupers/Grouper.hpp>


class AlphabetGrouper: public Grouper<std::set<std::wstring>> {
public:
    AlphabetGrouper(std::unordered_map<int, std::shared_ptr<Object>>& data);
    void Group() override;
    std::vector<int> GetObjectsInGroup(std::wstring groupName) override;
    std::vector<int> GetAllObject() override;
    void ObjectAddCall( int i, const std::shared_ptr<Object>& object) override;

private:
    void AddToGroupByName(int id, const std::wstring& name);

};


