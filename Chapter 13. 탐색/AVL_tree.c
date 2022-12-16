#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) (((a) > (b)) ? (a) : (b))

//AVL tree node 정의
typedef struct AVLNode{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
}AVLNode;

// Rotate Right 함수 구현
AVLNode *rotate_right(AVLNode *parent){
    AVLNode* child = parent->left;
    parent->left  = child->right;//원래는 child를 가리키고 있었으므로, null값을 넣어줌        
    child->right = parent;

    return child; // 새 루트를 반환
}   

// Rotate Left 함수 구현
AVLNode *rotate_left(AVLNode *parent){
    AVLNode* child = parent->right;
    parent->right  = child->left;//원래는 child를 가리키고 있었으므로, null값을 넣어줌
    child->left = parent;
    return child; // 새 루트를 반환
}  

// 트리의 높이 계산
int get_height(AVLNode *node){
    int height = 0;

    if(node!=NULL)
        height = max(get_height(node->left),get_height(node->right))+1; // 자신의 자식노드들 중 더 큰높이 +1

    return height;
}

// 노드의 균형인수를 반환
int get_balance(AVLNode *node){

    if (node == NULL) return 0;

    return (get_height(node->left) - get_height(node->right));
}

// 새로운 노드 추가 함수 -> ratation함수를 통해서 트리의 균형을 맞춰줌
AVLNode* insert(AVLNode* node, int key){//key: 추가하고자 하는 값, node : root node

    // 이진 탐색트리의 노드 추가 수행
    if (node == NULL)  
        return(create_node(key)); // 탐색에 실패한 위치가 새로운 노드를 삽입하는 위치
    
    if (key <node->key)
        node = insert(node->left,key);
    else if (key >node->key)
        node = insert(node->right,key);
    else
        return node;

    // 노드들의 균형인수 재계산
    int balance = get_balance(node);

    // LL타입 처리 // 왼쪽으로 쭈루룩 쏠린 불균형 상태
    if (balance>1 && key<node->left->key) // 왼쪽으로 쏠린 불균형 상태가 추가로 인해서 발생했어!
        return rotate_left(node); //parent는 현재 node

    // RR타입 처리
    if (balance<-1 && key>node->right->key)
        return rotate_right(node);

    // LR타입 처리
    if (balance>1 && key>node->left->key)
        {
        node->left = rotate_left(node->left); //회전한 child가 node->left이다
        return rotate_right(node);}  //한번 더 회전

    // RL타입 처리
    if (balance<-1 && key<node->right->key){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}






