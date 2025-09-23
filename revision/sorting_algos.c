#include "sorting_algos.h"

void printArr(int *arr, uchar size){
    for(uchar i = 0; i < size; i++){
        printf(" [%d] ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, uchar size){
    for(uchar i = 0; i < size; i++){
        for(uchar j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1])SWAP(arr[j], arr[j+1]);
        }
    }
}

void selectionSort(int *arr, uchar size);

void insertionSort(int *arr, uchar size);

void mergeSort(int *arr, uchar size);

void quickSort(int *arr, uchar size);

void heapSort(int *arr, uchar size);

void countingSort(int *arr, uchar size);

void radixSort(int *arr, uchar size);

void bucketSort(int *arr, uchar size);

void shellSort(int *arr, uchar size);
