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

//is_empty
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
//queue print
void queue_print(QueueType *q){
    printf("Queue (front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)){
        int i=q->front;
        do {
            i = (i+1)%MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i==q->rear){
                break;
            }
        }while (i!=q->front);
    }
    printf("\n");    
}

//is_full
int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}


//enqueue
void enqueue(QueueType *q, int item){
    // 큐는 맨 뒤에 삽입
    if (is_full(q)){
        error("Que is full");
    }
    q->rear= q->rear+1%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int delqueue(QueueType *q){
    if (is_empty(q)){
        error("Que is empty");
    }

    q->front = q->front+1%MAX_QUEUE_SIZE;
    int item = q->data[q->front];

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