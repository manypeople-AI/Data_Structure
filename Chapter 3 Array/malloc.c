#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 100;
    printf("%d\n",*p);
    free(p);
    printf("%d",*p);

    return 0;

}