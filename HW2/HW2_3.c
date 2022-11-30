#include <stdio.h>
 
void swap(int*x, int*y);
void MaxHeapify(int arr[], int i, int num);
void convertMaxHeap(int arr[], int num);
 
int main()
{
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int num = sizeof(arr) / sizeof(arr[0]);
 
    for (int i = 0; i < num; ++i)
        printf("%d ", arr[i]);
 
    convertMaxHeap(arr, num);
    
    printf("\n");
    printf("\n");
    
    for (int i = 0; i < num; ++i)
        printf("%d ", arr[i]);
 
    return 0;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void convertMaxHeap(int arr[], int num)
{
    for (int i = (num-2)/2; i >= 0; --i)
        MaxHeapify(arr,num,i);
}

void MaxHeapify(int arr[], int num, int i)
{
    int left = 2*i+ 1;
    int right = 2*i+ 2;
    int largest = i;
 
    if ( (left<num ) && (arr[left]>arr[i]) )
        largest = left;
    if ( (right<num) && (arr[right]>arr[largest]) )
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(arr,num,largest);
    }
}