#pragma once
#include <utility>
#include <Reader/Implementations/FileReaderWrite.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Object/ObjectFactory.hpp"

FileReaderWrite::FileReaderWrite(fs::path path): _file(std::move(path)) {}

std::unordered_map<int,std::shared_ptr<Object>>FileReaderWrite::GetObjects() {
    std::unordered_map<int,std::shared_ptr<Object>> objects;

    std::wifstream inputFile(_file);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file: " << _file << std::endl;
        return objects;
    }

    std::wstring line;
    while (std::getline(inputFile, line)) {
        std::wistringstream iss(line);
        std::wstring name;
        double x, y;
        std::wstring type;
        double creationTime;
        //iss.imbue(std::locale("C"));
        if (iss >> name >> x >> y >> type >> creationTime) {
            auto object= ObjectFactory::createObject(type, name, x,y,creationTime);
            objects[object->GetId()] = object;
        } else {
            std::wcerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();
    return objects;
}

void FileReaderWrite::SaveObjects(const std::unordered_map<int,std::shared_ptr<Object>> &objects) {
    std::wofstream outputFile(_file);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << _file << std::endl;
        return;
    }

    for (const auto& objectPtr : objects) {
        if (objectPtr.second) {
            outputFile << objectPtr.second->toString() << '\n';
        }
    }
    outputFile.close();
}

void FileReaderWrite::AppendObjects(const std::unordered_map<int,std::shared_ptr<Object>> &objects) {
    std::wofstream outputFile(_file, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << _file << std::endl;
        return;
    }

    for (const auto& objectPtr : objects) {
        if (objectPtr.second) {
            outputFile << objectPtr.second->toString() << std::endl;
        }
    }
    outputFile.close();
}

void FileReaderWrite::SaveInSpecifiedOrder(const std::unordered_map<int, std::shared_ptr<Object>> &objects,
                                           const std::vector<int> &order) {
    std::wofstream outputFile(_file);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << _file << std::endl;
        return;
    }

    for (const auto& id : order) {
        auto it = objects.find(id);
        if (it != objects.end()) {
            outputFile << it->second->toString() << std::endl;
        }
    }
}
