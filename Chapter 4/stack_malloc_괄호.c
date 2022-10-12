#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1; //구조체의 element를 접근하기 위해 ->를 사용 접근지시자 
    //s의 top을 -1로 설정하겠음
    s->capacity=1;
    s->data = (element*)malloc(s->capacity*sizeof(element));
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
        s->capacity*=2;
        s->data = (element*)realloc(s->data,s->capacity*sizeof(element));
    }
    else s->data[++(s->top)] = item; //top이나 data에 접근하려면 모두 ->구조체 접근
}
// 스택 삭제 함수
void delete(StackType *s){
    free(s);
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

int check_matching(const char *in){
    int n = strlen(in); //문장의 길이
    char ch;
    StackType s;
    char a;

    init_stack(&s);

    for (int i=0;i<n;i++){
        ch = in[i];
        switch (ch)
        {
        case '(':case '[': case'{':
            push(&s,ch);
            break;
        case ')':case ']': case'}':
            a = pop(&s);
            if ((a=='('&&ch==')')|| (a=='['&&ch==']') ||(a=='{'&&ch=='}')){
                break;
            }
            else return 0;
            break;
        }
    }
    return 1;
}

int main(void){
    char *p = "{A[(i+1]=0; }";
    if (check_matching(p) == 1)
        printf("%s success\n",p);
    else
        printf("%s fail \n",p);
    return 0;
}