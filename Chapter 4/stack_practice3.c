#include <stdio.h>
#include <stdlib.h>
//top과 stack 배열을 하나의 구조체로 결합시키고 이 구조체의 포인터를 함수로 전달함

// 차후에 스택이 필요하면 여기만 복사하여 붙인다.
// ====== 스택 코드의 시작 =====
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1; //구조체의 element를 접근하기 위해 ->를 사용 접근지시자 
    //s의 top을 -1로 설정하겠음
}

//공백 상태 검출 함수
int is_empty(StackType *s){
    return (s->top == -1); //구조체 s의 top이 -1과 같으면 1 반환
}

//포화 상태 검출 함수
int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);
}

//삽입함수
void push(StackType *s, element item){
    if (is_full(s)){
        fprintf(stderr,"stack overflow\n");
        return;
    }
    else s->data[++(s->top)] = item; //top이나 data에 접근하려면 모두 ->구조체 접근
}

//삭제 함수
element pop(StackType *s){
    if (is_empty(s)){
        fprintf(stderr,"stack underflow\n");
        exit(1);
    }
    else return s->data[(s->top)--]; //보고나서 삭제하기
}

element peek (StackType *s){
    if (is_empty(s)){
        fprintf(stderr,"stack underflow\n");
        exit(1);
    }
    else return s->data[(s->top)]; //그냥 꺼내보기만 함 삭제 x

}

// =========스택 코드 종료=========

int main(void){
    StackType s; //스택을 정적으로 생성
    StackType p;
    int a;

    init_stack(&s); // 스택 초기화
    push(&s, 1); //스택에 1 push
    push(&s, 2);
    push(&s, 3);
    a = peek(&s);
    printf("peek %d\n",a);
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));

    init_stack(&p); // 스택 초기화
    push(&p, 5); //스택에 1 push
    push(&p, 7);
    push(&p, 8);
    printf("%d\n",pop(&p));
    printf("%d\n",pop(&p));
    printf("%d\n",pop(&p));
}




