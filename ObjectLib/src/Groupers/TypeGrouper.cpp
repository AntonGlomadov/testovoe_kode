#include <Groupers/TypeGrouper.hpp>

TypeGrouper::TypeGrouper(std::unordered_map<int, std::shared_ptr<Object>> &data)
                                        : Grouper<std::set<std::wstring>>(data){
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

void TypeGrouper::Group() {
    _names.clear();
    _groups.clear();
    _names.insert(L"Разное");
    _groups[L"Разное"] = std::set<int, decltype(_compareFunc)>{_compareFunc};
    for (const auto &obj: _objects) {
        auto type = obj.second->GetType();
        auto typeNum = obj.second->GetNumberOfObjectWithSameType();
        AddToGroupByType(obj.first,type,typeNum);
    }
}

void TypeGrouper::AddToGroupByType(int id, const std::wstring& type, int typeNumber) {
    if (typeNumber>minNum){
        if(_groups.find(type) == _groups.end()) {
            _groups[type] = std::set<int, decltype(_compareFunc)>{_compareFunc};
            _names.insert(type);
        }
        _groups[type].insert(id);
    } else{
        _groups[L"Разное"].insert(id);
    }
}

void TypeGrouper::ObjectAddCall(int i, const std::shared_ptr<Object> &object) {
    auto type = object->GetType();
    auto typeNum = object->GetNumberOfObjectWithSameType();
    AddToGroupByType(i,type,typeNum);
}

std::vector<int> TypeGrouper::GetObjectsInGroup(std::wstring groupName) {
    std::vector<int> result;
    auto groupObjects = _groups[groupName];
    for(auto& id: groupObjects){
        result.emplace_back(id);
    }
    return result;
}

std::vector<int> TypeGrouper::GetAllObject() {
    std::vector<int> result;
    for(auto& groupName:_names){
        auto groupObjects = _groups[groupName];
        for(auto& id: groupObjects){
            result.emplace_back(id);
        }
    }
    return result;
}

int TypeGrouper::GetMinNumberForType() {
    return minNum;
}

void TypeGrouper::SetMinNumberForType(int num) {
    minNum = num;
}



