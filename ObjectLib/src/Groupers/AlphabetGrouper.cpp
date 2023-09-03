#include <cwctype>
#include <algorithm>
#include <Groupers/AlphabetGrouper.hpp>

AlphabetGrouper::AlphabetGrouper() {
    _groups = std::unordered_map<wchar_t, std::set<std::shared_ptr<Object>>>();
    _gropsNames = std::set<wchar_t>();
}

void
AlphabetGrouper::sortByRuAlphabet(const std::unordered_map<int,std::shared_ptr<Object>> &data) {
    for (const auto& obj : data) {
        auto  name = obj.second->GetName();
        auto firstLetter = name[0];
        if ((firstLetter >= L'А' && firstLetter <= L'я') ||
            (firstLetter >= L'А' && firstLetter <= L'Я') ||
            (firstLetter == L'Ё'|| firstLetter == L'ё')){ // ёЁ по какой-то пречине не входит в алфавит
            firstLetter = std::towupper(firstLetter);
        } else{
            firstLetter = '#';
        }
        _groups[firstLetter].insert(obj.second);
        _gropsNames.insert(firstLetter);
    }
}

std::set<wchar_t> AlphabetGrouper::getGroupsNames() {
    return _gropsNames;
}

void AlphabetGrouper::ObjectAddCall(const std::shared_ptr<Object> &object) {
    auto  name = object->GetName();
    auto firstLetter = name[0];
    if ((firstLetter >= L'А' && firstLetter <= L'я') ||
        (firstLetter >= L'А' && firstLetter <= L'Я') ||
        (firstLetter == L'Ё'|| firstLetter == L'ё')){ // ёЁ по какой-то пречине не входит в алфавит
        firstLetter = std::towupper(firstLetter);
    } else {
        firstLetter = '#';
    }
    _groups[firstLetter].insert(object);
    _gropsNames.insert(firstLetter);
}

std::vector<std::shared_ptr<Object>> AlphabetGrouper::GetGroupValueByKey(wchar_t val) {
    std::vector<std::shared_ptr<Object>> group;
    auto it = _groups.find(val);
    if (it != _groups.end()){
        auto set = it->second;
        for(auto& data:set){
            group.emplace_back(data);
        }
    }
    return group;
}



