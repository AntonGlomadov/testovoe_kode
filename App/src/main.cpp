#pragma once
#include <iostream>
#include <Reader/ReadWriteInterface.hpp>
#include <Reader/Implementations/FileReader.hpp>
#include <Object/ObjectsController.hpp>
#include <Object/Impl/Human.hpp>
#include <Object/Impl/Car.hpp>
#include <Object/Impl/Tree.hpp>
#include <Object/Impl/Building.hpp>
#include <Groupers/AlphabetGrouper.hpp>
#include <Groupers/TypeGrouper.hpp>
#include <Groupers/TimeGrouper.hpp>
#include <functional>
#include <AppController.hpp>

void HelloMessage(){
    std::wcout<<L"Это консольное прилоежение для тестового задния."<<std::endl
                <<L"По умолчанию программа работает с файлом example.txt - который по умолчанию располагается рядом с программой";
}




int main() {
    std::locale::global(std::locale("Russian_Russia"));
    std::wcin.imbue(std::locale("rus_rus.866"));
    AppController test;
    test.Start();
/*    std::locale::global(std::locale("Russian_Russia"));
    std::unique_ptr<ObjectsController> _controller = std::make_unique<ObjectsController>(std::make_unique<FileReader>("./data.txt"));
    _controller->Init();

    auto data = _controller->GetObjects(4,9);
    for(auto& i:data){
        std::wcout << L"    " << i->toString() <<L" id:"<<i->GetId()<< L"\n";
    }

    bool working = true;
    while (working){
        std::wcout << L"    " << i->toString() <<L" id:"<<i->GetId()<< L"\n";

    }*/
}