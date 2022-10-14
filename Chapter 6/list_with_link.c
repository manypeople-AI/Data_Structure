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

ListNode *head = NULL;
//노드의 크기만큼 동적메모리를 할당받음
//이 동적 메모리가 하나의 노드가 된다 동적메모리 주소를 head에 저장
head = (ListNode *)malloc(sizeof(ListNode));

head->data = 10;
head->link = NULL;
