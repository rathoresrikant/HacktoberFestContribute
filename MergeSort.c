#include <stdio.h>

#define MAX_SIZE 11 // Define a constant for maximum size

void merge(int a[], int low, int mid, int high) {
    int l1, l2, i, b[MAX_SIZE]; // Use a local temporary array for merging
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }
    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];
    
    // Copy merged elements back to the original array
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int a[], int low, int high) { 	
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int i, a[MAX_SIZE], n;
    
    printf("Enter number of elements (max %d): ", MAX_SIZE - 1);
    scanf("%d", &n);
    
    // Validate the number of elements
    if (n < 1 || n > MAX_SIZE - 1) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE - 1);
        return 1; // Exit with an error code
    }
    
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, 0, n - 1);
    
    printf("List after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n"); // Added newline for better output formatting

    return 0;	
}
