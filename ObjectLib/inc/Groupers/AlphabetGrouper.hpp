#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <Object/Object.hpp>
#include <set>

struct NameComparator {
    bool operator()( const std::shared_ptr<Object>& obj1,  const std::shared_ptr<Object>& obj2) const {
        return obj1->GetName() < obj2->GetName();
    }
};

class AlphabetGrouper {
public:
    AlphabetGrouper();
    void sortByRuAlphabet(const std::unordered_map<int,std::shared_ptr<Object>>& data);
    void ObjectAddCall( const std::shared_ptr<Object>& object);
    std::vector<std::shared_ptr<Object>> GetGroupValueByKey(std::wstring val);
    std::set<wchar_t> getGroupsNames();
private:

    std::set<wchar_t> _gropsNames ;
    std::unordered_map<wchar_t , std::set<std::shared_ptr<Object>>> _groups ;
};


