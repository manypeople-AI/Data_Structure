#include <stdio.h>

int main(){

    char* str= "helloworld"; //포인터 str은 "fryends"라는 문자열을 가리키는 포인터
    //str은 문자열 fryends의 주소를 가리킴
    
    printf("%c ",(*str+2)); // H 출력
    
    printf("%c ",(*str+1)); // G
    printf("%c ",(*str)); // F 출력 시작점을 가리킴
	printf("%s ", str);

    char str2[] = "Fryends";

    printf("%c ",*(str2+2)); // y

	return 0;
}