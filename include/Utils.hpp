#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include "Course.hpp"

namespace util {

// string helpers
std::string trim(const std::string& s);
std::string toUpper(std::string s);

// split a CSV line by commas 
std::vector<std::string> splitCSVLine(const std::string& line);

// Load courses from CSV file 
bool loadCoursesFromCSV(const std::string& path, std::vector<Course>& out);

} // namespace util

#endif // UTILS_HPP
