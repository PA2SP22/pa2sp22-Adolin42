#ifndef DLList_H
#define DLList_H
#include <cstddef>
#include <iostream>
#include "dl_node.h"
using std::string;

class DLList {
 public:
  // Constructor
  DLList();
  // Destructor
  ~DLList();
  // Mutators
  void PushFront(int add);
  void PushBack(int add);
  void PopFront();
  void PopBack();
  void RemoveFirst(int find);
  void RemoveAll(int find);
  void Clear();
  // Accessors
  int GetSize() const;
  int GetFront() const;
  int GetBack() const;
  bool Exists(int find);
  // Output List
  string ToStringForwards();
  string ToStringBackwards();

 private:
  unsigned int size_;
  DLNode* head_;
  DLNode* tail_;
};


#endif
