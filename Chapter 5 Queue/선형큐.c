#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType; // 큐타입

//오류 함수
void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//init_queue 큐 초기화
void init_queue(QueueType *q){
    q -> rear = -1;
    q -> front = -1;
}

//queue print
void queue_print(QueueType *q){
    for (int i=0; i<MAX_QUEUE_SIZE;i++){ // 전체 빈 공간 다 출력
        if (i<q->front || i>q->rear)
            printf("  | ");
        else
            printf("%d | " ,q->data[i]);
    }
    printf("\n");
}

//is_full
int is_full(QueueType *q){
    if (q->rear == MAX_QUEUE_SIZE-1)
        return 1;
    else
        return 0;
}

//is_empty
int is_empty(QueueType *q){
    if (q->front == q->rear)
        return 1;
    else 
        return 0;
}

//enqueue

void enqueue(QueueType *q, int item){
    // 큐는 맨 뒤에 삽입
    if (is_full(q)) {
        error("queue is full");
        return;}
    else{
        q-> data[q->rear+1] = item;
        q-> rear++;
    }
}

int delqueue(QueueType *q){
    if (is_empty(q)) {
        error("queue is empty");
        return -1;}
    else{
        int a = q-> data[++(q->front)]; // 맨 앞에 있는 데이터 빼주기 front 는 맨앞에 있는 데이터가 아니고 그 전임.
        q->front++;
        return a;
    }
}

int main(void){
    int item = 0;
    QueueType q;
    
    init_queue(&q);

    enqueue(&q,10);queue_print(&q);
    enqueue(&q,20);queue_print(&q);
    enqueue(&q,30);queue_print(&q);

    item = delqueue(&q);queue_print(&q);
    item = delqueue(&q);queue_print(&q);
    item = delqueue(&q);queue_print(&q);
    return 0;   
}




