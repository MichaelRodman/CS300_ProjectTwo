#ifndef VECTORSTORE_HPP
#define VECTORSTORE_HPP

#include <vector>
#include <string>
#include "Course.hpp"

class VectorStore {
public:
    void clear();
    void build(const std::vector<Course>& courses);
    const Course* find(const std::string& id) const;     // nullptr if missing
    std::vector<Course> sortedByCourseNumber() const;    // returns sorted copy
    void printAllSorted() const;                         // convenience printer
private:
    std::vector<Course> data_;
};

#endif // VECTORSTORE_HPP
