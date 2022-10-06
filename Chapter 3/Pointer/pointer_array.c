#include <stdio.h>

int main(){
    char str[] = "Fryends"; //Frayends만큼 크기가 정해진 상태인 배열
    printf("%c\n", str[1]); //r
    printf("%p\n", &str); // 첫번째 값을 가리키는 주소 0061FF18
    printf("%p\n", &str[0]); // 첫번째 값을 가리키는 주소 0061FF18
    printf("%p\n", &str[1]); //Char형이라서 1씩 증가 0061FF19
    printf("%c\n", *(str+1)); //str 주소에서 char형 크기인 1만큼 증가한 r
    printf("%c\n", *(str)+1); // str이 가리킨 문자열 F다음인 G
    printf("%s\n", str); //Fryends
    
    char *str2;
    printf("new");
    printf("%p\n", &str2); //0061FF14
    printf("%s\n", str2);
    //아직 포인터가 가리키는거 없음
    printf("end2");
    str2 = "Fryends";
    printf("%p\n", &str2);//0061FF14
    printf("%s\n", str2); //Fryends
    printf("%p\n", *str2); //00000046


    printf("start");
    printf("%p\n", &str2[0]);//0040506C
    printf("%p\n", &str2[1]);//0040506D
    printf("%p\n", &str2[2]);//0040506E
    printf("end");



    printf("%p\n", *(str2+2)); //00000079 실제로 아스키코드로 변환된 숫자값이 저장?
    printf("%p\n", *(str2+3)); //00000065
    printf("%p\n", *(str2+4)); //0000006E

    return 0;
}