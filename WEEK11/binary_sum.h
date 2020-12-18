#ifndef DYN_STACK
#define DYN_STACK

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value);
int maxSumPath(struct Node* root);
#endif
