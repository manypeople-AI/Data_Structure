#include <stdio.h>

//다양한 자료형의 포인터 선언하기

int main(){

    long long *numPtr1; // *numPtr1은 8바이트
    float *numPtr2; // *numPtr2는 4바이트
    char *cPtr1; // *cPtr1은 1바이트

    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';

    numPtr1 = &num1;    // num1의 메모리 주소 저장
    numPtr2 = &num2;    // num2의 메모리 주소 저장
    cPtr1 = &c1;        // c1의 메모리 주소 저장

    printf("%p\n",&num1);
    printf("%d\n", sizeof(*numPtr1));    // 8
    printf("%d\n", sizeof(numPtr1));  // 4
    printf("%f\n", *numPtr2);      // 3.500000
    printf("%c\n", *cPtr1);        // a

    return 0;

}




