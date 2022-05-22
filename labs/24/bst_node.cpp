/*
 * Name        : lab_23.cpp
 * Author      : Ptolemy Linden
 * Description : Creating a Binary Search Tree class
*/
#include "bst_node.h"

// Default Constructor
BSTNode::BSTNode() {
  contents_ = 0;
  left_child_ = NULL;
  right_child_ = NULL;
}

// Overloaded Constructor
BSTNode::BSTNode(int contents) {
  contents_ = contents;
  left_child_ = NULL;
  right_child_ = NULL;
}

// Destructor
BSTNode::~BSTNode() {
  left_child_ = NULL;
  right_child_ = NULL;
}


// --------------------
//      Mutators
// --------------------

// Sets the contents of the node
void BSTNode::SetContents(int contents) {
  contents_ = contents;
}

// Sets the pointer to a left child
void BSTNode::SetLeftChild(BSTNode* left_child) {
  left_child_ = left_child;
}

// Sets the pointer to a right child
void BSTNode::SetRightChild(BSTNode* right_child) {
  right_child_ = right_child;
}


// --------------------
//      Accessors
// --------------------

// Returns the actual value stored in contents_
int BSTNode::GetContents() const {
  return contents_;
}

// Returns the memory address of contents_
int& BSTNode::GetContents() {
  return contents_;
}

// Returns the pointer to a left child
BSTNode* BSTNode::GetLeftChild() const {
  return left_child_;
}

// Returns the memory address of a left child
BSTNode*& BSTNode::GetLeftChild() {
  return left_child_;
}

// Returns the pointer to a right child
BSTNode* BSTNode::GetRightChild() const {
  return right_child_;
}

// Returns the memory address of a right child
BSTNode*& BSTNode::GetRightChild() {
  return right_child_;
}
