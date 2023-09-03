#pragma once

#include <functional>
#include <iostream>
#include "Reader/ReadWriteInterface.hpp"
#include "Groupers/AlphabetGrouper.hpp"



//singleton
class ObjectsController {
public:
    ObjectsController(std::unique_ptr<ReadWriteInterface> readWriteInterface);
    void Init();
    void AddObject(const std::shared_ptr<Object>& object);
    std::vector<std::shared_ptr<Object>> GetObjects(unsigned long long startIndex, unsigned long long endIndex);
    std::shared_ptr<Object> getObjectById(int id);
    void subscribeToModification(std::function<void(int id, const std::shared_ptr<Object>&)> callback);
    size_t GetNumberOfObject();
    void SaveObjects();
    void SaveObjectsInSpecifiedOrder(const std::vector<int>& order);
    std::unordered_map<int, std::shared_ptr<Object>>& GetObjects();

    ObjectsController(const ObjectsController&) = delete;
    ObjectsController& operator=(const ObjectsController&) = delete;



private:
    std::unique_ptr<ReadWriteInterface> _readWriteInterface;
    std::unordered_map<int,std::shared_ptr<Object>> _objects;
    std::vector<std::function<void(int id, const std::shared_ptr<Object>&)>> _callbacks;
};


