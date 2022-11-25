#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{ // 연결리스트 구조체
    element data;
    struct StackNode *link;
}StackNode;

typedef struct //스택 구조체
{
    StackNode *top;
    /* data */
}LinkedStackType;

// 초기화 함수
void init(LinkedStackType *s)
{
    s->top = NULL;
}

// 공백상태 검출 함수
int is_empty(LinkedStackType *s){
    return (s->top == NULL); // 스택이 비어있으면 1 반환
}
// 포화상태 검출 함수
int is_full(LinkedStackType *s){
    return 0; //??왜?
}

// 삽입 연산
void push(LinkedStackType *s, element item){
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = item;
    temp -> link = s-> top;
    s->top = temp;
}


// 삭제 연산
element pop(LinkedStackType *s){
    if (is_empty(s)==1){ // 스택이 비어있는 경우
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else{
        StackNode *temp = s->top;
        int data = temp -> data; //삭제하기 전에 데이터 저장
        s->top = s->top->link;
        free(temp);
        return data;
    }
}


// peek 함수
element peek(LinkedStackType *s){
    if (is_empty(s)==1){ // 스택이 비어있는 경우
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else{
        return (s->top->data);
    }
}



// 스택 출력 함수
void print_stack(LinkedStackType *s){
    for (StackNode *p = s->top;p!=NULL;p=p->link){
        printf(" %d ->",p->data);

    }
    printf("NULL \n");
}

int main(void){
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    return 0;
    
}


