//posfix
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

int eval(char exp[]){ //왜? 수정해야해서 by성진짱

    int op1, op2, value, i =0;
    int result;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);


    //숫자면 push 연산자면 계산
    for (int i=0;i<len;i++){ // i.. for 문안에 있는 i는 새로 할당
        if (exp[i]=='/'||exp[i]=='*'||exp[i]=='+'||exp[i]=='-'){//연산자인 경우
            int b = pop(&s); //먼저 뒤에께 나옴 주의주의!!!!!!!!!!!!!!!!!!!!
            int a = pop(&s);
            switch (exp[i])
            {
            case '/':
                result = a/b;
                push(&s,result);
                break;
            case '*':
                result = a*b;
                push(&s, result);
                break;
            case '+':
                result = a+b;
                push(&s, result);
                break;
            case '-':
                result = a-b;
                push(&s, result);
                break;
            }       
        }
        else{
            value = exp[i] - '0';
            push(&s, value);
        }
    
    
    }
    return pop(&s);
}

int main(void){

    int result;
    printf("posfix is 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("result is %d\n",result);

    return 0;
    }