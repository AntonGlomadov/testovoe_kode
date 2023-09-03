/*
#pragma once
#include <iostream>
#include "Object/Impl/Human.hpp"
#include <Reader/ReadWriteInterface.hpp>
#include <Reader/Implementations/FileReader.hpp>
#include "Object/Impl/Car.hpp"
#include "Object/Impl/Tree.hpp"
#include "Object/Impl/Building.hpp"
#include <Groupers/AlphabetGrouper.hpp>
#include <Groupers/TypeGrouper.hpp>
#include <Groupers/TimeGrouper.hpp>


void testRead(){
    std::unique_ptr<ReadWriteInterface> readWriteInterface = std::make_unique<FileReader>(".\\data.txt");
    std::unordered_map<int,std::shared_ptr<Object>> objects = readWriteInterface->GetObjects();
    for(auto& obj :objects){
        auto z  = obj.second->toString();
        std::wcout<<z<<std::endl;
    }
    std::wcout<<"----------------------------"<<std::endl;
    auto nameGrouped = AlphabetGrouper::sortByRuAlphabet(objects);
    for (const auto& group : nameGrouped) {
        std::wcout << L"Группа \"" << group.first << L"\":\n";
        for (const auto& obj : group.second) {
            std::wcout << L"    " << obj->toString()   << L"\n";
        }
    }
    std::wcout<<"----------------------------"<<std::endl;
    auto typeGrouped = TypeGrouper::sortByTypeNumber(objects,4);
    for (const auto& group : typeGrouped) {
        std::wcout << L"Группа \"" << group.first << L"\":\n";
        for (const auto& obj : group.second) {
            std::wcout << L"    " << obj->toString() <<L" id:"<<obj->GetId() << L"\n";
        }
    }
    std::wcout<<"----------------------------"<<std::endl;
    auto timeGrouped = TimeGrouper::sortByCreationTyme(objects);
    for (const auto& group : timeGrouped) {
        std::wcout << L"Группа \"" << group.first << L"\":\n";
        for (const auto& obj : group.second) {
            std::wcout << L"    " << obj->toString() <<L" id:"<<obj->GetId()<< L"\n";
        }
    }
}

int main()
{
    std::locale::global(std::locale("Russian_Russia"));
    //addToFile();
    testRead();
    return 0;
}*/
