#pragma once
#include <functional>
#include <Object/ObjectsController.hpp>
#include <filesystem>
#include "Groupers/AlphabetGrouper.hpp"

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
    void GroupByAlphabet();
    void Save();

private:
    unsigned long long _showWindowIndex = 0;
    std::unique_ptr<ObjectsController> _controller;
    fs::path _filePath = "./example.txt";
    bool _isWorking;
    std::function<void(AppController *)> _jobCall;
};


