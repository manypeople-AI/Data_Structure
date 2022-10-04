#include <stdio.h>

int main(){

    char str[]= "Fryends"; //포인터 str은 "fryends"라는 문자열을 가리키는 포인터
    //str은 문자열 fryends의 주소를 가리킴
    
    *(str+2) = 'i';

	printf("%s ", str);
	return 0;


}
