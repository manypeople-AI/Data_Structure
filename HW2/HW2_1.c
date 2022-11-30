#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
    }DlistNode;

TreeNode make_tree(int arr[]){
    //                   arr[0](n4)
    //        arr[1](n3)            arr[2](n6)
    //  arr[3](n1)  arr[4](n2)   arr[5](n5)
    TreeNode n1 = {arr[3], NULL, NULL};
    TreeNode n2 = {arr[4], NULL, NULL};
    TreeNode n3 = {arr[1], &n1, &n2};
    TreeNode n5 = {arr[5], NULL, NULL};
    TreeNode n6 = {arr[2], &n5 ,NULL};
    TreeNode n4 = {arr[0], &n3, &n6};
    TreeNode *root = &n4;

    return *root;
}

// 이중 연결리스트 초기화
void init(DlistNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중연결리스트의 노드를 출력
void print_node(DlistNode* phead){
    DlistNode* p;
    for (p=phead->rlink;p!=phead;p=p->rlink){
        printf("<-|  |%d|  |-> ",p->data);
    }
    printf("\n");
}

// 삽입연산
// 새로운 데이터를 노드 before의 오른쪽에 삽입
DlistNode insert(DlistNode *before, element data){
    DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
    newnode->data = data; 
    newnode->llink = before; //1
    newnode->rlink = before->rlink; //2
    before->rlink->llink = newnode; //3
    before->rlink = newnode; //4

    return *newnode;
}

// 중위순회
DlistNode inorder(TreeNode *root, DlistNode *head, DlistNode *before){
    if (root!=NULL){
        inorder(root->left, head);
        if (head->llink==head && head->rlink==head){
            head -> data = root->data;
            before = head;
        }
        else{
            insert(before, root->data);
        }
        inorder(root->right, before);
        before = insert(before, root->data);

        return before;
    }
    else return;
}

//원형 이중연결리스트
DlistNode make_linked_list(TreeNode *root){
    DlistNode *before = (DlistNode*)malloc(sizeof(DlistNode));
    DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head); // 초기화
    
    before = head;
    before = inorder(root->left, head, before);
    inorder(root->right, head, before);
}

int main(void){

    // 사용자에게 배열로 사용할 숫자 받기
	int num[6]; // 6개의 node를 가짐
	int x; //입력될 반복문에 사용할 변수
    printf("Enter the number in the order in which you want to create a complete binary tree. \n");
	for (x = 0; x <= 5; x++)
	{
		printf("Round %d = ", x+1); 
		scanf("%d", &num[x]);
	}
    printf("Input array is ["); // input array 출력
    for (x = 0; x<=5; x++)
        printf(" %d ", num[x]);
    printf("]\n");
    // 받기 완료
    // 받은 array로 Tree 함수 생성
    TreeNode root = make_tree(num[6]);
    make_linked_list(&root);
   
    return 0;
}
