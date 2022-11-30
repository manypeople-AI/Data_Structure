#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* make_tree(int arr[]){
    //                   arr[0](n4)
    //        arr[1](n3)            arr[2](n6)
    //  arr[3](n1)  arr[4](n2)   arr[5](n5)
    Node n1 = {arr[3], NULL, NULL};
    Node n2 = {arr[4], NULL, NULL};
    Node n3 = {arr[1], &n1, &n2};
    Node n5 = {arr[5], NULL, NULL};
    Node n6 = {arr[2], &n5 ,NULL};
    Node n4 = {arr[0], &n3, &n6};
    Node *root = &n4;

    return root;
}

Node* BTree2DoublyLinkedList(Node* root, Node** head)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all
    // recursive calls
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