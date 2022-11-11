#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
    }DlistNode;

DlistNode *current;
// 초기화함수
void init(DlistNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중연결리스트의 노드를 출력
void print_node(DlistNode* phead){
    DlistNode* p;
    for (p=phead->rlink;p!=phead;p=p->rlink){
        if (p==current){
            printf("<-| | #%s# | |-> ",p->data);
        }
        else 
            printf("<-| |%s| |-> ",p->data);
    }
    printf("\n");
}

// 삽입연산
// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DlistNode *before, element data){
    DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
    strcpy(newnode->data, data); 
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


// main 문
int main(void){ 

    char ch;
    DlistNode* head = (DlistNode *)malloc(sizeof(DlistNode));
    init(head);

    dinsert(head, "NXDE / IDLE");
    dinsert(head, "Antifragile / RESSERAFIM");
    dinsert(head, "Savage / AESPA");

    current = head->rlink;
    print_node(head); // mp3에 어떤 곡들이 있는지 표시

    do{
        printf("\n Enter the sign (<, > , q) : ");
        ch = getchar(); // input으로 char를 받기
        if (ch == '<'){
            current = current -> llink;
            if (current == head) // 맨 첫번째 곡일때 <-를 누르면 맨 끝곡으로
                current = current ->llink;
        }
        else if (ch =='>'){
            current = current -> rlink;
            if(current == head)
                current = current -> rlink; //맨끝곡일때 ->를 누르면 첫번째 곡으로
        }
        print_node(head);
        getchar(); //다시 받음
    }while(ch !='q');
    free(head);
    return 0;
    }