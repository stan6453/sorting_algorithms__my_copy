#include "sort.h"

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    printf("[left]: ");
    for (int p = 0; p < leftSize; p++) {
        printf("%d, ", left[p]);
    }
    printf("\n");
    printf("[right]: ");
    for (int p = 0; p < rightSize; p++) {
        printf("%d, ", right[p]);
    }
    printf("\n");

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
    printf("[Done]: ");
    for (int p = 0; p < k; p++) {
        printf("%d, ", arr[p]);
    }
    printf("\nMerging...\n");
}

void merge_sort(int *arr, size_t size) {
    if (size < 2) {
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}
