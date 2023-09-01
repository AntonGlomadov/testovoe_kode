#pragma once
#include <iostream>
#include <ObjImplementations/Human.hpp>
#include <Reader/ReadWriteInterface.hpp>
#include <Reader/Implementations/FileReader.hpp>
#include "ObjImplementations/Car.hpp"
#include "ObjImplementations/Tree.hpp"
#include "ObjImplementations/Building.hpp"

void addToFile(){
    std::unique_ptr<ReadWriteInterface> readWriteInterface = std::make_unique<FileReader>(".\\data.txt");
    std::vector<std::shared_ptr<Object>> objects;
    objects.emplace_back(std::make_shared<Car>("Ауди",10,20));
    objects.emplace_back(std::make_shared<Car>("Бмв",10,50));
    objects.emplace_back(std::make_shared<Car>("Лада",40,20));
    objects.emplace_back(std::make_shared<Human>("Антон",70,20));
    objects.emplace_back(std::make_shared<Human>("Дима",10,90));
    objects.emplace_back(std::make_shared<Human>("Вася",24,20));
    objects.emplace_back(std::make_shared<Tree>("Береза",45,0));
    objects.emplace_back(std::make_shared<Tree>("Дуб",0,0));
    objects.emplace_back(std::make_shared<Tree>("Ясень",2,4));
    objects.emplace_back(std::make_shared<Building>("Дом",10,20));
    objects.emplace_back(std::make_shared<Building>("Аптека",12,2));
    objects.emplace_back(std::make_shared<Building>("Магазин",56,7));
    readWriteInterface->SaveObjects(objects);
}

void testRead(){
    std::unique_ptr<ReadWriteInterface> readWriteInterface = std::make_unique<FileReader>(".\\data.txt");
    std::vector<std::shared_ptr<Object>> objects = readWriteInterface->GetObjects();
    for(auto& obj :objects){
        auto z  = obj->toString();
        std::cout<<z<<std::endl;
    }
}

int main()
{
    system("chcp 65001");
    addToFile();
    testRead();
    return 0;
}