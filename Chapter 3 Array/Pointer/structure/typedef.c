#include <stdio.h>
#include <string.h> //strcpy 사용하려면 필요

typedef struct{ //typedef를 이용해 구조체를 새로운 타입으로 선언
    char name[10];
    int age;
    double gpa;
}student; //새로운 데이터 타입의 이름이 된다.

int main(void)
{   // int 나 float 처럼 새로운 데이터 타입의 이름이 된다
    student dain; // 새로운 타입만을 이용해 변수 선언 가능
    
    strcpy(dain.name, "George"); //string을 복사
    student a = {"kim", 20, 4.3};
    student b = {"lee", 25, 4.0};

    printf("%d \n", a.age);
    printf("%s \n", dain.name);
    return 0;

}
