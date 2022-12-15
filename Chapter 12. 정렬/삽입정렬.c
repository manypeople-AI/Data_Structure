#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int list[], int n){
    int i,j,key;
    for (i=1;i<n;i++){
        key = list[i];
        for (j = i-1;j>=0&&list[j]>key;j--) //초기식 -> 조건식 -> 수행구문 -> 증감식 -> 조건식 
            list[j+1] = list[j];
        list[j+1] = key;
    }
}
