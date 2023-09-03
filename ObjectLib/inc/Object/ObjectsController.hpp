#pragma once

#include <functional>
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
    void subscribeToModification(std::function<void(const std::shared_ptr<Object>&)> callback);
    size_t GetNumberOfObject();
    void SaveObjects();

    ObjectsController(const ObjectsController&) = delete;
    ObjectsController& operator=(const ObjectsController&) = delete;

    void sorByAlphabetGrouper();
    std::set<wchar_t> getAlphabetGroupsNames();


private:
    std::shared_ptr<AlphabetGrouper> _alphabetGrouper;
    std::unique_ptr<ReadWriteInterface> _readWriteInterface;
    std::unordered_map<int,std::shared_ptr<Object>> _objects;
    std::vector<std::function<void(const std::shared_ptr<Object>&)>> _callbacks;
};


