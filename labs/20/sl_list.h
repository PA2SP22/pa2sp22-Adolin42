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
  SLNode* tail_;
  unsigned int size_;

  /*
    Create a new dynamic SLNode with the contents of 
	  the parameter and attach as head of list
  */
  void InsertHead(int contents);

  /*
    Create a new dynamic SLNode with the contents of
    the integer parameter and attach as the tail of the list
  */
  void InsertTail(int contents);
  /*
    Remove the head node from the list, or does nothing
    if the list is empty.
  */
  void RemoveHead();

  /*
    Remove the tial node from the list. Does nothing if the
    list is empty
  */
  void RemoveTail();

 public:
  // Constructor
  SLList();
  // Destructor
  ~SLList();

  /*
    Creates a new SLNode with the contents of the parameter and
	  inserts it into the correct position in the list. The list
    will be sorted with the lowest values in the front and the
		largest values in the back.
  */
  void Insert(int contents);

  /*
    Remove the first occurence of the supplied parameter
    found as the data in a node. Return true on successful
    removal or false if the list is empty of if the value
    is not found/removed
  */
  bool RemoveFirstOccurence(int contents);

  /*
    Returns the contents of the head node
    (The node the head is pointing to)
  */
  int GetHead() const;

  /*
    Returns the contents of the tail node
    (The node the tail is pointing to)
  */
  int GetTail() const;
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
