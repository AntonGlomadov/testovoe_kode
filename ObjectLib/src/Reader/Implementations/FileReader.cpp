#pragma once
#include <utility>
#include <Reader/Implementations/FileReader.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ObjectFactory.hpp"

FileReader::FileReader(fs::path path): _file(std::move(path)) {}

std::vector<std::shared_ptr<Object>>FileReader::GetObjects() {
    std::vector<std::shared_ptr<Object>> objects;

    std::ifstream inputFile(_file);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file: " << _file << std::endl;
        return objects;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name;
        double x, y;
        std::string type;
        double creationTime;

        if (iss >> name >> x >> y >> type >> creationTime) {
            auto object= ObjectFactory::createObject(type);
            object->SetName(name);
            object->SetCoordinates(x,y);
            objects.push_back(object);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();
    return objects;
}

void FileReader::SaveObjects(const std::vector<std::shared_ptr<Object>> &objects) {
    std::ofstream outputFile(_file);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << _file << std::endl;
        return;
    }

    for (const auto& objectPtr : objects) {
        if (objectPtr) {
            outputFile << objectPtr->toString() << '\n';
        }
    }
    outputFile.close();
}

void FileReader::AppendObjects(const std::vector<std::shared_ptr<Object>> &objects) {
    std::ofstream outputFile(_file, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << _file << std::endl;
        return;
    }

    for (const auto& objectPtr : objects) {
        if (objectPtr) {
            auto z= objectPtr->toString();
            outputFile << objectPtr->toString() << std::endl;
        }
    }
    outputFile.close();
}
