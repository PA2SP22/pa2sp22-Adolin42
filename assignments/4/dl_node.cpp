/*
 * Name        : dl_node.cpp
 * Author      : Ptolemy Linden
 * Description : Creating a DLNode class
*/

#include "dl_node.h"

// Constructor
DLNode::DLNode(int contents) {
  contents_ = contents;
  previous_ = NULL;
  next_ = NULL;
}

// Destructor
DLNode::~DLNode() {}

// Mutators
void DLNode::SetContents(int contents) {
  contents_ = contents;
}

void DLNode::SetNext(DLNode* next) {
  next_ = next;
}

void DLNode::SetPrevious(DLNode* previous) {
  previous_ = previous;
}

// Accessors
int DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_;
}

DLNode* DLNode::GetPrevious() const {
  return previous_;
}