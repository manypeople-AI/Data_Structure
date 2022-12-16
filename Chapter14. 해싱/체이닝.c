#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 7

typedef struct
{
    int key;
}element;

struct list{ // 하나의 버킷을 연결리스트로 구현
    element item;
    struct list *link;
};
struct list *hash_table[TABLE_SIZE]; 

//제산 함수를 사용한 해싱함수
int hash_function(int key){
    return key % TABLE_SIZE;
}

// 체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, struct list *ht[]){
    





}





