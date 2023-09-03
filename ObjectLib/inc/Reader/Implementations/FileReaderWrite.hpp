#pragma once

#include <Reader/ReadWriteInterface.hpp>
#include <filesystem>

namespace fs = std::filesystem;

class FileReaderWrite: public ReadWriteInterface{
public:
    explicit FileReaderWrite(fs::path path);
    std::unordered_map<int,std::shared_ptr<Object>> GetObjects() override;
    void SaveObjects(const std::unordered_map<int,std::shared_ptr<Object>>& objects) override;
    void AppendObjects(const std::unordered_map<int,std::shared_ptr<Object>>& objects) override;
    void SaveInSpecifiedOrder(const std::unordered_map<int,std::shared_ptr<Object>>& objects,const std::vector<int>& order) override;

private:
    fs::path _file;
};
