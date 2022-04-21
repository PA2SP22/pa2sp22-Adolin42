#include <iostream>
#include <string>
#include "todo_item.h"
using std::ostream;
using std::string;

#ifndef LINDEN_ASSIGNMENT_3B
#define LINDEN_ASSIGNMENT_3B

class TodoList {
 private:

  // Private member variables
  TodoItem** list_;
  unsigned int size_;
  unsigned int capacity_;
  
  // Private member functions
  void IncreaseCapacity();
  void Compact(unsigned int location);

 public:
  // Constructor
  TodoList();
  // Destructor
  ~TodoList();
  // Public member Functions
  void AddItem(TodoItem* item);
  void DeleteItem(unsigned int location);
  TodoItem* GetItem(unsigned int location);
  unsigned int GetSize();
  unsigned int GetCapacity();
  void Sort();
  string ToFile();
  friend ostream& operator <<(ostream &out, const TodoList &tdl);
  
  
 
};

#endif