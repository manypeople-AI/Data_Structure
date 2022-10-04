#include <stdio.h>
#define N 3

void print(int arr[][N], int n){

    int col = sizeof(arr[0]) / sizeof(int);    // 4: 2차원 배열의 가로 크기를 구할 때는 
    
    for (int i=0;i<col;i++){
        for (int j=0;j<N;j++){
            printf("%d ", arr[i][j]);
        }
    }

}

int main()
{
    int arr[][N]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };

    print(arr,N);

    return 0;
}
