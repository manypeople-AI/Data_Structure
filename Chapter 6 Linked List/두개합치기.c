#include <stdio.h>
#include <stdlib.h>

typedef int element;

//노드의 구조 정의(not 생성)
typedef struct ListNode
{
    element data; // Data Field
    struct ListNode *link; // link field : 포인터가 들어감
}ListNode;

// ListNode *p = NULL; //현재 아무것도 가리키고 있지 않은 상태
// p = (ListNode *)malloc(sizeof(ListNode)); //
ListNode* insert_first(ListNode *head, element value){ // head는 헤드포인터, value는 새롭게 추가되는 데이터 
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //새로 추가되는 데이터 이제 p 포인터가 얘를 가리켜야함
    p->data = value;
    p->link = head; // p 포인터의 값을 복사
    //head가 p를 가리키도록 함 head는 그냥 포인터임(값 x)
    head=p; //헤드포인터 변경
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p-> link = pre->link;
    
    pre->link = p; //p라는 struct를 가리킴
        
    return head;

}

//첫번째 노드 삭제 함수
ListNode* delete_first(ListNode *head){
    if (head == NULL) return NULL;
    ListNode* removed = head;
    head = removed->link;
    free(removed);
    return head;
}

//중간의 노드 삭제 함수

ListNode* delete(ListNode *head, ListNode *pre){
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;

}
//print_list 함수

void print_list(ListNode* head){
    for (ListNode* p=head;p!=NULL;p = p->link){
        printf("%d -> ",p->data);
    }
    printf("NULL \n");
    
}

ListNode* concat_list(ListNode* head1, ListNode* head2){
    ListNode* p;
    for (p=head1;p->link!=NULL;p = p->link){
        // p가 가리키는애가 null이 아니면됨      
    }
    p->link = head2;

    return head1;

}

int main (void){
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1,10);
    head1 = insert_first(head1,20);
    head1 = insert_first(head1,30);
    print_list(head1);

    head2 = insert_first(head2,40);
    head2 = insert_first(head2,50);
    print_list(head2);

    ListNode *total = concat_list(head1,head2);
    print_list(total);

    return 0;

}
