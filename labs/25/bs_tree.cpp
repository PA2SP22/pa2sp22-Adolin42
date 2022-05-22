/*
 * Name        : lab_24.cpp
 * Author      : Ptolemy Linden
 * Description : Creating a Binary Search Tree class
*/

#include "bs_tree.h"
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

/*
  Returns the value of the smallest node in the tree.
  Helper function for private Remove()
*/
int BSTree::FindMin(BSTNode* subroot) {
  if (subroot->GetLeftChild() != NULL) {
    return FindMin(subroot->GetLeftChild());
  }
  return subroot->GetContents();
}

/*
  Traverse the tree and remove the node containing the target 
  integer if present and returning true. Return false if target
  integer is not in tree
*/
bool BSTree::Remove(int contents, BSTNode*& subroot) {
  if (subroot == NULL) {
    return false;
  }
  // Check if contents is smaller than subroot
  if (contents < subroot->GetContents()
      && subroot->GetLeftChild() != NULL) {
    return Remove(contents, subroot->GetLeftChild());
  } else if (contents > subroot->GetContents() &&
           subroot->GetRightChild() != NULL) {
    return Remove(contents, subroot->GetRightChild());
    // Check if contents is equal to subroot
  } else if (contents == subroot->GetContents()) {
    // Check if subroot has 0 children
    if (subroot->GetLeftChild() == NULL &&
        subroot->GetRightChild() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      return true;
    } else if (subroot->GetLeftChild() == NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetRightChild();
      delete temp;
      size_--;
      return true;
    } else if (subroot->GetRightChild() == NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetLeftChild();
      delete temp;
      size_--;
      return true;
    } else {
      subroot->SetContents(FindMin(subroot->GetRightChild()));
      Remove(subroot->GetContents(), subroot->GetRightChild());
      return true;
    }
  }
  return false;
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

bool BSTree::Remove(int contents) {
  return Remove(contents, root_);
}

int BSTree::FindMin() {
  if (root_ == NULL) {
    return 0;
  }
  return FindMin(root_);
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
