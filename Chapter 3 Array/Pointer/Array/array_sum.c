#include <stdio.h>
// 배열에서 요소의 합을 구해보기

int main(){
    
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };    // 크기가 10인 int형 배열
    int sum = 0;

    for (int i =0;i<sizeof(numArr)/sizeof(int);i++){
        sum+=numArr[i];
    }

    printf("sum is %d",sum);
    
    return 0;
}