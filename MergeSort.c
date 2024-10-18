#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int leftIndex = low;
    int rightIndex = mid + 1;
    int i;
    
    // Allocate temporary array for merging
    int *tempArray = (int *)malloc((high - low + 1) * sizeof(int));
    
    // Merge the two halves into tempArray
    for (i = 0; leftIndex <= mid && rightIndex <= high; i++) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            tempArray[i] = arr[leftIndex++];
        } else {
            tempArray[i] = arr[rightIndex++];
        }
    }
    
    // Copy remaining elements from the left half, if any
    while (leftIndex <= mid) {
        tempArray[i++] = arr[leftIndex++];
    }
    
    // Copy remaining elements from the right half, if any
    while (rightIndex <= high) {
        tempArray[i++] = arr[rightIndex++];
    }
    
    // Copy merged elements back to the original array
    for (i = low; i <= high; i++) {
        arr[i] = tempArray[i - low];
    }
    
    // Free the allocated memory for tempArray
    free(tempArray);
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int i, arr[11], n;
    
    printf("Enter number of elements (max 11): ");
    scanf("%d", &n);
    
    if (n > 11 || n < 1) {
        printf("Invalid number of elements. Please enter a number between 1 and 11.\n");
        return 1;
    }
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n - 1);
    
    printf("List after sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;    
}
