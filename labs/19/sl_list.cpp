/*
 * Name        : lab_19.cpp
 * Author      : Ptolemy Linden
 * Description : Creating an SLList class that uses the SLNode class
*/

#include "sl_list.h"

// Constructor
SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
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
  SLNode* nn = new SLNode(contents);
  size_++;
  // Check if list is empty
  if (head_ == NULL) {
    head_ = nn;
    tail_ = nn;
    return;
  }
  // Otherwise the list has at least 1 node
  nn->set_next_node(head_);
  head_ = nn;
}

/*
    Create a new dynamic SLNode with the contents of
    the integer paramter and attach as the tail of the list
  */
void SLList::InsertTail(int contents) {
  // Check if list is empty
  if (head_ == NULL) {
    InsertHead(contents);
  } else {
    // Otherwise the list has at least 1 node
    SLNode* nn = new SLNode(contents);
    tail_->set_next_node(nn);
    tail_ = nn;
    size_++;
  }
}

  /*
    Remove the tail node from the list.
    Does nothing if the list is empty
  */
void SLList::RemoveTail() {
  // Check if size of list == 1
  if (size_ == 1) {
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
    size_--;

  // Otherwise the size of the list is either empty,
  // in which case we do nothing, or it's > 1.
  }

  if (size_ > 1) {
    SLNode* iterator = head_;

    while (iterator->next_node() != tail_) {
      iterator = iterator->next_node();
    }

    iterator->set_next_node(NULL);
    delete tail_;
    tail_ = iterator;
    size_--;
  }
}

/*
  Remove the head node from the list, or does nothing
  if the list is empty.
*/
void SLList::RemoveHead() {
  // I don't think this code is necessary but just in case there's some
  // nonsense going on I'm throwing this error-checking in here
  if (head_ == NULL) {
    tail_ = NULL;
    return;
  }

  // If the size_ of the list is greater than 0
  if (size_ > 0) {
    SLNode* temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_--;
  }
}

/*
  Returns the contents of the head node
  (The node the head is pointing to)
*/
int SLList::GetHead() const {
  if (size_ != 0) {
    return head_->contents();
  }
  return 0;
}

/*
  Returns the contents of the tail node
  (The node the tail is pointing to)
*/
int SLList::GetTail() const {
  if (size_ != 0) {
    return tail_->contents();
  }
  return 0;
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
  }
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
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

  } else {
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
}
