#include <stdio.h>

int hand(int N){
    if (N<=1) return(0); 
    else return(N-1+hand(N-1));
}

int main(void){
    int N;
    int result = 0;

    while(1){
        printf("Please enter the num: ");
        scanf("%d", &N); // 정수값 받아서 변수에 저장하기
        if(N<0)continue; 
        if(N>=0)break;
    }


    result = hand(N);

    // print
    printf("When there are %d people, the total number of handshakes is %d\n", N, result);

    return 0;


}





