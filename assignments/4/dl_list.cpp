/*
 * Name        : dl_list.cpp
 * Author      : Ptolemy Linden
 * Description : Creating a DLList class that uses a DLNode class
*/

#include "dl_list.h"
#include <sstream>
using std::stringstream;
using std::cerr;
// Constructor
DLList::DLList() {
  size_ = 0;
  head_ = NULL;
  tail_ = NULL;
}

// Destructor
DLList::~DLList() {
  Clear();
}

// -------------------
//      Accessors
// -------------------

// Returns the size of the list
int DLList::GetSize() const {
  return size_;
}

/*
  Returns the integer value of the node at the 
  beginning of the list. const function. Output "List Empty" to 
  standard error output if the list is empty and return 0. 
*/
int DLList::GetFront() const {
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}

/*
  Returns the integer value of the node at the end 
  of the list. const function. Output "List Empty" to standard error 
  output if the list is empty and return 0.
*/
int DLList::GetBack() const {
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}

/*
  Has one parameter, an integer to find. If the value 
  is found, return true, else return false.
*/
bool DLList::Exists(int find) {
  // Checking if list is empty
  if (size_ == 0) {
    return false;
  }

  // Checking if the list is 1 node long
  if (size_ == 1) {
    if (head_->GetContents() == find) {
      return true;
    }
    return false;
  }

  // If the above are false, then the list must be 2+ nodes long
  DLNode* iterator = head_;

  while (iterator != tail_) {
    if (iterator->GetContents() == find) {
      return true;
    }
    iterator = iterator->GetNext();
  }
  // The iterator has landed on tail, this is the final check
  if (iterator->GetContents() == find) {
    return true;
  }
  return false;
}

// -------------------
//      Mutators
// -------------------

/*
  Has one parameter, an integer to add to the 
  list. Creates a DLNode with the contents of the parameter and adds 
  that node to the front of the list. 
*/
void DLList::PushFront(int add) {
  // Instantiating the new node with the add argument
  DLNode* nn = new DLNode(add);

  // Checking if the list is empty
  if (size_ == 0) {
    head_ = nn;
    tail_ = nn;
    size_++;
    return;
  }
  // Otherwise the list is 1+ nodes long
  nn->SetNext(head_);
  head_->SetPrevious(nn);
  head_ = nn;
  size_++;
}

/*
  Has one parameter, an integer to add to the list. 
  Creates a DLNode with the contents of the parameter and adds that 
  node to the end of the list. 
*/
void DLList::PushBack(int add) {
  // Checking if the list is empty
  if (size_ == 0) {
    PushFront(add);
    return;
  }
  // Checking if the list is 1 node long
  if (size_ == 1) {
    DLNode* nn = new DLNode(add);
    nn->SetPrevious(tail_);
    tail_->SetNext(nn);
    tail_ = nn;
    size_++;
    return;
  }
  // If the above are false, then the list is 2+ nodes long
    DLNode* nn = new DLNode(add);
    nn->SetPrevious(tail_);
    tail_->SetNext(nn);
    tail_ = nn;
    size_++;
}

/*
  Removes the first node in the list. Output "List 
  Empty" to standard error output if the list was already empty. 
*/
void DLList::PopFront() {
  // Checking if list is empty
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  }

  // Checking if list is 1 node long
  if (size_ == 1) {
    delete head_;
    head_ = NULL;
    tail_ = NULL;
    size_--;
    return;
  }

  // If the above are false, then the list must be 2+ nodes long
  DLNode* temp = head_->GetNext();
  temp->SetPrevious(NULL);
  delete head_;
  head_ = temp;
  size_--;
}

/*
  Removes the last node in the list. Output "List 
  Empty" to standard error output if the list was already empty. 
*/
void DLList::PopBack() {
  // Check if list is empty
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  }

  // Check if list is 1 node long
  if (size_ == 1) {
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
    size_--;
    return;
  }

  // If the above are false, the list must be 2+ nodes long
  DLNode* temp = tail_;
  tail_ = tail_->GetPrevious();
  tail_->SetNext(NULL);
  delete temp;
  size_--;
}

/*
  Has one parameter, an integer to find. If the 
  value is found, remove that node from the list. Will only remove the 
  first node that matches the value. If the value is not found, output 
  "Not Found" to standard error output. 
*/
void DLList::RemoveFirst(int find) {
  // Check if list is empty
  if (size_ == 0) {
    cerr << "Not Found";
    return;
  }

  // Check if list is 1 node long
  if (size_ == 1) {
    // Check if the node's contents matches find
    if (head_->GetContents() == find) {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      size_ = 0;
      return;
    // The node's contents != find  
    } else {
      cerr << "Not Found";
      return;
    }
  }

  // If the above are false, then the list must be 2+ nodes long
  DLNode* iterator = head_;

  // Iterate through the list until iterator points to NULL
  // or we find "find".
  while (iterator != NULL) {
    if (iterator->GetContents() == find) {
      DLNode* temp = iterator->GetPrevious();
      temp->SetNext(iterator->GetNext());
      delete iterator;
      return;
    }
    // Iterator has reached null, therefore "find" was not found
    cerr << "Not Found";
  }
}

/*
  Has one parameter, an integer to find. If the 
  value is found, remove that node from the list. Will remove all 
  nodes that match the value. If the value is not found, output "Not 
  Found" to standard error output. 
*/
void DLList::RemoveAll(int find) {
  // Checking if list is empty
  if (size_ == 0) {
    cerr << "Not Found";
    return;
  }

  // Checking if list is 1 node long
  if (size_ == 1) {
    if (head_->GetContents() == find) {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      size_--;
      return;
    }
    cerr << "Not Found";
    return;
  }

  // If the above are false, then the list must be 2+ nodes long
  DLNode* iterator = head_;
  // Using this variable to check if any nodes were found.
  // If size_check == size_ after we loop through the list,
  // then that means no nodes were found and we cerr << "Not Found".
  unsigned int size_check = size_;

  while (iterator != NULL) {
    if (iterator->GetContents() == find) {
      DLNode* temp = iterator->GetPrevious();
      temp->SetNext(iterator->GetNext());
      temp = iterator->GetNext();
      temp->SetPrevious(iterator->GetPrevious());
      delete iterator;
      size_--;
    } else {
      iterator = iterator->GetNext();
    }
  }
  // Iterator has reached NULL
  if (size_check == size_) {
    cerr << "Not Found";
  }
}

  /*
    Clears all nodes from the list, resets the size to 0 and 
    head and tail to NULL.
  */
void DLList::Clear() {
  // Creating a temp ptr to use in the while loop
  DLNode* temp;
  while (head_ != NULL) {
    // Point temp to the same node as head_;
    temp = head_;

    // Point head_ to next node in list
    head_ = head_->GetNext();
    // Delete the node temp is pointing to
    delete temp;
  }
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

/*
  Outputs the contents of the list as a 
  comma separated list ("1, 2, 3, etc") starting at the first node and 
  ending at the last node. If the list is empty return the empty string 
  and output "List Empty" to standard error output. 
*/
string DLList::ToStringForwards() {
  // Checking if list is empty
  if (size_ == 0) {
  cerr << "List Empty";
  return "";
  }
  // Checking if list is 1 node long
  if (size_ == 1) {
    stringstream ss;
    ss << head_->GetContents();
    return ss.str();
  }
  // If the above are false, the list must be 2+ nodes long
  stringstream ss;
  DLNode* iterator = head_;

  while (iterator != tail_) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetNext();
  }
  // The iterator has now landed on tail, therefore
  // we do note include << ", ";
  ss << iterator->GetContents();
  return ss.str();
}

/*
  Outputs the contents of the list as a 
  comma separated list ("1, 2, 3, etc") starting at the last node and 
  ending at the first node. If the list is empty return the empty string 
  and output "List Empty" to standard error output.
*/
string DLList::ToStringBackwards() {
  // Check if list is empty
  if (size_ == 0) {
    cerr << "List Empty";
    return "";
  }

  // Instantiating a stringstream object that we have to use
  // when the list isn't empty
  stringstream ss;

  // Check if the list is 1 node long
  if (size_ == 1) {
    ss << head_->GetContents();
    return ss.str();
  }

  // Otherwise, the list is 2+ nodes long
  DLNode* iterator = tail_;

  while (iterator != head_) {
    ss << iterator->GetContents() << ", ";
    iterator = iterator->GetPrevious();
  }
  // Iterator is now pointing to head_
  ss << iterator->GetContents();
  return ss.str();
}
