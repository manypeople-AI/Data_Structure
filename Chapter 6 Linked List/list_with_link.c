// node의 정의
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//노드의 구조 정의(not 생성)
typedef struct ListNode
{
    element data; // Data Field
    struct ListNode *link; // link field : 포인터가 들어감
}ListNode;

// 전역 범위에서는 함수호출을 할 수 없음 반드시 어떤 함수이 내부에서 해야함
void list_with_link(void){
    // head pointer
    ListNode *head = NULL;
    // head는 첫번째 노드를 가르키는 주소를 가짐
    //노드의 크기만큼 동적메모리를 할당받음
    //이 동적 메모리가 하나의 노드가 된다 동적메모리 주소를 head에 저장
    head = (ListNode *)malloc(sizeof(ListNode));
    
    head->data = 10;
    head->link = NULL;

    // 두번째 노드의 생성
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p-> data =20;
    p-> link =NULL; // 마지막 NODE니까 NULL

    // 노드의 연결
    head->link = p;

}





