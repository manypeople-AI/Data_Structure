#include <stdio.h>

// 반복문을 사용하여 배열의 요소를 뒤에서부터 출력

int main(){
    // 크기가 10인 배열
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };
    
    for (int i=(sizeof(arr)/sizeof(int)-1);i>=0;i--){
        printf("%d\n",arr[i]);
    }

    return 0;

}    
