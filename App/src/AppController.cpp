#pragma once
#include <AppController.hpp>
#include <iostream>
#include <thread>
#include <sstream>
#include <Reader/Implementations/FileReader.hpp>
#include <Object/Impl/Car.hpp>
#include <Object/Impl/Building.hpp>
#include <Object/Impl/Human.hpp>
#include <Object/Impl/Tree.hpp>

AppController::AppController() {
    _isWorking = true;
    _jobCall = &AppController::HelloMessage;
}

void AppController::Start() {
    while (_isWorking){
        system("cls");
        _jobCall(this);
    }
}

void AppController::HelloMessage() {
    std::wcout<<L"Это консольное приложение для тестового задания."<<std::endl
              <<L"По умолчанию программа работает с файлом example.txt - который по умолчанию располагается рядом с программой"<<std::endl
            <<L"Если хотите выйти - 0"<<std::endl
            <<L"Если хотите продолжить работать со стандартным файлом введите - 1"<<std::endl
            <<L"Если хотите выбрать свой файл введите - 2"<<std::endl
              <<L"!!! УЧТИТЕ ЧТО СТРУКТУРА ФАЙЛА ДОЛЖНА СООТВЕТСТВОВАТЬ СТУКТУРЕ ПРИМЕРА !!! "<<std::endl;
    int choice;
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;
    if (choice == 0){
        _isWorking = false;
    }
    else if (choice == 2) {
        _jobCall = &AppController::GetAnotherPath;
    } else if (choice == 1){
        _jobCall = &AppController::Init;
    } else{
        std::wcout<<L"Не верный ввод"<<std::endl<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void AppController::GetAnotherPath() {
    std::wcout<<L"Введите путь до файла:"<<std::endl;
    std::wstring strFilePath;
    std::wcin.ignore();
    std::getline(std::wcin, strFilePath);
    fs::path filePath = strFilePath;
    if(fs::exists(filePath)){
        _filePath = filePath;
        _jobCall = &AppController::Init;
    } else{
        std::wcout<<L"Файл по заданному пути: "<< strFilePath <<L" - отсутствует"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        _jobCall = &AppController::HelloMessage;
    }
}

void AppController::Init() {
    _controller = std::make_unique<ObjectsController>(std::make_unique<FileReader>(_filePath));
    _controller->Init();
    _jobCall = &AppController::MainMenu;

}

void AppController::MainMenu() {
    std::wcout<<L"Основное меню"<<std::endl<<std::endl
            <<L"Ниже перечисленны функции данного приложения."<<std::endl<<L"Для выполнения нужной вам функции введите соответствующую цифру в консоль"<<std::endl<<std::endl
            <<L"Функции"<<std::endl
            <<L"Просмотреть объекты - 1"<<std::endl
            <<L"Добавить объект - 2"<<std::endl
            <<L"Группировать объекты - 3"<<std::endl
            <<L"Сохранить - 4"<<std::endl
            <<L"Выйти - 0"<<std::endl;
    int choice;
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;
    if (choice == 0){
        _isWorking = false;
    } else if (choice == 1){
        _jobCall = &AppController::ShowObjects;
    }else if (choice == 2){
        _jobCall = &AppController::AddObject;
    }else if (choice == 3){
        _jobCall = &AppController::Group;
    }else if (choice == 4){
        _jobCall = &AppController::Save;
    }
}

void AppController::ShowObjects() {
    std::wcout<<L"Отображение содержимого"<<std::endl<<std::endl
            <<L"На экране отображается только 10 элементов из файла."<<std::endl
            <<L"Ниже перечисленны функции данного приложения."<<std::endl
            <<L"Для выполнения нужной вам функции введите соответствующую цифру в консоль"<<std::endl<<std::endl
            <<L"Функции:"<<std::endl
                <<L"Просмотреть первые 10 объектов - 1"<<std::endl
                <<L"Просмотреть следующие 10 объектов - 2"<<std::endl
                <<L"Просмотреть предыдущие 10 объектов - 3"<<std::endl
                <<L"Просмотреть последние 10 объектов - 4"<<std::endl
                <<L"Вернуться в основное меню - 0"<<std::endl<<std::endl;
    std::wcout<<"-=-=-=--=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<std::endl;
    auto numberOfObjects = _controller->GetNumberOfObject();
    std::wcout<<L"Всего в файле содержится объектов: "<<numberOfObjects<<std::endl<<std::endl;
    std::vector<std::shared_ptr<Object>> objects;
    if (_showWindowIndex+10>numberOfObjects){
        objects =_controller->GetObjects(_showWindowIndex,numberOfObjects);
    } else{
        objects =_controller->GetObjects(_showWindowIndex,_showWindowIndex+10);
    }

    for (int i = 0; i<objects.size();++i){
        std::wcout<<L"№"<<i+_showWindowIndex+1<<" - "<<objects[i]->toString()<<std::endl;
    }
    std::wcout<<"-=-=-=--=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<std::endl;
    int choice;
    std::wcin.ignore();
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;
    if (choice == 0){
        _jobCall = &AppController::MainMenu;
    }else if (choice == 1){
        _showWindowIndex = 0;
    }else if (choice == 2){
        if (_showWindowIndex+10<numberOfObjects){
            _showWindowIndex +=10;
        }
    }else if (choice == 3){
        if (_showWindowIndex-10>=0){
            _showWindowIndex -=10;
        }
    }else if (choice == 4){
            _showWindowIndex = (numberOfObjects/10)*10;
    } else{
        std::wcout<<L"Не верный ввод"<<std::endl<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}


std::shared_ptr<Object> chooseType(){
    std::wcout<<L"Выберите тип объекта"<<std::endl<<std::endl
              <<L"Типы:"<<std::endl
              <<L"Отмена создания - 0"<<std::endl
              <<L"Машина - 1"<<std::endl
              <<L"Здание - 2"<<std::endl
              <<L"Человек - 3"<<std::endl
              <<L"Дерево - 4"<<std::endl;

    int choice;
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;
    if (choice == 0){
        return nullptr;
    }
    else if (choice == 1){
        return std::make_shared<Car>();
    } else if (choice == 2){
        return std::make_shared<Building>();
    } else if (choice == 3){
        return std::make_shared<Human>();
    }else if (choice == 4){
        return std::make_shared<Tree>();
    }else{
        std::wcout<<L"Не верный ввод"<<std::endl<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
        return chooseType();
    }
}

double getNumberFromConsole(){
    double userInput;
    std::wstring inputStr;
    while (true) {
        std::wcout << L"Введите число (с точкой или запятой в качестве разделителя): ";
        std::wcin >> inputStr;
        std::replace(inputStr.begin(), inputStr.end(), L'.', L',');
        std::wistringstream inputStream(inputStr);
        if (inputStream >> userInput) {
            return userInput;
        } else {
            std::wcout << L"Некорректный ввод. Пожалуйста, введите число еще раз." << std::endl;
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
        }
    }
}

void AppController::AddObject() {
    std::wcout<<L"Добавление объекта"<<std::endl<<std::endl;
    std::shared_ptr<Object> object = chooseType();
    if (object != nullptr) {
        std::wcout << L"Введите имя: ";
        std::wstring name;
        std::wcin >> name;
        object->SetName(name);
        std::wcout << L"Введите координату x:"<<std::endl;
        double x = getNumberFromConsole();
        std::wcout << L"Введите координату y:"<<std::endl;
        double y = getNumberFromConsole();
        object->SetCoordinates(x, y);
        _controller->AddObject(object);
        system("cls");
        std::wcout << L"Объект: " << object->toString() << L"добавлен";
    }
    _jobCall = &AppController::MainMenu;
}

void AppController::Save() {
    _controller->SaveObjects();
    std::wcout << L"Файл успешно сохранен"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    _jobCall = &AppController::MainMenu;
}

void AppController::Group() {
    std::wcout<<L"Выберите тип группировки"<<std::endl<<std::endl
              <<L"Типы:"<<std::endl
              <<L"Отмена создания - 0"<<std::endl
              <<L"По алфавиту - 1"<<std::endl;

    int choice;
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;
    if (choice == 0){
        _jobCall = &AppController::MainMenu;
    }
    else if (choice == 1){
        _jobCall = &AppController::GroupByAlphabet;
    }else{
        std::wcout<<L"Не верный ввод"<<std::endl<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }
}

void AppController::GroupByAlphabet() {
    _controller->sorByAlphabetGrouper();
   auto groupsName = _controller->getAlphabetGroupsNames();
    std::wcout<<L"Группировка по алфавиту"<<std::endl<<std::endl<<L"Существующие группы: "<<std::endl;
    for(auto& group: groupsName){
        std::wcout<<group<<std::endl;
    }
    std::wcout<<L"Для просмотра объектов в группе введите соответствующий символ"<<std::endl<<std::endl;

    wchar_t choice;
    std::wcout<<L"Ввод: ";
    std::wcin >> choice;

    auto it  = groupsName.find(choice);
    if (it != groupsName.end()) {
        _
    }

}
