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
    q -> rear = 0;
    q -> front = 0;
}

//queue print
void queue_print(QueueType *q){
    int i=q->front;
    while(i<=q->rear){
        if (i == MAX_QUEUE_SIZE){
            i=0;
            printf("%d | " ,q->data[i]);
            i++;}
        else{   
            printf("%d | ",q->data[i]);
            i++;
        }
    }
    printf("\n");

}

//is_full
int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

//is_empty
int is_empty(QueueType *q){
    return (q->front == q->rear);
}

//enqueue

void enqueue(QueueType *q, int item){
    // 큐는 맨 뒤에 삽입
    if (is_full(q)) {
        error("queue is full");
        return;}
    else{
        if (q->rear == MAX_QUEUE_SIZE-1){
            q->data[0] = item;
            q->rear = 0;
        }
        else{
            q-> data[q->rear+1] = item;
            q-> rear++;
        }
    }
}

int delqueue(QueueType *q){
    int item;
    if (is_empty(q)) {
        error("queue is empty");
        return -1;}
    else{
        if (q->front == MAX_QUEUE_SIZE){
            item= q-> data[0];
            q->front = 0;} // 맨 앞에 있는 데이터 빼주기 front 는 맨앞에 있는 데이터가 아니고 그 전임.
        else{
            item= q-> data[++(q->front)];
            q->front++;}}

    return item;
    
}

int main(void){
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--Add progress--\n") ;
    while (!is_full(&queue)){
        printf("Enter the num: ");
        scanf("%d" , &element);
        printf("pass");
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("Que is full\n\n");

    printf("--Delete progress--\n");
    while (!is_empty (&queue)){
        element = delqueue(&queue);
        queue_print(&queue);

    }
    printf("Que is empty. \n");
    return 0;

}