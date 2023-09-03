#pragma once
#include <iostream>
#include <AppController.hpp>

int main() {
    std::locale::global(std::locale("Russian_Russia"));
    std::wcin.imbue(std::locale("rus_rus.866"));
    AppController controller;
    controller.Start();
    return 0;
}