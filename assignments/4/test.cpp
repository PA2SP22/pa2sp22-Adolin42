#include "dl_list.h"
using std::cerr;

void DLList::RemoveFirst(int find) {
  // Check if list is empty
  if (head_ == NULL) {
    cerr << "List Empty";
    return;
  }

  // Check if size of list = 1
  if (size_ == 1) {
    // Check if head's contents == find. If so, delete head
    if (head_->GetContents() == find) {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      size_--;
      return;
    } else {
      cerr << "Not Found";
      return;
    }

  // If all of the above are false, then the list must be 2+ nodes long
  // Note that we don't have to iterate through the entire list,
  // we only have to iterate until we find the first node that == find.
  // Therefore, we can do while (iterator->GetContents() != find)
  // as opposed to while (iterator != tail_) which would cause
  // iterator to travel through the entire list, wasting time.
    DLNode* iterator = head_;

    while (iterator->GetContents() != find) {
      iterator = iterator->GetNext();

      if (iterator->GetContents() == find) {
        DLNode* temp = iterator->GetPrevious();
        temp->SetNext(iterator->GetNext());
        delete iterator;
        size_--;
      }
    }
  }
}
