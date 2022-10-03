#include <stdio.h>

// 메모리 주소를 출력해보는 함수
int main()
{
    int num1 = 10;
    //변수앞에 &(주소연산자)를 붙이면 메모리 주소 구할수있음
    printf("%p\n", &num1);    // 008AF7FC: num1의 메모리 주소를 출력
                              // 컴퓨터마다, 실행할 때마다 달라짐

    char c1 = 'a';         // 변수에 문자 'a' 저장
    char *s1 = "Hello";    // 포인터에 문자열 "Hello"의 주소 저장

    printf("%c\n", c1);    // a: %c로 문자 출력
    printf("%s\n", s1);    // Hello: %s로 문자열 출력

    return 0;
}