// 전역변수로 스택
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

// 공백 상태 검출 함수
int is_empty(){
    return (top == -1);
}


// 포화 상태 검출 함수
int is_full(){
    return (top==MAX_STACK_SIZE-1); //같으면 1, 다르면 0
}


// 삽입 함수
void push(element item){ //item은 추가할 요소

    if (is_full()){ //is_full()이 1이면 if문 실행
        fprintf(stderr,"스택오버플로우\n");
        return;
    }
    else stack[++top]=item; //앞에 ++가 붙으면 라인이 실행되기 전에 +1
}

//삭제 함수

element pop(){
    if (is_empty()){
        fprintf(stderr,"스택언더플로우\n");
        exit(1); //프로그램 강제종료
    }
    else return stack[top--];
}
//피크 함수

element peek(){
    if (is_empty()){
        fprintf(stderr,"스택오버플로우\n");
        exit(1);
    }
    else return stack[top];
    }

int main(void){
    push(1);
    push(2);
    push(3);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    return 0;
}














