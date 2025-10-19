#include "VectorStore.hpp"
#include <algorithm>
#include <iostream>

void VectorStore::clear() { data_.clear(); }

void VectorStore::build(const std::vector<Course>& courses) { data_ = courses; }

const Course* VectorStore::find(const std::string& id) const {
    for (const auto& c : data_) if (c.courseNumber == id) return &c;
    return nullptr;
}

std::vector<Course> VectorStore::sortedByCourseNumber() const {
    std::vector<Course> v = data_;
    std::sort(v.begin(), v.end(),
              [](const Course& a, const Course& b){ return a.courseNumber < b.courseNumber; });
    return v;
}

void VectorStore::printAllSorted() const {
    auto v = sortedByCourseNumber();
    for (const auto& c : v)
        std::cout << c.courseNumber << ", " << c.courseName << '\n';
}
