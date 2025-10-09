#include "sorting_algos.h"

int main(void){

    int arr[] = {10, 9, 8, 7, 6, 5, 4, -1, 1, 11, 16, -100, 250};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);
    quickSort(arr, 0, size-1);
    printArr(arr, size);
    return 0;
}