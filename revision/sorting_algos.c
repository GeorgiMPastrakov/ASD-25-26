#include "sorting_algos.h"

void printArr(int *arr, uchar size){
    for(uchar i = 0; i < size; i++){
        printf(" [%d] ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, uchar size){
    if (size < 2) return;
    for(uchar i = 0; i < size; i++){
        bool swapped = false;
        for(uchar j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                SWAP(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)break;
    }
}

void selectionSort(int *arr, uchar size){
    if (size < 2) return;
    for(uchar i = 0; i < size - 1; i++){
        uchar minIndex = i;
        for(uchar j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        SWAP(arr[i], arr[minIndex]);
    }
}

void insertionSort(int *arr, uchar size){
    if (size < 2) return;
    for(uchar i = 1; i < size; i++){
        int key = arr[i];
        uchar j = i;
        while(j > 0 && arr[j-1] > key){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}

static void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    memcpy(L, arr + left, n1 * sizeof(int));
    memcpy(R, arr + mid + 1, n2 * sizeof(int));
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

static void mergeSortRec(int *arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortRec(arr, left, mid);
    mergeSortRec(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int *arr, int size) {
    if (size > 1)
        mergeSortRec(arr, 0, size - 1);
}

void quickSort(int *arr, uchar size);

void heapSort(int *arr, uchar size);

void countingSort(int *arr, uchar size);

void radixSort(int *arr, uchar size);

void bucketSort(int *arr, uchar size);

void shellSort(int *arr, uchar size);
