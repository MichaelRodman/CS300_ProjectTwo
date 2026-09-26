#ifndef PREREQUISITE_GRAPH_HPP
#define PREREQUISITE_GRAPH_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include "Course.hpp"

class PrerequisiteGraph {
public:
    // Builds a directed graph where each prerequisite points to
    // the course that depends on it.
    void build(const std::vector<Course>& courses);

    // Returns true when the prerequisite relationships contain a cycle.
    bool hasCycle() const;

    // Returns a valid prerequisite-first course ordering.
    // Returns an empty vector if a cycle exists.
    std::vector<std::string> topologicalSort() const;

private:
    std::unordered_map<std::string, std::vector<std::string>> adjacency;
    std::unordered_map<std::string, int> indegree;
};

#endif // PREREQUISITE_GRAPH_HPP