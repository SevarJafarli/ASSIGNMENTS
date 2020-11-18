#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}


int addNodes(struct Node* iter)
{
  if (iter == NULL)
    return 0;
  return iter->value + addNodes(iter->left) + addNodes(iter->right);
}


int maxSumPath(struct Node* root) {
    if(root==NULL)
        return 0;
    int left = maxSumPath(root->left);
    int right = maxSumPath(root->right);
    if(left > right)
        return left + root->value;
    else
        return right + root->value;
}
int main(){
  struct Node* root = newNode(1);
  root->left = newNode(5);
  root->right = newNode(10);
  root->left->left = newNode(20);
  root->left->right = newNode(4);
  root->left->left->left=newNode(999);
  root->right->right=newNode(20);
  root->right->right->right=newNode(15);
  root->right->left=newNode(21);
  root->right->left=newNode(13);
  printf("Max Sum path of binary tree is %d\n", maxSumPath(root));
  return 0;
}

