#include<stdio.h>
#define SIZE 50

typedef struct Heap {
	int heap[SIZE];
	int i;
	int type;
}Heap;

void init(Heap* h) {
	h->i = 0; 
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Heap *h, int curr) {
	if(curr == 0) {
		return;
	}

	if((h -> heap[(curr - 1)/2]) > (h -> heap[curr])) {
		swap(&(h -> heap[(curr - 1)/2]), &(h -> heap[curr]));
		curr = (curr-1)/2;
		heapify(h,curr);
	}
	else {
		return;
	}

}

void insert(Heap *h,int value) {
	h ->heap[h->i] = value;
	heapify(h, h-> i);
	h -> i++;
}

void printHeap(int arr[], int n)
{
    printf("Array representation of Heap is:\n");

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
	Heap h;
	init(&h);
	insert(&h, 1);
	insert(&h, 5);
	insert(&h, 6);
	insert(&h, 2);
	insert(&h, 8);
        insert(&h, 10);
        insert(&h, 3);
        insert(&h, 4);
	printHeap(h.heap, h.i);
}
