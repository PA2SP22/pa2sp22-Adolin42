#ifndef BSTNode_H
#define BSTNode_H
#include <cstddef>

class BSTNode {
 public:
  BSTNode();
  BSTNode(int contents);
  ~BSTNode();
  void SetContents(int contents);
  void SetLeftChild(BSTNode* left_child);
  void SetRightChild(BSTNode* right_child);
  int GetContents() const;
  int& GetContents();
  BSTNode* GetLeftChild() const;
  BSTNode* GetRightChild() const;
  BSTNode*& GetLeftChild();
  BSTNode*& GetRightChild();

 private:
  BSTNode* left_child_;
  BSTNode* right_child_;
  int contents_;
};

#endif
