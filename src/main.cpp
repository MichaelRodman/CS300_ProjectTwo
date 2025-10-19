#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <filesystem>

#include "Course.hpp"
#include "Utils.hpp"
#include "VectorStore.hpp"
#include "HashTable.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

static void showMenu() {
    cout << "\nCourse Planner\n";
    cout << "  1. Load Data Structure\n";
    cout << "  2. Print Course List\n";
    cout << "  3. Print Course\n";
    cout << "  9. Exit\n";
    cout << "Select an option: ";
}

static void printCourse(const Course& c, const HashTable& ht) {
    cout << c.courseNumber << ", " << c.courseName << '\n';
    cout << "Prerequisites: ";
    if (c.prerequisites.empty()) {
        cout << "None\n";
    } else {
        for (size_t i = 0; i < c.prerequisites.size(); ++i) {
            const string& pid = c.prerequisites[i];
            Course pre = ht.get(pid);
            cout << pid;
            if (!pre.courseNumber.empty()) cout << " (" << pre.courseName << ")";
            if (i + 1 < c.prerequisites.size()) cout << ", ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    VectorStore vstore;
    HashTable htable;
    BinarySearchTree bst;
    vector<Course> allCourses;
    bool loaded = false;

    while (true) {
        showMenu();

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        if (choice == 9) {
            cout << "Thank you for using the course planner!\n";
            break;
        }

        switch (choice) {
            case 1: {
                cout << "Enter the data file path (e.g., data/courses.csv): ";
                string path;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
                getline(cin, path);

                cout << "\nAttempting to load file: " << path << '\n';

                if (!util::loadCoursesFromCSV(path, allCourses)) {
                    cout << "Could not open file: " << path << '\n';
                    cout << "Current working directory: "
                         << filesystem::current_path().string() << "\n\n";
                    break;
                }

                vstore.build(allCourses);
                htable.build(allCourses);
                bst.build(allCourses);
                loaded = true;

                cout << "Data loaded successfully: " << allCourses.size() << " courses.\n\n";
                break;
            }

            case 2: {
                if (!loaded) {
                    cout << "Please load the data first (Option 1).\n";
                    break;
                }
                cout << "\nHere is a sample schedule:\n\n";
                bst.printInOrder();            // sorted alphanumeric by course number
                cout << '\n';
                break;
            }

            case 3: {
                if (!loaded) {
                    cout << "Please load the data first (Option 1).\n";
                    break;
                }

                cout << "What course do you want to know about? ";
                string courseNum;
                cin >> courseNum;
                courseNum = util::toUpper(courseNum);

                Course c = htable.get(courseNum);
                if (c.courseNumber.empty()) {
                    cout << "Course not found: " << courseNum << '\n';
                } else {
                    printCourse(c, htable);
                }
                break;
            }

            default:
                cout << choice << " is not a valid option.\n";
                break;
        }
    }

    return 0;
}
