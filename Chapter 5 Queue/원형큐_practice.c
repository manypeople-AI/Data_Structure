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
    q-> front = 0;
    q-> rear = 0;
}

//is_empty
int is_empty(QueueType *q){
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}


//is_full
int is_full(QueueType *q){
    // full인 경우에는 rear가 front보다 1 작음
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
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



//enqueue
void enqueue(QueueType *q, int item){

}

int delqueue(QueueType *q){

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