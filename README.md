# CS 300: Data Structures and Algorithms

## Project Overview
This repository contains my work for CS 300 at Southern New Hampshire University.  
The goal of these projects was to design efficient algorithms and use appropriate data structures to store and retrieve course information for academic advisors at ABC University.

### Artifacts Included
- **Project One:** Runtime and memory analysis of different data structures  
- **Project Two:** C++ implementation that loads, sorts, and prints course information in alphanumeric order  

---

## Reflection

### What problem were you solving?
In these projects, I developed software that helps academic advisors access and organize Computer Science course data efficiently. The program needed to read course data from a file, store it in a data structure, and display courses in sorted order.

### How did you approach the problem, and why are data structures important?
I approached the problem by first comparing various data structures and evaluating their runtime and memory performance. I chose a hash table for quick lookups and a binary search tree for maintaining sorted data. Understanding data structures is essential because the wrong choice can lead to inefficient performance and scalability issues.

### How did you overcome roadblocks?
My main challenges were ensuring the data parsed correctly and the sorting algorithm worked as expected. I solved these by debugging step-by-step, testing smaller parts of the program, and carefully validating input data.

### How has your work expanded your approach to software design?
This course emphasized the importance of pre-planning algorithms and understanding data relationships before coding. I learned that creating pseudocode, visualizing data flow, and testing small components early helps prevent larger issues later.

### How has your work evolved your coding practices?
These projects improved how I structure my programs. I now focus more on readability, modular design, and meaningful comments. I also consider runtime efficiency during the planning phase instead of after coding. These habits make my programs more maintainable and adaptable for future improvements.

---

### Repository Information
Course: CS 300 – Data Structures and Algorithms  
Institution: Southern New Hampshire University  
Date: October 2025  

---

---
## Project Two Details (Course Planner)

## PROJECT TWO – Course Planner
This program allows academic advisors at ABC University (ABCU) to view and organize course information using different data structures.  
The user can:
  1. Load course data from a CSV file  
  2. Display all courses in alphanumeric order  
  3. Search for a specific course and view its prerequisites

## Files Included
src/
    main.cpp
    Utils.cpp
    VectorStore.cpp
    HashTable.cpp
    BinarySearchTree.cpp

include/
    Course.hpp
    Utils.hpp
    VectorStore.hpp
    HashTable.hpp
    BinarySearchTree.hpp

data/
    courses.csv

.vscode/
    launch.json
    tasks.json

## How To Run
1. Open the project folder in Visual Studio Code.  
2. Build using the `g++` build task or terminal command:
      g++ -std=c++17 -Wall -Wextra -O2 -I include src/*.cpp -o ProjectTwo.exe
3. Run the program:
      ./ProjectTwo.exe
4. When prompted for a file path, enter:
      data/courses.csv

## Notes
- The CSV file must be properly formatted and placed in the data/ folder.
- Hardcoded paths are avoided per best practices.
- The README file serves as documentation for how to compile and test this project.
  
