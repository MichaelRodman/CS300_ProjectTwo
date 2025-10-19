#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <unordered_map>
#include <string>
#include "Course.hpp"

class HashTable {
public:
    void clear();
    void build(const std::vector<Course>& courses);
    bool exists(const std::string& id) const;
    Course get(const std::string& id) const; // empty Course if missing
private:
    std::unordered_map<std::string, Course> map_;
};

#endif // HASHTABLE_HPP
