//순환적 방법
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 탐색이진트리를 위한 node의 구조
typedef struct TreeNode{
    int key;
    struct TreeNode *left, *right;
}TreeNode;

// 순환적인 탐색 방법
TreeNode* search_cycle(TreeNode *node, int key){
    if (node == NULL) return NULL;
    if (node->key>key){
        return search_cycle(node->left, key);
    }
    if (node->key<key){
        return search_cycle(node->right, key);
    }
    if (node->key == key){
        return node;
    }
}

// 반복적인 탐색 방법
TreeNode* search_repeat(TreeNode *node, int key){
    while (node!=NULL){
        if (node->key ==key)
            return node;
        if (node->key > key)
            node = node->left;
        if (node>key < key)
            node = node->right;
    }
    return NULL;
}

// 삽입 연산
TreeNode* insert_node(TreeNode *node, int key){
    if (node ==NULL) return new_node(key);
    if (search_cycle(node, key)==NULL){
        while (node!=NULL){
            if (node->key > key){
                node = node->left;
            }
            if (node->key < key){
                node = node->right;
            }
        }
        return node;
    }
    else{
        printf("Sorry. There is already another node with the same key value.");
    }
}

// 삭제 연산
TreeNode* delete_node(TreeNode *node, int key){

}









