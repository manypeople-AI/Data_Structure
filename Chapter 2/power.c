// 숫자 x의 n제곱 값을 구하는 문제: x^n
#include <stdio.h>


int power(int x, int n) //n은 남은 곱하는 수
{   
    if (n<1) return(1);
    else return(x*power(x,n-1));
}

int main(void)
{   
    int x,n;
    int result;

    printf("x^n에서 x를 입력하세요: ");
    scanf("%d", &x);
    printf("x^n에서 n을 입력하세요: ");
    scanf("%d", &n);

    result = power(x,n);
    //결과 출력
    printf("x^n은 %d입니다",result);
    
    return 0;
}
