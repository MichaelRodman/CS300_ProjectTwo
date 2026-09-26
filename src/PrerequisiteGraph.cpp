#include "PrerequisiteGraph.hpp"
#include <queue>

void PrerequisiteGraph::build(const std::vector<Course>& courses) {
    adjacency.clear();
    indegree.clear();

    // Create one graph node for every course.
    for (const Course& course : courses) {
        adjacency[course.courseNumber];
        indegree[course.courseNumber] = 0;
    }

    // Add a directed edge from each prerequisite to the course
    // that depends on it.
    //
    // Time complexity: O(V + E), where V is the number of courses
    // and E is the total number of prerequisite relationships.
    for (const Course& course : courses) {
        for (const std::string& prerequisite : course.prerequisites) {
            adjacency[prerequisite].push_back(course.courseNumber);
            ++indegree[course.courseNumber];
        }
    }
}

std::vector<std::string> PrerequisiteGraph::topologicalSort() const {
    std::vector<std::string> ordering;

    // Work with a copy so the graph's stored indegree values remain unchanged.
    std::unordered_map<std::string, int> remainingIndegree = indegree;
    std::queue<std::string> ready;

    // Courses with no prerequisites can be processed first.
    for (const auto& entry : remainingIndegree) {
        if (entry.second == 0) {
            ready.push(entry.first);
        }
    }

    // Kahn's algorithm processes each vertex and edge once.
    // Time complexity: O(V + E).
    while (!ready.empty()) {
        std::string current = ready.front();
        ready.pop();

        ordering.push_back(current);

        auto neighbors = adjacency.find(current);
        if (neighbors == adjacency.end()) {
            continue;
        }

        for (const std::string& dependent : neighbors->second) {
            --remainingIndegree[dependent];

            if (remainingIndegree[dependent] == 0) {
                ready.push(dependent);
            }
        }
    }

    // A complete ordering is impossible when a cycle exists.
    if (ordering.size() != indegree.size()) {
        return {};
    }

    return ordering;
}

bool PrerequisiteGraph::hasCycle() const {
    if (indegree.empty()) {
        return false;
    }

    // Kahn's algorithm returns an empty ordering when a cycle
    // prevents all vertices from being processed.
    // Time complexity: O(V + E).
    return topologicalSort().empty();
}