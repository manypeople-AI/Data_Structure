#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

//       +
//   *        +
//1    4    16     25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, NULL, NULL};
TreeNode n3 = {'*', &n1, &n2};
TreeNode n4 = {16, NULL, NULL};
TreeNode n5 = {25, NULL, NULL};
TreeNode n6 = {'+', &n4 , &n5};
TreeNode n7 = {'+', &n3 , &n6};
TreeNode *root = &n7;

//수식 계산함수
int evaluate(TreeNode *root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL){
        return root->data;        
    }
    else{
        int x = evaluate(root->left);
        int y = evaluate(root->right);
        char op = root->data;
        printf("%d %c %d \n",x,op,y);
        switch (op){
            case '+':
                return x+y;
            case '*':
                return x*y;
            case '/':
                return x/y;
            case '-':
                return x-y;
            }
    }
    return 0;
}

//main 문
int main(void){
    printf("result is %d. \n", evaluate(root));
    return 0;
}
