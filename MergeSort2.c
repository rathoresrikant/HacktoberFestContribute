#include <stdio.h>
#define MAX 30

int main() {
    int a[MAX], temp[MAX], i, j, k, n, size, l1, h1, l2, h2;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {    
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Unsorted list is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Merge sort
    for (size = 1; size < n; size = size * 2) {
        l1 = 0;

        while (l1 + size < n) {
            h1 = l1 + size - 1; // end of first half
            l2 = h1 + 1; // start of second half
            h2 = l2 + size - 1; // end of second half

            // Adjust h2 if it goes beyond the array
            if (h2 >= n) {
                h2 = n - 1;
            }

            i = l1; // start of first half
            j = l2; // start of second half
            k = l1; // index for temp

            // Merge the two halves into temp
            while (i <= h1 && j <= h2) {
                if (a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            // Copy remaining elements from the first half, if any
            while (i <= h1)
                temp[k++] = a[i++];

            // Copy remaining elements from the second half, if any
            while (j <= h2)
                temp[k++] = a[j++];

            // Move to the next segment
            l1 = h2 + 1;
        }

        // Copy the sorted subarray back to original array
        for (i = l1; i < n; i++)
            temp[i] = a[i]; // Copy remaining elements to temp

        // Copy temp back to a
        for (i = 0; i < n; i++)
            a[i] = temp[i];

        printf("\nSize = %d \nElements are: ", size);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    }

    printf("\nSorted list is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
