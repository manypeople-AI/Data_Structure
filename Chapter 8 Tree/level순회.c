// 레벨 순회는 Queue를 사용함

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

// 원형 큐 코드 시작
#define MAX_QUEUE_SIZE 100
typedef TreeNode * element; // 큐에 들어가는 형태가 node의 형태가 된다
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType; // 큐타입

//오류 함수
void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

// 큐 초기화 함수

void init_queue(QueueType *q){
    q -> rear = 0;
    q -> front = 0;
}
// 공백상태 검출함수
int is_empty(QueueType *q){
    return (q->front == q->rear); //front와 rear가 같으면 empty
}
// 포화 상태 검출함수
int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
//enqueue
void enqueue(QueueType *q, element item){
    // 큐는 맨 뒤에 삽입
    if (is_full(q)){
        error("Que is full");
    }
    q->rear= q->rear+1%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//delqueue
element delqueue(QueueType *q){
    if (is_empty(q)){
        error("Que is empty");
    }
    q->front = q->front+1%MAX_QUEUE_SIZE;
    element item = q->data[q->front];
    return item; 
}
//level_order
void level_order(TreeNode *root){
    QueueType q; // 큐 정의하기
    init_queue(&q);
    if (root == NULL) return; //root 가 null인 경우
    enqueue(&q,root);
    for(;root;){
        root = delqueue(&q);
        printf("[%d] ",root->data);
        if (root->left)
            enqueue(&q,root->left);
        if (root->right)
            enqueue(&q,root->right);
    }
}

// 트리 구성
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

// main 문
//main
int main(void){
    printf("level order = ");
    level_order(root);
    printf("\n");
    return 0;
}

