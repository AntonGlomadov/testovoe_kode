#include <cwctype>
#include <algorithm>
#include "Groupers/AlphabetGrouper.hpp"

std::map<wchar_t, std::vector<std::shared_ptr<Object>>>
AlphabetGrouper::sortByRuAlphabet(const std::vector<std::shared_ptr<Object>> &data) {
    std::map<wchar_t, std::vector<std::shared_ptr<Object>>> groupedObjects;
    for (const auto& obj : data) {
        auto  name = obj->GetName();
        auto firstLetter = name[0];
        if ((firstLetter >= L'А' && firstLetter <= L'я') ||
            (firstLetter >= L'А' && firstLetter <= L'Я') ||
            (firstLetter == L'Ё'|| firstLetter == L'ё')){ // ёЁ по какой-то пречине не входит в алфавит
            firstLetter = std::towupper(firstLetter);
        } else{
            firstLetter = '#';
        }
        groupedObjects[firstLetter].push_back(obj);
    }

    // Сортировка каждой группы по имени
    for (auto& group : groupedObjects) {
        std::sort(group.second.begin(), group.second.end(),
                  [](const std::shared_ptr<Object>& a, const std::shared_ptr<Object>& b) {
                      auto first = a->GetName();
                      auto second = b->GetName();
                      for(auto &c:first){
                          c = std::towlower(c);
                      }
                      for(auto &c:second){
                          c = std::towlower(c);
                      }
                      return first < second;
                  });
    }
    return groupedObjects;
}
