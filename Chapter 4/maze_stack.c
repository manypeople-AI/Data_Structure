// 조건 막다른 길을 만나면 아직 가보지 않은 방 중에서 가장 가까운 방으로 돌아가서 새로운 경로 찾기
// 한번 지나간 방을 다시 가면안됨 - 방문한 방은 표시를 해야함
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    short r; //자료형 short //row 행
    short c; // column 열
    element *data;
    int top;
    int capacity;
}StackType;

StackType terms[MAX_STACK_SIZE];
StackType here = {1,0}, entry = {1,0};

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
void push(StackType *s, StackType item){
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


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

//위치를 스택에 삽입
void push_loc(StackType *s, int r, int c){
    if (r<0 || c<0) return;
    if (maze[r][c]!='.' && maze[r][c]!='1'){//갈 수 있나? 갔던 곳은 아닌가? 
        StackType tmp;
        tmp.r = r; //{a,b}형태의 데이터를 push하는 법
        tmp.c = c;

        push(&s,tmp);
    }

}

//미로를 화면에 출력한다 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    



}

int main(void){



}





