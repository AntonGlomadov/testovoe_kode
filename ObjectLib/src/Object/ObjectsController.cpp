#pragma once
#include <Object/ObjectsController.hpp>


ObjectsController::ObjectsController(std::unique_ptr <ReadWriteInterface> readWriteInterface) {
    _readWriteInterface = std::move(readWriteInterface);
}

void ObjectsController::Init() {
    _objects = _readWriteInterface->GetObjects();
}

void ObjectsController::SaveObjects() {
    _readWriteInterface->SaveObjects(_objects);
}

void ObjectsController::AddObject(const std::shared_ptr<Object>& object) {
    _objects.insert(std::make_pair(object->GetId(), object));
}

std::vector<std::shared_ptr<Object>> ObjectsController::GetObjects(unsigned long long startIndex, unsigned long long endIndex) {
    std::vector<std::shared_ptr<Object>> result;
    if (startIndex >= 0 && endIndex <=_objects.size()) {
        auto start = std::next(_objects.begin(), startIndex);
        auto end = std::next(_objects.begin(), endIndex);
        for (auto it = start; it != end; ++it) {
            result.push_back(it->second);
        }
    }
    return result;
}

std::shared_ptr<Object> ObjectsController::getObjectById(int id) {
    auto it = _objects.find(id);
    if (it != _objects.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

size_t ObjectsController::GetNumberOfObject() {
    return _objects.size();
}

void ObjectsController::subscribeToModification(std::function<void(const std::shared_ptr<Object> &)> callback) {
    _callbacks.push_back(callback);
}

void ObjectsController::sorByAlphabetGrouper() {
    if (_alphabetGrouper == nullptr) {
        _alphabetGrouper = std::make_shared<AlphabetGrouper>();
        _alphabetGrouper->sortByRuAlphabet(_objects);
        this->subscribeToModification([this](const std::shared_ptr<Object> &obj) {
            _alphabetGrouper->ObjectAddCall(obj);
        });
    }
}

std::set<wchar_t> ObjectsController::getAlphabetGroupsNames() {
    return _alphabetGrouper->getGroupsNames();
}



