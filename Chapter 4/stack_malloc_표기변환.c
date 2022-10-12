// 중위 표기식을 후위 표기식으로 변환하기
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
//연산자의 우선 순위를 반환
// *>+인 경우 +를 빼야하기 때문에
int prec(char op){
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1; //에러 발생
}

// 중위표기 수식 -> 후위표기 수식
void infix_to_profix(char exp[]){
    StackType s;
    StackType s2;
    init_stack(&s);
    init_stack(&s2);
    int len = strlen(exp);
    char ch, a;

    for (int i = 0;i<len;i++){
        ch =exp[i];
        // 문자가 숫자인 경우
        if (ch!='('&&ch!='+'&&ch!=')'&&ch!='-'&&ch!='/'&&ch!='*'){
            printf("%c",ch);
        }
        else{
            switch(ch)
            {
            case '(':
                push(&s, ch);
                break;
            case ')':
                a = pop(&s);
                printf("%c",a);
                //push(&s2,a);
                pop(&s);
                break;
            case '+':
                a = peek(&s);
                if (prec(a)>prec(ch)){
                    a = pop(&s);
                    push(&s,ch);
                    printf("%c",a);
                    }
                else {
                    push(&s,ch);
                    }
                break;
            case '-':
                a = peek(&s);
                if (prec(a)>prec(ch)){
                    a = pop(&s);
                    push(&s,ch);
                    printf("%c",a);
                }
                else{
                    push(&s,ch);
                }
                break;
            case '*':
                push(&s,ch);
                break;
            case '/':
                push(&s,ch);
                break;
            }
        }  

    }
    for (;is_empty(&s)!=1;){
        printf("%c",pop(&s));
    }

    // 바닥부터 출력해야한다
//     for (;is_empty(&s2)!=1;){
//         printf("%c",pop(&s2));
//     }
}

//main문
int main(void){
    char *s = "(2+3)*4+9";
    printf("infix %s \n",s);
    printf("profix ");
    infix_to_profix(s);
    printf("\n");
    return 0;
}

