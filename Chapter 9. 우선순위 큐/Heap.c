#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct 
{
    int key;
}element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size; // 요소 몇개 들어있는지
}HeapType;

// 생성함수
HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h){
    h->heap_size=0;
}


// 삽입연산
void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size); // 하나 추가될거니까

    // 트리를 거슬러 올라가면서 부모 노드와 비교
    while((i != 1) && (item.key>h->heap[i/2].key)){ // 이 조건을 만족하면 while문안으로 들어감
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item; //노드를 삽입
}

// 삭제연산
element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 루트 노드는 항상 index가 1이다(0 아님) 
    temp = h->heap[(h->heap_size)--]; // 말단 노드가 temp!
    parent = 1; // 최소 index
    child =2;//최소 index

    while(child<=h->heap_size){ //while문 중지 조건

        //현재 노드의 자식노드 둘 중 더 큰 자식노드를 찾음
        if ((child<h->heap_size) && (h->heap[child].key<h->heap[child+1].key)){
            child++; // 더 큰 자식노드의 index로 child값을 바꾸어줌
        }

        if (temp.key>= h->heap[child].key){ //temp.key = 말단노드의 키 값 (root가 될값?)
            break; // 말단노드 키값이 자식노드들보다 크면 중지하기
        }

        // 그게 아니라면 말단 노드 키 값이 자식노드들보다 작으면?
        h->heap[parent] = h->heap[child];
        parent = child; // 내려옴
 
        child*=2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void){
    element el = {10}, e2={5}, e3 ={30};
    element e4, e5, e6;
    HeapType* heap;


    heap = create();
    init(heap);

    insert_max_heap (heap, el);
    insert_max_heap (heap, e2); 
    insert_max_heap (heap, e3);

    //삭제
    e4 = delete_max_heap(heap);
    printf ("< %d > ", e4.key);
    e5 = delete_max_heap (heap) ;
    printf ("< %d > ", e5. key) ;
    e6 = delete_max_heap (heap) ;
    printf("< %d > \n", e6. key) ;
    
    free(heap) ;
    return 0;
}





