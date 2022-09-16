#include <stdio.h>

int factorial(int n)
{   
    if (n<=1) return(1); 
    else return(n*factorial(n-1));
}

int main(void)
{   
    int num1;
    int result = 0;
    while(1){
        printf("정수를 입력해주세요: ");
        scanf("%d", &num1); // 정수값 받아서 변수에 저장하기
        if(num1<0)continue; 
        if(num1>=0)break;
    }

    result = factorial(num1);

    // print
    printf("Result is %d!= %d\n", num1, result);

    return 0;
}