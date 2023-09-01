#pragma once

#include <Reader/ReadWriteInterface.hpp>
#include <filesystem>

namespace fs = std::filesystem;

class FileReader: public ReadWriteInterface{
public:
    explicit FileReader(fs::path path);
    std::vector<std::shared_ptr<Object>> GetObjects() override;
    void SaveObjects(const std::vector<std::shared_ptr<Object>>& objects) override;
    void AppendObjects(const std::vector<std::shared_ptr<Object>>& objects) override;

private:
    fs::path _file;
};
