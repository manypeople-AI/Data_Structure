// 숫자 x의 n제곱 값을 구하는 문제 : x^n
#include <stdio.h>


int power(int x, int n) 
{   
    if (n<1) return(1);
    else return(x*power(x,n-1));
}

int main(void)
{   
    int x,n;
    int result;

    printf("x^n에서 x의 값을 입력하세요.: ");
    scanf("%d", &x);
    printf("x^n에서 n의 값을 입력하세요.: ");
    scanf("%d", &n);

    result = power(x,n);
    //결과 출력
    printf("x^n는 %d입니다",result);
    
    return 0;
}
