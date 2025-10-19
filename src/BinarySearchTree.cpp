#include "BinarySearchTree.hpp"
#include <iostream>

BinarySearchTree::~BinarySearchTree() { clear(); }

void BinarySearchTree::destroy(BSTNode* n) {
    if (!n) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
}

void BinarySearchTree::clear() { destroy(root_); root_ = nullptr; }

void BinarySearchTree::build(const std::vector<Course>& courses) {
    clear();
    for (const auto& c : courses) insert(c);
}

void BinarySearchTree::insert(const Course& c) { root_ = insertRec(root_, c); }

BSTNode* BinarySearchTree::insertRec(BSTNode* node, const Course& c) {
    if (!node) return new BSTNode(c);
    if (c.courseNumber < node->course.courseNumber)
        node->left = insertRec(node->left, c);
    else
        node->right = insertRec(node->right, c);
    return node;
}

void BinarySearchTree::printInOrder() const { inOrderRec(root_); }

void BinarySearchTree::inOrderRec(BSTNode* node) const {
    if (!node) return;
    inOrderRec(node->left);
    std::cout << node->course.courseNumber << ", " << node->course.courseName << '\n';
    inOrderRec(node->right);
}
