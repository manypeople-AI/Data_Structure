#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* BTree2DoublyLinkedList(Node* root, Node** head)
{
    // Base case
    if (root == NULL)
        return root;

    static Node* prev = NULL;
 
    // Recursively convert left subtree
    BTree2DoublyLinkedList(root->left, head);
 
    // Now convert this node
    if (prev == NULL)
        *head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
 
    // Finally convert right subtree
    BTree2DoublyLinkedList(root->right, head);
    return prev;
}

Node* BTree2CircularDoublyLinkedList(Node* root)
{
    Node* head = NULL;
    Node* tail = BTree2DoublyLinkedList(root, &head);
    // make the changes to convert a DLL to CDLL
    tail->right = head;
    head->left = tail;
    // return the head of the created CDLL
    return head;
}


void print_node(Node* phead){
    if (phead == NULL)
        return;
    Node* p = phead;
    do{
        printf("<-|  |%d|  |-> ",p->data);
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
    // Let us create the tree shown in above diagram
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    
    // Convert to DLL
    Node* head = BTree2CircularDoublyLinkedList(root);
    // Print the converted list
    print_node(head);
 
    return 0;
}