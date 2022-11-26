// 반복적인 중위 순회
// 스택을 이용해서 구현

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

//push
void push(TreeNode *p){ //스택에 push할 놈
    if (top < SIZE-1){ // 스택이 꽉 찼을 때를 제외하고
        stack[++top] = p;
    }
} 

//pop
TreeNode *pop(){ //인자를 안받음 stack을 전역 변수로 선언해서?
    TreeNode *p =NULL;
    if (top >=0) //인자가 있다면 
        p = stack[top--]; //p에 맨 위의 인자를 넣고 top을 -1시킴
    return p;
}


//inorder_iter
void inorder_iter(TreeNode *root){
    while(1){
        for(;root;root=root->left)
            push(root);
        root = pop();
        if(!root) break; // pop 했는데 아무것도 없으면 break 즉 root가 null이면!
        printf(" [%d] ", root->data);
        root = root->right;
    }
}
//    15
//  4    20
//1     16 25
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2 , &n5};
TreeNode *root = &n6;

//main
int main(void){
    printf("inorder = ");
    inorder_iter(root);
    printf("\n");
    return 0;
}
