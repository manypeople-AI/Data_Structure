#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element;

//노드의 구조 정의(not 생성)
typedef struct ListNode
{
    element data; // Data Field
    struct ListNode *link; // link field : 포인터가 들어감
}ListNode;

//원형 리스트의 처음에 삽입

ListNode* insert_first(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    //head가 null인 경우(head는 마지막을 가리키고 있는데 )
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

ListNode* insert_last(ListNode* head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    //head가 null인 경우(head는 마지막을 가리키고 있는데 )
    if (head == NULL){
        head = node;
        node->link = head; // 원형이기 때문에 NULL이아니라 다시 head를 가리킨다.
    }
    else{
        node->link = head->link; //head->link가 마지막 노드가 가리키고 있는 친구
        head->link = node;
        head=node; // 어차피 같다고 할 건데 위에 link는 왜 따로 설정? 같다는게 뭐가 같다는거임?


        }
    return head;


}




















