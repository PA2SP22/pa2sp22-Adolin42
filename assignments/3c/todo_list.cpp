#include "todo_list.h"
using std::endl;

// Private member functions

  /*
    Increases the capacity of the array by 10. Should be called by 
  AddItem at the appropriate time. 
  */
  void TodoList::IncreaseCapacity() {
    capacity_ += 10;

    TodoItem** temp_array = new TodoItem*[capacity_];

    for (unsigned int i = 0; i < capacity_; i++) {
      temp_array[i] = NULL;
    }

    for (unsigned int i = 0; i < size_; i++) {
      temp_array[i] = list_[i];
    }
    delete[] list_;
    list_ = temp_array;
  }

  /*
    Compacts the array to get rid of an empty spot in the array. Should 
  be called by DeleteItem at the appropriate time.
  */
  void TodoList::Compact(unsigned int location) {
    for (unsigned int i = location - 1; i < size_; i++) {
      list_[i] = list_[i + 1];
    }
  }

// Public member functions


  /*
    CONSTRUCTOR
    Creates a dynamic array of 25 elements and initializes the elements 
  to NULL 
  */
  TodoList::TodoList() {
    size_ = 0;
    capacity_ = 25;
    list_  = new TodoItem*[capacity_];

    for (unsigned int i = 0; i < capacity_; i++) {
      list_[i] = NULL;
    }
  }

  /*
    DESTRUCTOR
  Frees the memory for all TodoItems 
  Frees the memory for the dynamic TodoItem* array 
  */

  TodoList::~TodoList() {
    for (unsigned int i = 0; i < size_; i++) {
      delete list_[i];
    }
    delete[] list_;
  }

  /*
  Has one parameter, a dynamic instance of 
  TodoItem (i.e. TodoItem*). If there is room in the array add the new 
  dynamic instance to the first available spot (i.e. the current size). If 
  the array is full, increase capacity by 10 and then add the item. 
  */
  void TodoList::AddItem(TodoItem* item) {
    if (size_ == capacity_) {
      IncreaseCapacity();
      list_[size_] = item;
    } else {
      list_[size_] = item;
    }
    size_++;
  }

  /*
    Has one parameter, an integer of the location 
  to delete. Please note the location is in human-readable form, i.e. 
  location 1 is really array index 0. After you delete the item you will 
  need to pack your array (shift all items "down" so there are no 
  empty slots between items). 
  */
  void TodoList::DeleteItem(unsigned int location) {
    if (location > 0 || location <= size_) {
      delete list_[location - 1];
      list_[location - 1] = NULL;
      size_--;

      Compact(location);
    }
  }

  /*
    Named GetItem. Has one parameter, an integer of the location to 
  retrieve the TodoItem. Please note the location is in human-
  readable form, i.e. location 1 is really array index 0. This function 
  will return a pointer to the TodoItem requested. If that location 
  doesn't exist it returns NULL.
  */
  TodoItem* TodoList::GetItem(unsigned int location) {
    if (location < 1 || location > size_) {
      return NULL;
    }
      TodoItem* item = list_[location - 1];
      return item;
  }

  /*
    Returns an unsigned integer containing the 
  current size of the list (number of items present).
  */
  unsigned int TodoList::GetSize() {
    return size_;
  }

  /*
    Returns an unsigned integer containing the 
  current maximum capacity of the list (number of slots). 
  */
  unsigned int TodoList::GetCapacity() {
    return capacity_;
  }

  /*
    Sorts the array by the priorities of the items. (1 is 
  highest priority, 5 is lowest). 
  */
  void TodoList::Sort() {
    for (int i = size_ - 1; i >= 1; i--) {
      for (unsigned int j = 0; j < size_- 1; j++) {
        if (list_[j]->priority() > list_[j + 1]->priority()) {
          TodoItem* swap = list_[j];
          list_[j] = list_[j + 1];
          list_[j + 1] = swap;
        }
      }
    }
  }

  /*
    Returns a string containing all TodoItems in the list. 
  Uses the TodoItems ToFile function to create. Each item should be 
  on its own line. 
  */
  string TodoList::ToFile() {
    stringstream ss;

    for (unsigned int i = 0; i < size_; i++) {
      ss << list_[i]->ToFile() << endl;
    }
    return ss.str();
  }

  ostream& operator <<(ostream &out, const TodoList &tdl) {
    // out << c.cents_;
    // Return the ostream object to allow for chaining of <<
    for (unsigned int i = 0; i < tdl.size_; i++) {
      out << endl;
      out << "Item #" << i + 1 << endl;
      out << "Description: " << tdl.list_[i]->description() << endl;
      out << "Priority: " << tdl.list_[i]->priority() << endl;

      if (tdl.list_[i]->completed() == true) {
        out << "Completed: Yes" << endl;
      } else {
        out << "Completed: No" << endl;
      }
    }
    return out;
  }
