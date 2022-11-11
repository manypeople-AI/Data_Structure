#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
    }DlistNode;

// 초기화함수
// 이중연결리스트는 head node가 존재하므로 head pointer가 따로 필요없다
// 반드시 초기화하고 사용해야함
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
void dinsert(DlistNode *before, element data){
    DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
    newnode->data = data; 
    newnode->llink = before; //1
    newnode->rlink = before->rlink; //2
    before->rlink->llink = newnode; //3
    before->rlink = newnode; //4
}

// 삭제연산 removed node를 삭제
void ddelete(DlistNode *head, DlistNode *removed){
    if (removed==head) return; // head node를 삭제하면 안된다
    removed->llink->rlink = removed -> rlink;
    removed->rlink->llink = removed -> llink;
    free(removed);
}

int main(void){
    DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head); //초기화
    printf("추가 단계\n");
    for (int i=0;i<5;i++){
        dinsert(head,i);
        print_node(head);
    }
    printf("\n삭제단계\n");
    for (int i=0;i<5;i++){
        print_node(head);
        ddelete(head,head->rlink);
    }
    free(head);
    return 0;
    
}












