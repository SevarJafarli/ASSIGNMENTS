#include <stdio.h>
#include <stdlib.h>
#include "binary_sum.h"

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

