#include "HashTable.hpp"

void HashTable::clear() { map_.clear(); }

void HashTable::build(const std::vector<Course>& courses) {
    map_.clear();
    for (const auto& c : courses) map_[c.courseNumber] = c;
}

bool HashTable::exists(const std::string& id) const {
    return map_.find(id) != map_.end();
}

Course HashTable::get(const std::string& id) const {
    auto it = map_.find(id);
    if (it == map_.end()) return Course{};
    return it->second;
}
