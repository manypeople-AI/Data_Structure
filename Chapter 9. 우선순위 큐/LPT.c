#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct{
    int id;
    int avail;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

//생성 함수
HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h){
    h->heap_size=0;
}

//삽입함수 -> min_heap : avail(부모)<=avail(자식)
void insert_min_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size); // 하나 추가될거니까
    
    // 일단 마지막에 추가
    // 트리를 거슬러 올라가면서 부모 노드와 비교
    // while문 안의 부호만 바꿔주면 min_heap이 된다
    while((i != 1) && (item.avail<h->heap[i/2].avail)){ // 이 조건을 만족하면 while문안으로 들어감
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item; //노드를 삽입
}         

// 삭제연산
element delete_min_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 루트 노드는 항상 index가 1이다(0 아님) , 가장 작은 값
    temp = h->heap[(h->heap_size)--]; // 말단 노드가 temp! 
    parent = 1; // 최소 index
    child =2;//최소 index

    while(child<=h->heap_size){ //while문 중지 조건

        //현재 노드의 자식노드 둘 중 더 작은 자식노드를 찾음
        if ((child<h->heap_size) && (h->heap[child].avail>h->heap[child+1].avail)){
            child++; // 더 작은 자식노드의 index로 child값을 바꾸어줌
        }

        if (temp.avail< h->heap[child].avail){ //<=가 아니고 < -> 만약 머신 2와 3이 끝나는 시간 같으면 2에 할당해야함. 같으면 순서 바뀜ㅇㅇ
            break; // 말단노드 키값이 자식노드들보다 작으면 중지하기 
        }

        // 그게 아니라면 말단 노드 키 값이 자식노드들보다 크면?
        h->heap[parent] = h->heap[child];
        parent = child; // 내려옴
 
        child*=2;
    }
    h->heap[parent] = temp;
    return item;
}


#define JOBS 7
#define MACHINES 3
int main(void){
    int jobs[JOBS] = {8,7,6,5,3,2,1}; // 작업은 정렬되어있다고 가정
    element m ={0,0}; // id와 avail
    HeapType* h;
    h = create();
    init(h);

    //avail 값은 기계가 사용 가능하게 되는 시간이다
    for (int i = 0;i<MACHINES; i++){
        m.id = i+1;
        m.avail =0;
        insert_min_heap(h,m);
    }

    // 최소히프에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가시킨 후에 
    // 다시 최소 히프에 추가
    for (int i=0;i<JOBS;i++){
        m = delete_min_heap(h); //루트 꺼내고 재정렬
        printf("JOB %d allocate from time %d to time %d for machine number %d. \n", i, m.avail, m.avail+jobs[i]-1,m.id);

        m.avail += jobs[i];
        insert_min_heap(h,m);
    }
    return 0;
}












