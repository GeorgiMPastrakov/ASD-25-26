#include "sorting_algos.h"

int main(void){

    int arr[] = {10, 9, 8, 7, 6, 5, 4, -1, 1, 11, 16, -100, 250};
    uchar size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);
    insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}