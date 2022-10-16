#include <stdio.h>
#define MAX_DEGREE 101 // 다항식의 최대차수 + 1
// 다항식을 처리하는 방법
// 모든 차수의 계수값을 배열에 저장
typedef struct{
    int degree; //차수
    float coef[MAX_DEGREE];  //계수들의 배열
}polynomial1;

// 이런 방법은 대부분의 항의 계수가 0인 경우 공간의 낭비가 심하다는 것
// 그러나 덧셈, 뺄셈 시에 같은 차수의 계수를 쉽게 찾을 수 있으므로 알고리즘이 간단해짐.
int main(void){
    polynomial1 a = {5, {10,0,0,0,6,3}}; // 정의하기
    printf("%d\n", a.degree);
    printf("%3.1f", a.coef[0]); //5차항의 계수
    

    return 0;

}