#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

struct Course {
    std::string courseNumber;              // e.g., CSCI200
    std::string courseName;                // e.g., Data Structures
    std::vector<std::string> prerequisites;// e.g., {"CSCI101","MATH201"}
};

#endif // COURSE_HPP
