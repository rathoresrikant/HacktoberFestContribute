#include <stdio.h>

int main() {
    int n, A[100];

    // Input size and elements
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Insertion sort in descending order
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        // Move elements that are less than key to one position ahead
        while (j >= 0 && A[j] < key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; // Insert key at the correct position
    }

    // Output sorted array
    printf("Sorted array in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
