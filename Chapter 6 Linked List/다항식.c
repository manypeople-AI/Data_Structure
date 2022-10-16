#include <stdio.h>
#include <stdlib.h>

//노드의 구조 정의(not 생성)
typedef struct ListNode
{
    int coef;// Data Field
    int expon;
    struct ListNode *link; // 메모리할당 전, 자기를 가리키는 개념이 아님. 그냥 선언만한 상태. 뭘가리키는지는 몰라  
}ListNode;

// 연결 리스트 헤더
typedef struct ListType{//리스트 헤더 타입
    int size; // 그 안에 노드의 개수
    ListNode* head;
    ListNode* tail;
}ListType;

// 오류 함수
void error(char *message){
    fprintf(stderr, "%s\n",message);
    exit(1);
}

// 리스트 헤더 생성함수
ListType* create(){
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size =0;
    plist->head =plist->tail = NULL;
    return plist;
}

// insert_last
void insert_last(ListType* plist, int coef, int expon){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp==NULL) error("memmory allocation error");
    temp->coef = coef;
    temp->expon = expon;
    temp->link =NULL; //!!
    if (plist->tail == NULL){
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType* plist1,ListType* plist2, ListType* plist3){

    ListNode* a = plist1->head;
    ListNode* b = plist2->head;

    int sum;

    while(a != NULL && b!=NULL){ 
        if (a->expon>b->expon){
            insert_last(plist3, a->coef, a->expon);
            a = a->link;

            }
        else if(a->expon == b->expon){
            sum = a->coef+b->coef;
            if (sum!=0){
                insert_last(plist3, a->coef + b->coef, a->expon);}
            a = a->link;
            b = b->link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b = b->link;}
        }// while문 빠져나옴
    

    for (;a!=NULL;a = a->link){
        insert_last(plist3, a->coef, a->expon);
    }
    for (;b!=NULL;b =b->link){
        insert_last(plist3,b->coef,b->expon);
    }

    }  

void poly_print(ListType* plist){
    ListNode *p = plist->head;
    printf("polynomial = ");
    for (;p;p=p->link){
        printf("%d^%d + ",p->coef,p->expon);
    }
    printf("\n");
}

int main(void){
    ListType *list1,*list2,*list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1,3,12);
    insert_last(list1,2,8);
    insert_last(list1,1,0);

    insert_last(list2,8,12);
    insert_last(list2,-3,12);
    insert_last(list2,10,6);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1,list2,list3);
    poly_print(list3);

    free(list1);free(list2);free(list3);


}