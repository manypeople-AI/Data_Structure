#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) //주소를 받음 a가 가리키는건 str[i]의 주소
{
	char temp = *a;  //*a는 element 값
	*a = *b; 
	*b = temp;
}

void reversestring(char *str){ //주소!
    int len = strlen(str);
    //printf("%d\n", len); //6
    //printf("%s\n", str); //TOMATO

    for (int i=len-1;i>=len/2;i--){
        //printf("%c\n", str[i]);
        //printf("%c\n", str[len-i-1]);
        swap(&str[i],&str[len-i-1]);
    }

    //return str;
}

int main() {
    char str[] = "TOMATOS";

    printf("%s\n", str); //TOMATO
    reversestring(str); //주소값을 받았다
    printf("%s\n", str); //TOMATO

    return 0;
}