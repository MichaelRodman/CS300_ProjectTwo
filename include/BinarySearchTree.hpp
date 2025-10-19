#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Course.hpp"

struct BSTNode {
    Course course;
    BSTNode* left{nullptr};
    BSTNode* right{nullptr};
    explicit BSTNode(const Course& c) : course(c) {}
};

class BinarySearchTree {
public:
    ~BinarySearchTree();
    void clear();
    void build(const std::vector<Course>& courses);
    void insert(const Course& c);
    void printInOrder() const; // prints "CSCI100, Intro ..."
private:
    BSTNode* root_{nullptr};
    void destroy(BSTNode* n);
    BSTNode* insertRec(BSTNode* node, const Course& c);
    void inOrderRec(BSTNode* node) const;
};

#endif // BINARYSEARCHTREE_HPP
