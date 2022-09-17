#include <stdio.h>

int fib(int n)
{
    if (n==1) return(1);
    else if (n==0) return(0);
    else return(fib(n-1)+fib(n-2));

}

int main(void)
{
    int num;
    int result;

    printf("Enter the num : ");
    scanf("%d",&num);

    //result 
    result = fib(num);
    printf("Result is %d !", result);

    return 0;

}