#include <stdio.h>//포인터 연산 사용하기


int main()
{//포인터로 선언한 변수에는 메모리 주소가 들어있음.
    //이 포인터 변수에 덧셈이나 뺄셈 연산을 하면 어떻게 될까요?
	char str[10] = "Fryends"; 
    char *p = str;

	*(p + 2) = 'i';
	printf("%s ", str);
	return 0;
}

