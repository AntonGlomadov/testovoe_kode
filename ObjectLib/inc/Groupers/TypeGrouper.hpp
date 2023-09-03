#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <Object/Object.hpp>
#include <Groupers/Grouper.hpp>

class TypeGrouper: public Grouper<std::set<std::wstring>> {
public:
    TypeGrouper(std::unordered_map<int, std::shared_ptr<Object>>& data);
    void Group() override;
    std::vector<int> GetObjectsInGroup(std::wstring groupName) override;
    std::vector<int> GetAllObject() override;
    void ObjectAddCall( int i, const std::shared_ptr<Object>& object) override;
    int GetMinNumberForType();
    void SetMinNumberForType(int num);

private:
    void AddToGroupByType(int id, const std::wstring& type, int typeNumber);
    int minNum = 0;
};


