/*
 * Name        : sl_list.cpp
 * Author      : Ptolemy Linden
 * Description : Creating an SLList class that uses the SLNode class
*/

#include "sl_list.h"

// Constructor
SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}
// Destructor
SLList::~SLList() {
  Clear();
}

/*
  Create a new dynamic SLNode with the contents of 
	the parameter and attach as head of list
*/
void SLList::InsertHead(int contents) {
  // Initializing the new node with contents parameter
  SLNode* new_node = new SLNode(contents);
  // If the list is empty, we make head_ point to the new node
  if (head_ == NULL) {
  head_ = new_node;
  // Otherwise the list must contain at least 1 node, so we do this instead
  } else {
    // Make sure the new node points to where head_ is pointing to
    new_node->set_next_node(head_);
    // Point head_ to the new_node
    head_ = new_node;
  }
  // Increment the size of the list since we've added a node
  size_++;
}

/*
  Remove the head node from the list, or does nothing
  if the list is empty.
*/
void SLList::RemoveHead() {
  // If the size_ of the list is greater than 0
  if (head_ != NULL) {
    SLNode* temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_--;
  }
}

/*
  Clear the entire contents of the list, freeing all memory
  associated with all nodes.
*/
void SLList::Clear() {
  // Creating a temp ptr to use in the while loop
  SLNode* temp;
  while (head_ != NULL) {
    // Point temp to the same node as head_;
    temp = head_;

    // Point head_ to next node in list
    head_ = head_->next_node();
    // Delete the node temp is pointing to
    delete temp;
    // Decrement the size_ of the list
    size_--;
  }
  head_ = NULL;
}

/*
  Returns the size of the list
*/

unsigned int SLList::size() const {
  return size_;
}

/*
  Return a string representation of the contents of all nodes
  in the list, in the format NUM1, NUM2, ..., LASTNUM
  Return empty string on empty list
*/
string SLList::ToString() const {
  if (head_ == NULL) {
    return "";
  }

  stringstream ss;
  SLNode* iterator = head_;

  while (iterator != NULL) {
    if (iterator->next_node() == NULL) {
      ss << iterator->contents();
    } else {
      ss << iterator->contents() << ", ";
    }
    iterator = iterator->next_node();
  }
  return ss.str();
}
