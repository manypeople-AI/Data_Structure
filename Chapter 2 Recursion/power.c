// ���� x�� n���� ���� ���ϴ� ���� : x^n
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

    printf("x^n���� x�� ���� �Է��ϼ���.: ");
    scanf("%d", &x);
    printf("x^n���� n�� ���� �Է��ϼ���.: ");
    scanf("%d", &n);

    result = power(x,n);
    //��� ���
    printf("x^n�� %d�Դϴ�",result);
    
    return 0;
}
