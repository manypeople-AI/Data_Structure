#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct 
{
    int key;
}element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType *)malloc(sizeof(HeapType));
}
void init(HeapType *h){
    h->heap_size = 0;
}
// 삽입함수
void insert_max_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    while ((i !=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /=2;
    }
    h->heap[i] = item;
}

//삭제 함수
element delete_max_head(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size){
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if (temp.key >=h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *=2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[],int n){
    int i;
    HeapType* h;

    h = create();
    init(h);

    for (i=0; i<n; i++){
        insert_max_heap(h,a[i]);
    }

    for (i =0;i<=(n-1);i++){ //내림차순으로 설정
        a[i] = delete_max_head(h);
    }
    free(h);
}

#define SIZE 8
int main(void){
    int k;
    int count=1; //count는 unique한 숫자들의 개수 이 개수가 k보다 작아지면 stop
    int temp = 0;
    printf("Enter the k = "); 
    scanf("%d", &k);
    
    element list[SIZE] = {1,23,12,9,30,2,23,50};
    heap_sort(list,SIZE);

    printf("The result is ");
    for (int i=0;i<SIZE;i++){
        if (i>=1){
            if (list[i].key!=list[i-1].key){
                count +=1;
            }
        }
        if (count > k) break;
        printf(" %d ", list[i].key);
    }

    return 0;
}