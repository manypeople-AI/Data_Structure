#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int calc_dir_size(TreeNode *root){
    if (root==NULL) return 0;
    int x = calc_dir_size(root->left);
    int y = calc_dir_size(root->right);
    int op = root->data;
    return x+y+op;
}

//main
int main(void){
    TreeNode n4 = {500, NULL, NULL};
    TreeNode n5 = {200, NULL, NULL};
    TreeNode n3 = {100, &n4, &n5};
    TreeNode n2 = {50, NULL, NULL};
    TreeNode n1 = {0, &n2, &n3};
    
    printf("Size of Directory = %d\n", calc_dir_size(&n1));
    return 0;
}