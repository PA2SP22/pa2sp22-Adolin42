#include <iostream>
#include "todo_list.h"
#include "CinReader.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

#ifndef LINDEN_ASSIGNMENT_3C
#define LINDEN_ASSIGNMENT_3C

class TodoUI {
 public:
  TodoUI();
  ~TodoUI();
  void Menu();

 private:
  CinReader reader_;
  TodoList* list_;
  void CreateItem();
  void EditItem();
  void DeleteItem();
  void ViewAllItems();
  void ViewSpecificItem();
  void DeleteAllItems();
};


#endif
