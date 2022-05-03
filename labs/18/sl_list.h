#ifndef SLList_H
#define SLList_H
#include "sl_node.h"
#include <cstddef>
#include <string>
#include <iostream>
#include <sstream>
using std::stringstream;
using std::string;

class SLList {
 private:
  SLNode* head_;
  unsigned int size_;

 public:
  // Constructor
  SLList();
  // Destructor
  ~SLList();

  /*
    Create a new dynamic SLNode with the contents of 
	  the parameter and attach as head of list
  */
  void InsertHead(int contents);

  /*
    Remove the head node from the list, or does nothing
    if the list is empty.
  */
  void RemoveHead();

  /*
    Clear the entire contents of the list, freeing all memory
    associated with all nodes.
  */
  void Clear();

  /*
    Return the size of the list
  */
  unsigned int size() const;

  /*
    Return a string representation of the contents of all nodes
    in the list, in the format NUM1, NUM2, ..., LASTNUM
    Return empty string on empty list
  */
  string ToString() const;
};

#endif
