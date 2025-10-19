
Southern New Hampshire University  
CS-300: Data Structures and Algorithms  
Instructor: Chao Ling  
Student: Michael Rodman  
Date: October 19, 2025  

-----------------------------------------------------
PROJECT TWO - Course Planner
-----------------------------------------------------

This program allows academic advisors at ABC University (ABCU) to view and organize course information using different data structures.  
The user can:
  1. Load course data from a CSV file  
  2. Display all courses in alphanumeric order  
  3. Search for a specific course and view its prerequisites  

-----------------------------------------------------
FILES INCLUDED
-----------------------------------------------------
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

-----------------------------------------------------
HOW TO RUN
-----------------------------------------------------
1. Open the project folder in Visual Studio Code.  
2. Build using the `g++` build task or terminal command:
      g++ -std=c++17 -Wall -Wextra -O2 -I include src/*.cpp -o ProjectTwo.exe
3. Run the program:
      ./ProjectTwo.exe
4. When prompted for a file path, enter:
      data/courses.csv

-----------------------------------------------------
NOTES
-----------------------------------------------------
- The CSV file must be properly formatted and placed in the data/ folder.
- Hardcoded paths are avoided per best practices.
- The README file serves as documentation for how to compile and test this project.

-----------------------------------------------------
BONUS IMPLEMENTATION
-----------------------------------------------------
This project includes a bonus implementation demonstrating multiple data structures
performing similar operations in different ways.

- The Hash Table is used for fast course lookups (Option 3 - Print Course).
- The Binary Search Tree and Vector are used to print the full course list
  in alphanumeric order (Option 2 - Print Course List).

This shows how the same problem can be approached efficiently using different
data structures within the same program.

