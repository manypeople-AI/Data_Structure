#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{ // 연결리스트 구조체
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct //큐 구조체
{
    QueueNode *front, *rear;
}LinkedStackType;

// 큐 초기화 함수 (front와 rear모두 0)
void init(LinkedStackType *q){
    q->front = q->rear =0;
}

// 공백상태 검출 함수

int is_empty(LinkedStackType *q){
    return(q->front==NULL);
}

// 포화 상태 검출 함수 -> 연결리스트로 구현하면 포화되지 않음?
int is_full(LinkedStackType *q){
    return 0;
}

// 삽입 함수 
void enqueue(LinkedStackType *q, element item){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp -> data = item;
    temp -> link = NULL; // 마지막인애가 가르키는건 NULL(없음)
    if (is_empty(q)){ // 큐가 공백이면 참 이니까 1 반환 if 안에 1이면 실행
        q->front = q->rear = temp;
    }
    else{
        q->rear->link = temp;
        q->rear = temp;
    }
}

// 삭제 함수

element dequeue(LinkedStackType *q){
    QueueNode *temp = q->front;
    element data;
    if (is_empty(q)){
        fprintf(stderr,"Queue is empty");
        exit(1);
    }
    else{
        data = temp->data;
        q->front = temp-> link;
        if (q->front ==NULL)//요소가 딱 1개 있었던 것이라면
            q->rear == NULL; // 비어있는 큐
        free(temp);
        return data;
    }
}

// 큐 프린트 함수
void print_queue(LinkedStackType *q){
    for (QueueNode *p = q->front;p!=NULL;p=p->link){
        printf("%d <-", p->data);
    }
    printf("NULL\n");
}


// main 문
int main(void){
    LinkedStackType queue;
    init(&queue);
    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    return 0;
    
}