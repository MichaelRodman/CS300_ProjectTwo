# Course Planner (CS 300 – Data Structures & Algorithms)

C++17 console application that loads course data from a CSV file, displays all courses in alphanumeric order, and supports searching a course to view its prerequisites.

This project demonstrates foundational software development skills (file I/O, parsing, OOP, data structures, and clear documentation).

---

## Tech & Concepts
- **Language:** C++17
- **Core:** OOP, modular design, debugging, file I/O, CSV parsing
- **Data Structures:** Hash Table (lookup), Binary Search Tree (sorted traversal), and Directed Graph (prerequisite relationships)
- **Build:** g++ (VS Code terminal)

---

## Demo

**Load courses from CSV**
![Load demo](docs/demo-load.jpg)

**Print courses in alphanumeric order**
![Sorted demo](docs/demo-sorted.jpg)

---

## Features
- Load course data from a CSV file
- Print all courses in **alphanumeric order**
- Search by course ID (example: `CS300`) to display course details and prerequisites
- Menu-driven interface

---

## Project Structure
```text
data/
  courses.csv
include/
  *.hpp
src/
  *.cpp
docs/
  demo-load.jpg
  demo-sorted.jpg
```

---

## CS 499 Capstone Enhancement: Algorithms and Data Structures

For the CS 499 Computer Science Capstone, this project was enhanced with a directed prerequisite graph that represents relationships between courses.

### Enhancement Features

- Builds a directed graph from course prerequisite relationships
- Uses Kahn's topological sorting algorithm to generate a prerequisite-safe course order
- Detects circular prerequisite dependencies and prevents invalid course ordering
- Preserves the original binary search tree, hash table, and course lookup functionality
- Includes a controlled cycle-test dataset in `data/courses_cycle.csv`
- Validates prerequisite references and identifies courses that depend on missing course IDs
- Includes a missing-prerequisite test dataset in `data/courses_missing.csv`


### Algorithm Design

Each course is represented as a vertex in the graph. A directed edge is created from a prerequisite course to the course that depends on it.

Topological sorting is performed using Kahn's algorithm. Courses with an indegree of zero are processed first, and dependent courses become available as their prerequisite edges are removed.

If every course cannot be processed, the graph contains a cycle and a valid prerequisite ordering cannot be produced.

### Time Complexity

Graph construction and topological sorting both operate in:

**O(V + E)**

where:

- `V` is the number of courses
- `E` is the number of prerequisite relationships

This approach is efficient because each vertex and prerequisite edge is processed only once during traversal.


### Testing and Validation

The enhanced Course Planner was compiled using C++17 with additional compiler warnings enabled. Compilation completed successfully without errors or warnings.

The following manual tests were completed:

1. **Normal Course Ordering:** Loaded `data/courses.csv` and verified that the program generated a valid prerequisite-safe course order.

2. **Circular Dependency Detection:** Loaded `data/courses_cycle.csv` and verified that the program detected the circular dependency and refused to generate an invalid course order.

3. **Missing Prerequisite Validation:** Loaded `data/courses_missing.csv`, which intentionally references the nonexistent course `CSCI999`. The program correctly identified the missing prerequisite and displayed an appropriate error message instead of reporting a cycle.

These tests confirmed that the new validation works while preserving the original graph functionality.

### Instructor Feedback

Following the initial enhancement, Professor Sanford recommended additional testing for missing or invalid prerequisite references. I incorporated this feedback by adding prerequisite-reference validation, a dedicated test dataset, and clearer error reporting. This improvement helps distinguish missing course data from actual circular dependencies.
