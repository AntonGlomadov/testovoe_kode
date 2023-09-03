#pragma once
#include <utility>


struct Point{
    double _x;
    double _y;
    std::wstring toString(){
        return std::to_wstring(_x)+L" "+std::to_wstring(_y);
    }
};

 inline double distanceBetweenPoints(const Point& firstP,const Point& secondP){
    return sqrt(pow(firstP._x - secondP._x,2) + pow(firstP._y - secondP._y,2));
}

