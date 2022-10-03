#include <stdio.h>
// 배열의 요소에 저장된 값을 두배로

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };    // 크기가 10인 int형 배열

    for (int i=0;i<sizeof(numArr)/sizeof(int);i++){
        numArr[i] = 2*numArr[i];
        printf("%d\n",numArr[i]);}
   

    return 0;
}



