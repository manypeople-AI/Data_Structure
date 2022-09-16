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

    printf("Please enter the number : ");
    if 
    scanf("%d", &num1); // 입력을 받아서 변수에 저장

    result = factorial(num1);

    // print
    printf("Result is %d!= %d\n", num1, result);

    return 0;
}