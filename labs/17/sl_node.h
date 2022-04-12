#ifndef SLNode_H
#define SLNode_H
#include <cstddef>

class SLNode {
 private:
  SLNode* next_node_;
  int contents_;
 public:
  // Constructor
  SLNode(int contents_ = 0);
  // Empty Destructor
  ~SLNode();
  // Mutators
  void set_contents(int contents);
  void set_next_node(SLNode* next_node);
  // Accessors
  int contents() const;
  SLNode* next_node() const;
};

#endif
