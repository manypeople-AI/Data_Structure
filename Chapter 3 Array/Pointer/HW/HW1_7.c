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

    for (int i=len-1;i>=len/2;i--){
        swap(&str[i],&str[len-i-1]);
    }
}
int main() {
    char str[] = "TOMATO";
    printf("%s\n", str); //TOMATO
    reversestring(str); //주소값을 받았다
    printf("%s\n", str); //TOMATO
    return 0;
}