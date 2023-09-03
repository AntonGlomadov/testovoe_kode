
#include "Object/Impl/Tree.hpp"
#include <utility>

Tree::Tree(std::wstring name, double x, double y) : Object(std::move(name), x, y) {
    if (type_counts.find(L"Дерево") == type_counts.end()) {
        type_counts[L"Дерево"] = 1;
    } else {
        type_counts[L"Дерево"]++;
    }
    _type = L"Дерево";
}

Tree::Tree():Object() {
    if (type_counts.find(L"Дерево") == type_counts.end()) {
        type_counts[L"Дерево"] = 1;
    } else {
        type_counts[L"Дерево"]++;
    }
    _type = L"Дерево";
}

Tree::~Tree() {
    type_counts[L"Дерево"]--;
}
