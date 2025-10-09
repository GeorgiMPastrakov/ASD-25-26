#ifndef SORTING_ALGOS
#define SORTING_ALGOS
#include<stdio.h>
#include<stdbool.h>
#include <string.h>

#define SWAP(a, b)  {int tmp = (a); (a) = (b); (b) = tmp;}

void printArr(int *arr, int size);
void bubbleSort(int *arr, int size);
void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void mergeSort(int *arr, int size);
void quickSort(int *arr, int low, int high);
void heapSort(int *arr, int size);
void countingSort(int *arr, int size);
void radixSort(int *arr, int size);
void bucketSort(int *arr, int size);
void shellSort(int *arr, int size);

#endif