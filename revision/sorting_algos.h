#ifndef SORTING_ALGOS
#define SORTING_ALGOS
#include<stdio.h>

#define SWAP(a, b) {a = a^b; b = a^b; a = a^b;}while (0)

typedef unsigned char uchar;

void printArr(int *arr, uchar size);
void bubbleSort(int *arr, uchar size);
void selectionSort(int *arr, uchar size);
void insertionSort(int *arr, uchar size);
void mergeSort(int *arr, uchar size);
void quickSort(int *arr, uchar size);
void heapSort(int *arr, uchar size);
void countingSort(int *arr, uchar size);
void radixSort(int *arr, uchar size);
void bucketSort(int *arr, uchar size);
void shellSort(int *arr, uchar size);

#endif