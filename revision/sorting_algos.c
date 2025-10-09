#include "sorting_algos.h"

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf(" [%d] ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size){
    if (size < 2) return;
    for(int i = 0; i < size; i++){
        bool swapped = false;
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                SWAP(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)break;
    }
}

void selectionSort(int *arr, int size){
    if (size < 2) return;
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        SWAP(arr[i], arr[minIndex]);
    }
}

void insertionSort(int *arr, int size){
    if (size < 2) return;
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i;
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

static int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            SWAP(arr[++i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

static void heapify(int *arr, int n, int i) {
    int largest = i;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        largest = i;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest == i) break;
        SWAP(arr[i], arr[largest]);
        i = largest;
    }
}

void heapSort(int *arr, int size) {
    if (size < 2) return;
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }
    for (int end = size - 1; end > 0; --end) {
        SWAP(arr[0], arr[end]);
        heapify(arr, end, 0);
    }
}

void countingSort(int *arr, int size) {
    if (size < 2) return;
    int minv = arr[0], maxv = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minv) minv = arr[i];
        if (arr[i] > maxv) maxv = arr[i];
    }
    int range = maxv - minv + 1;
    if (range > 1000000) {
        insertionSort(arr, size);
        return;
    }
    int count[range];
    for (int i = 0; i < range; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[arr[i] - minv]++;
    for (int i = 1; i < range; ++i) count[i] += count[i - 1];
    int out[size];
    for (int i = size - 1; i >= 0; --i) {
        int idx = arr[i] - minv;
        out[--count[idx]] = arr[i];
    }
    for (int i = 0; i < size; ++i) arr[i] = out[i];
}

static void radixCountByDigit(int *a, int n, int exp) {
    int count[10] = {0};
    int out[n];
    for (int i = 0; i < n; ++i) {
        int digit = (a[i] / exp) % 10;
        if (digit < 0) digit = -digit;
        count[digit]++;
    }
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        int digit = (a[i] / exp) % 10;
        if (digit < 0) digit = -digit;
        out[--count[digit]] = a[i];
    }
    for (int i = 0; i < n; ++i) a[i] = out[i];
}

static void radixNonNegative(int *a, int n) {
    if (n < 2) return;
    int maxv = a[0];
    for (int i = 1; i < n; ++i) if (a[i] > maxv) maxv = a[i];
    for (int exp = 1; maxv / exp > 0; exp *= 10) {
        int count[10] = {0};
        int out[n];
        for (int i = 0; i < n; ++i) count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; --i) {
            int d = (a[i] / exp) % 10;
            out[--count[d]] = a[i];
        }
        for (int i = 0; i < n; ++i) a[i] = out[i];
    }
}

void radixSort(int *arr, int size) {
    if (size < 2) return;
    int negCount = 0, posCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) negCount++; else posCount++;
    }
    int neg[negCount], pos[posCount];
    int ni = 0, pi = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) neg[ni++] = -arr[i];
        else pos[pi++] = arr[i];
    }
    radixNonNegative(pos, posCount);
    radixNonNegative(neg, negCount);
    int k = 0;
    for (int i = negCount - 1; i >= 0; --i) arr[k++] = -neg[i];
    for (int i = 0; i < posCount; ++i) arr[k++] = pos[i];
}

void bucketSort(int *arr, int size) {
    countingSort(arr, size);
}

void shellSort(int *arr, int size) {
    if (size < 2) return;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int tmp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > tmp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
    }
}
