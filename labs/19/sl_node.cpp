/*
 * Name        : lab_19.cpp
 * Author      : Ptolemy Linden
 * Description : Creating an SLNode class
 */

#include "sl_node.h"

SLNode::SLNode(int contents) {
  next_node_ = NULL;
  contents_ = contents;
}

SLNode::~SLNode() {}

void SLNode::set_contents(int contents) {
  contents_ = contents;
}

void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}

int SLNode::contents() const {
  return contents_;
}

SLNode* SLNode::next_node() const {
  return next_node_;
}
