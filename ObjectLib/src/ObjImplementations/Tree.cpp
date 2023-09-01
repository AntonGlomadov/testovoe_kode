
#include <ObjImplementations/Tree.hpp>
#include <utility>

Tree::Tree(std::string name, double x, double y) : Object(std::move(name), x, y) {
    _type = "Дерево";
}

Tree::Tree():Object() {
    _type = "Дерево";
}
