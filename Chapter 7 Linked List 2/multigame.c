#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 3명의 플레이어가 보드게임을 한다
// 이때 프로그램을 작성하여서 현재 누구 순서인지를 알리도록 하자.
// 모든 플레이어는 원형 연결리스트에 저장되며 한 플레이어의 기회가 끝나면 포인터를 
// 앞으로 움직여서 다음 플레이어의 순서가 된다. 

typedef char element[100];
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data,data); //주의~
    
    if (head == NULL){
        head = node;
        node->link = head; // 원형이기 때문에 NULL이아니라 다시 head를 가리킨다.
    }
    else{
        node->link = head->link; //head->link가 마지막 노드가 가리키고 있는 친구
        head->link = node;
    }
    return head;
}

int main(void )
{
    ListNode *head = NULL ;
    head = insert_first(head , "KIM" );
    head = insert_first(head , "PARK" );
    head = insert_first (head , "CHOI" );
    ListNode* p = head;
    for (int i = 0; i < 10; i++) {
        printf("%s's turn \n",p->data);
        p = p->link;        
    }
    return 0;
}

























