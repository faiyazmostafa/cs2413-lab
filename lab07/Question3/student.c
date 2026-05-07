#include <stdio.h>

// Helper function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller elements to the left
   of the pivot and all greater elements to the right.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    // Place the pivot in the correct spot
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive helper function
void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size) {
    // If the array is empty or has only one element, do nothing.
    if (arr == NULL || size < 2) {
        return;
    }

    quickSortHelper(arr, 0, size - 1);
}