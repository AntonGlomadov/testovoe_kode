#pragma once
#include <iostream>
#include <ObjImplementations/Human.hpp>
#include <Reader/ReadWriteInterface.hpp>
#include <Reader/Implementations/FileReader.hpp>
#include "ObjImplementations/Car.hpp"
#include "ObjImplementations/Tree.hpp"
#include "ObjImplementations/Building.hpp"
#include <Groupers/AlphabetGrouper.hpp>

void addToFile(){
    std::unique_ptr<ReadWriteInterface> readWriteInterface = std::make_unique<FileReader>(".\\data.txt");
    std::vector<std::shared_ptr<Object>> objects;
    objects.emplace_back(std::make_shared<Car>(L"Ёуди",10,20));
    objects.emplace_back(std::make_shared<Car>(L"ёмв",10,50));
    objects.emplace_back(std::make_shared<Car>(L"Лада",40,20));
    objects.emplace_back(std::make_shared<Human>(L"Антон",70,20));
    objects.emplace_back(std::make_shared<Human>(L"антон",10,90));
    objects.emplace_back(std::make_shared<Human>(L"Вася",24,20));
    objects.emplace_back(std::make_shared<Tree>(L"Береза",45,0));
    objects.emplace_back(std::make_shared<Tree>(L"Дуб",0,0));
    objects.emplace_back(std::make_shared<Tree>(L"Ясень",2,4));
    objects.emplace_back(std::make_shared<Building>(L"Дом",10,20));
    objects.emplace_back(std::make_shared<Building>(L"Аптека",12,2));
    objects.emplace_back(std::make_shared<Building>(L"Магазин",56,7));
    objects.emplace_back(std::make_shared<Tree>(L"2сень",2,4));
    objects.emplace_back(std::make_shared<Building>(L"1ом",10,20));
    objects.emplace_back(std::make_shared<Building>(L"Aптека",12,2));
    objects.emplace_back(std::make_shared<Building>(L"Cагазин",56,7));
    readWriteInterface->SaveObjects(objects);
}

void testRead(){
    std::unique_ptr<ReadWriteInterface> readWriteInterface = std::make_unique<FileReader>(".\\data.txt");
    std::vector<std::shared_ptr<Object>> objects = readWriteInterface->GetObjects();
    for(auto& obj :objects){
        auto z  = obj->toString();
        std::wcout<<z<<std::endl;
    }
    std::wcout<<"----------------------------"<<std::endl;
    auto nameGrouped = AlphabetGrouper::sortByRuAlphabet(objects);
    // Вывод результатов
    for (const auto& group : nameGrouped) {
        std::wcout << L"Группа \"" << group.first << L"\":\n";
        for (const auto& obj : group.second) {
            std::wcout << L"    " << obj->toString() << L"same type:"<< obj->GetNumberOfObjectWithSameType()  << L"\n";
        }
    }

}

int main()
{
    std::locale::global(std::locale("Russian_Russia"));
    addToFile();
    testRead();
    return 0;
}