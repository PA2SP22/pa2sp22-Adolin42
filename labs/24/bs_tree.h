#ifndef BSTREE_H
#define BSTREE_H
#include <cstddef>
#include "bst_node.h"
#include <string>
using std::string;

class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int contents);
  void Clear();
  unsigned int GetSize() const;
  string InOrder();

 private:
  BSTNode* root_;
  unsigned int size_;

  bool Insert(int contents, BSTNode*& subroot);
  void Clear(BSTNode*& subroot);
  string InOrder(BSTNode* subroot);
};

#endif
