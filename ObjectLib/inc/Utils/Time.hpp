#pragma once
#include <chrono>

namespace utils{
    double getCurrentTimeInMillisecondsDouble(){
        auto time  = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        return static_cast<double>(time)/1000;
    }
}
