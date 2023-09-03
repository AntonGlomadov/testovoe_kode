#pragma once
#include <functional>
#include <Object/ObjectsController.hpp>
#include <filesystem>
#include "Groupers/AlphabetGrouper.hpp"
#include "Groupers/DistanceGrouper.hpp"
#include "Groupers/TimeGrouper.hpp"
#include "Groupers/TypeGrouper.hpp"

namespace fs = std::filesystem;


class AppController {
public:
    AppController();
    void Start();

private:
    void HelloMessage();
    void GetAnotherPath();
    void Init();
    void MainMenu();
    void ShowObjects();
    void AddObject();
    void Group();
    void GroupByDistance();
    void GroupByCreationTime();
    void GroupByType();
    void GroupByAlphabet();

    void Save();

private:
    unsigned long long _showWindowIndex = 0;
    std::unique_ptr<ObjectsController> _controller;
    std::unique_ptr<DistanceGrouper> _distanceGrouper;
    std::unique_ptr<TypeGrouper> _typeGrouper;
    std::unique_ptr<TimeGrouper> _timeGrouper;
    std::unique_ptr<AlphabetGrouper> _alphabetGrouper;
    fs::path _filePath = "./example.txt";
    bool _regroup = false;
    bool _isWorking;
    std::function<void(AppController *)> _jobCall;
};


