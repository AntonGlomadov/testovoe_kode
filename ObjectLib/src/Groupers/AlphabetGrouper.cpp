#pragma once
#include <cwctype>
#include <algorithm>
#include <Groupers/AlphabetGrouper.hpp>

AlphabetGrouper::AlphabetGrouper(std::unordered_map<int, std::shared_ptr<Object>> &data)
                                                            : Grouper<std::set<std::wstring>>(data) {
    _compareFunc = [this](int a, int b) -> bool {
        auto name1 = _objects[a]->GetName();
        auto name2 = _objects[b]->GetName();
        if (name1 < name2) {
            return true;
        } else if (name1 > name2) {
            return false;
        } else {
            return a < b;
        }
    };
}

void AlphabetGrouper::Group() {
    _names.clear();
    _groups.clear();
    _names.insert(L"#");
    for (const auto &obj: _objects) {
        auto name = obj.second->GetName();
        AddToGroupByName(obj.first,name);
    }

}

void AlphabetGrouper::AddToGroupByName(int id, const std::wstring &name) {
    auto firstLetter = name[0];
    if ((firstLetter >= L'А' && firstLetter <= L'я') ||
        (firstLetter >= L'А' && firstLetter <= L'Я') ||
        (firstLetter == L'Ё' || firstLetter == L'ё')) { // ёЁ по какой-то пречине не входит в алфавит
        firstLetter = std::towupper(firstLetter);
    } else {
        firstLetter = '#';
    }
    std::wstring letterToString (1,firstLetter);
    if(_groups.find(letterToString) == _groups.end()) {
        _groups[letterToString] = std::set<int, decltype(_compareFunc)>{_compareFunc};
        _names.insert(letterToString);
    }
    _groups[letterToString].insert(id);
}

std::vector<int> AlphabetGrouper::GetObjectsInGroup(std::wstring groupName) {
    std::vector<int> result;
    auto groupObjects = _groups[groupName];
    for(auto& id: groupObjects){
        result.emplace_back(id);
    }
    return result;}

std::vector<int> AlphabetGrouper::GetAllObject() {
    std::vector<int> result;
    for(auto& groupName:_names){
        auto groupObjects = _groups[groupName];
        for(auto& id: groupObjects){
            result.emplace_back(id);
        }
    }
    return result;
}

void AlphabetGrouper::ObjectAddCall(int i, const std::shared_ptr<Object> &object) {
    auto name = object->GetName();
    AddToGroupByName(i,name);
}





