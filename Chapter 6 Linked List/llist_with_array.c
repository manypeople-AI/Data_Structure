#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 리스트 구현
// 배열을 이용한 구현-> 구현이 간단, 속도가 빠름, 그러나 리스트의 크기가 고정
// 순차적인 메모리 공간 할당 -> 리스트의 순차적 표현

#define MAX_LIST_SIZE 100 //리스트의 최대크기

// 배열과 항목의 개수
typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE];
    int size; // 현재 리스트에 저장된 element 개수
}ArrayListType;

// 오류 처리 함수
void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L){
    L->size =0;
}

// 리스트가 비어있으면 1을 반환
// 그렇지 않으면 0 반환

int is_empty(ArrayListType *L){
    return L->size==0;
}

// 리스트가 가득 차있으면 1을 반환
// 그렇지 않으면 0을 반환

int is_full(ArrayListType *L){
    return L->size==MAX_LIST_SIZE;
}


element get_entry(ArrayListType *L, int pos){ // 값에 접근하기 pos는 index
    if (pos<0 || pos>=L->size)
        error("position error");
    return L->array[pos]; 
        }

//리스트 출력
void print_list(ArrayListType *L){

    int i;
    for (i=0;i<L->size;i++){
        printf("%d->", L->array[i]);
    }
    printf("\n");
}

// 리스트의 맨 끝에 항목을 추가하는 insert_last() 함수 구현

void insert_last(ArrayListType *L, element item){
    if (!is_full(L))// 가득 찬 경우
        L->array[L->size++] = item; // 하나 추가해줬으니까 size++
}

// 리스트의 pos위치에 새로운 항목을 추가
// pos부터 마지막 항목까지 한칸씩 오른쪽으로 이동하여 빈자리를 만들고 새로운 것을 pos에 저장

void insert(ArrayListType *L, int pos, element item){
    if (!is_full(L) && pos>=0 && pos<=L->size){
        for (int i=L->size-1;i>=pos;i--){
            L->array[i+1]=L->array[i];
        }
        L->array[pos]=item;
        L->size++; // 이부분 까먹지마!!!!!
    }
}

// pos 위치의 항목을 삭제하는 함수
void delete(ArrayListType *L, int pos){
    if (!is_empty(L) && pos>=0 && pos<L->size){
        for (int i = pos;i<=L->size-1;i++){
            L->array[i]=L->array[i+1];
        }
        L->size--;
    }
}


int main(void){
    ArrayListType list;
    init(&list);
    insert(&list , 0, 10); print_list(&list);
    insert(&list , 0, 20); print_list(&list); 
    insert(&list , 0, 30); print_list(&list); 
    insert_last(&list , 40); print_list(&list); //overflow
    delete(&list , 0); print_list(&list); //
    return 0;
}
//
//





