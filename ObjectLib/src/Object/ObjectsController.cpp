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
    for (const auto& callback : _callbacks) {
        callback(object->GetId(), object);
    }
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

void ObjectsController::subscribeToModification(std::function<void(int id, const std::shared_ptr<Object> &)> callback) {
    _callbacks.push_back(callback);
}

std::unordered_map<int, std::shared_ptr<Object>> &ObjectsController::GetObjects() {
    return _objects;
}

void ObjectsController::SaveObjectsInSpecifiedOrder(const std::vector<int> &order) {
    _readWriteInterface->SaveInSpecifiedOrder(_objects,order);
}






