#include "Utils.hpp"
#include <fstream>
#include <sstream>
#include <cctype>

namespace util {

std::string trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

std::string toUpper(std::string s) {
    for (char& c : s)
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    return s;
}

std::vector<std::string> splitCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) fields.push_back(trim(token));
    return fields;
}

bool loadCoursesFromCSV(const std::string& path, std::vector<Course>& out) {
    std::ifstream in(path);                 
    if (!in) return false;

    out.clear();
    std::string line;
    bool firstLine = true;

    while (std::getline(in, line)) {
        // Strip UTF-8 BOM on the very first line only: EF BB BF
        if (firstLine && line.size() >= 3 &&
            static_cast<unsigned char>(line[0]) == 0xEF &&
            static_cast<unsigned char>(line[1]) == 0xBB &&
            static_cast<unsigned char>(line[2]) == 0xBF) {
            line.erase(0, 3);
        }
        firstLine = false;

        line = trim(line);
        if (line.empty()) continue;

        auto fields = splitCSVLine(line);
        if (fields.size() < 2) continue;

        Course c;
        c.courseNumber = toUpper(fields[0]);
        c.courseName   = fields[1];
        for (size_t i = 2; i < fields.size(); ++i) {
            if (!fields[i].empty())
                c.prerequisites.push_back(toUpper(fields[i]));
        }
        out.push_back(c);
    }
    return true;
}

} // namespace util
