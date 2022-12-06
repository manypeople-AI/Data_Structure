#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;


// node 개수 구하기
int get_node_count(TreeNode *node){
    int node_count = 0;
    if(node==NULL) {
        return 0;
        }
    else{
        node_count+=1;
        node_count += get_node_count(node->left);
        node_count += get_node_count(node->right);
    }
    return node_count;
}                                                                                                                                                     

int leaf_count = 0;
// 단말 노드 개수 구하기
int get_leaf_count(TreeNode *node){
    if (node==NULL){
        return 0;        
    }
    else{
        int m = get_leaf_count(node->left);
        int n = get_leaf_count(node->right);
        if (m==0 & n==0){
            leaf_count +=1;
        }
    }
    return leaf_count;
}


// 높이 구하기 왜 안됌????????????????????????????????????
int get_height(TreeNode *node){
    int height = 0;
    if (node!=NULL)
        height = 1 + max(get_height(node->left),get_height(node->right));

    return height;
}


// 예제로 사용할 Tree 하나 생성하기
TreeNode n7 = {200, NULL, NULL};
TreeNode n6 = {200, NULL, NULL};
TreeNode n4 = {500, &n7, NULL};
TreeNode n5 = {200, NULL, NULL};
TreeNode n3 = {100, &n5, &n6};
TreeNode n2 = {50, &n4, NULL};
TreeNode n1 = {3, &n2, &n3};
TreeNode *root = &n1;

int main(void){

    printf("%d\n",get_node_count(root));
    printf("%d\n",get_leaf_count(root));
    printf("%d\n",get_height(root));

    return 0;
}


