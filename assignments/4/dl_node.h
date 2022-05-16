#ifndef DLNode_H
#define DLNode_H
#include <cstddef>

class DLNode {
 public:
  // Constructor
  DLNode(int contents = 0);
  // Destructor
  ~DLNode();
  // Mutators
  void SetContents(int contents);
  void SetNext(DLNode* next);
  void SetPrevious(DLNode* previous);
  // Accessors
  int GetContents() const;
  DLNode* GetNext() const;
  DLNode* GetPrevious() const;


 private:
  int contents_;
  DLNode* previous_;
  DLNode* next_;
};

#endif
