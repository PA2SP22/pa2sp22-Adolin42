#ifndef BSTREE_H
#define BSTREE_H
#include <cstddef>
#include <sstream>
#include <string>
#include "bst_node.h"
using std::string;
using std::stringstream;

class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int contents);
  bool Remove(int contents);
  int FindMin();
  void Clear();
  unsigned int GetSize() const;
  string InOrder();

 private:
  BSTNode* root_;
  unsigned int size_;

  bool Remove(int contents, BSTNode*& subroot);
  int FindMin(BSTNode* subroot);
  bool Insert(int contents, BSTNode*& subroot);
  void Clear(BSTNode*& subroot);
  string InOrder(BSTNode* subroot);
};

#endif
