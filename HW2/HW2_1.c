#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* BTree2DLL(Node* root, Node** head)
{
    // root가 null인 경우
    if (root == NULL)
        return root;

    static Node* prev = NULL;
 
    // 왼쪽 하위 트리를 재귀적으로 변환
    BTree2DLL(root->left, head);
 
    // 현재 노드 변환
    if (prev == NULL)
        *head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
 
    //최종적으로 오른쪽 하위 트리 변환
    BTree2DLL(root->right, head);
    return prev;
}

Node* BTree2CDLL(Node* root)
{
    Node* head = NULL;
    Node* tail = BTree2DLL(root, &head);
    // DLL을 CDLL로 변환하도록 변경
    tail->right = head;
    head->left = tail;
   
    return head;
}


void print_node(Node* phead){
    if (phead == NULL)
        return;
    Node* p = phead;
    do{
        printf("<-|%d|-> ",p->data);
        p=p->right;
    }while(p!=phead);
    printf("\n");
}

Node* newNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

int main()
{
    // 완전이진트리 구조 생성

    Node* root = newNode(11);
    root->left = newNode(13);
    root->right = newNode(16);
    root->left->left = newNode(26);
    root->left->right = newNode(31);
    root->right->left = newNode(37);
 
    // 변환
    Node* head = BTree2CDLL(root);
    // 최종 리스트 반환
    print_node(head);
 
    return 0;
}