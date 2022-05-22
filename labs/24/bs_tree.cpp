/*
 * Name        : lab_24.cpp
 * Author      : Ptolemy Linden
 * Description : Creating a Binary Search Tree class
*/

#include "bs_tree.h"
#include <sstream>
using std::stringstream;
// ------------------
// PRIVATE FUNCTIONS
// -------------------

// 4 MAIN CASES FOR INSERTION

// 1) Tree is empty
// 2) The value is smaller than the root
// 3) The value is larger than the root
// 4) The value is the same as the root
bool BSTree::Insert(int contents, BSTNode*& subroot) {
  if (subroot == NULL) {
    BSTNode* nn = new BSTNode(contents);
    subroot = nn;
    size_++;
    return true;
  } else if (contents < subroot->GetContents()) {
    return Insert(contents, subroot->GetLeftChild());
  } else if (contents > subroot->GetContents()) {
    return Insert(contents, subroot->GetRightChild());
  } else {
    return false;
  }
}

// Clear the entire contents of the tree, freeing all memory
// associated with all nodes
void BSTree::Clear(BSTNode*& subroot) {
  if (subroot != NULL) {
    if (subroot->GetLeftChild() != NULL) {
      Clear(subroot->GetLeftChild());
    }
    if (subroot->GetRightChild() != NULL) {
      Clear(subroot->GetRightChild());
    }
    delete subroot;
    subroot = NULL;
  }
  size_ = 0;
}

/*
Creates a string of the data in all nodes in the tree,
in ascending order, separate by spaces (there should be a 
space after the last output value)
*/
string BSTree::InOrder(BSTNode* subroot) {
  if (subroot == NULL) {
    return "";
  }
  stringstream ss;
  ss << InOrder(subroot->GetLeftChild());
  ss << subroot->GetContents() << " ";
  ss << InOrder(subroot->GetRightChild());
  return ss.str();
}

// ------------------
// PUBLIC FUNCTIONS
// -------------------

BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}

BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int contents) {
  return Insert(contents, root_);
}

void BSTree::Clear() {
  Clear(root_);
}

unsigned int BSTree::GetSize() const {
  return size_;
}

string BSTree::InOrder() {
  return InOrder(root_);
}
