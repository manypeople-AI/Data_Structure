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

//리스트의 항목 출력
void print_list(ListNode* head){
    ListNode* check_point;
    if (head == NULL){
        return; // return 뒤에 아무것도 안쓰는거 무슨 의미?
    }
    else{
        check_point = head->link; // 형식상 첫번째 node
        for (;check_point!=head;check_point = check_point -> link)  // while문으로 짜는 법 생각해보기
            printf("%d -> ", check_point->data); // 조건이 참이면 반복
        printf("%d \n", head->data);
    }
}

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
        // 데이터가 같다는거임?
        }
    return head;
}

//test program

int main(void)
{
    ListNode* head = NULL;

    // list = 10->20->30->40
    head = insert_last(head , 20);
    print_list(head);
    head = insert_last(head , 30);
    print_list(head);
    head = insert_last(head, 40);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}