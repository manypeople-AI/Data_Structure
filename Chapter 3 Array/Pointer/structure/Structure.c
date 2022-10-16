#include <stdio.h> //python에서 import와 같은 것?!
#include <string.h> // strcpy 함수가 선언된 헤더파일

//구조체를 사용하면 여러 자료형들을 
// 조합하여 자신이 원하는 자료형을 만들고 사용할수 있음


// 구조체는 보통 main 함수 바깥에 정의
struct studentTag {
    char name[10]; 	// 문자배열로 된 이름
    
    int age;	  	// 나이를 나타내는 정수값
    double gpa;	  // 평균평점을 나타내는 실수값
};

int main(void){

    // 정의한 구조체를 사용하려면 구조체 변수를 선언해야함
    struct studentTag s; //구조체 변수 선언

    // 점으로 구조체 멤버에 접급해서 값을 할당
    strcpy(s.name, "kim");
    s.age = 20;
    s.gpa = 4.3;

    //점으로 구조체 멤버에 접근해서 값 출력
    printf("%d",s.age);

}