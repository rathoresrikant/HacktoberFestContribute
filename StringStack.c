#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int top = -1;
char stack[MAX_STACK_SIZE];

void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        return '\0'; // Return a null character to indicate underflow
    }
    return stack[top--];
}

void reverseString(char* str) {
    int len = strlen(str);

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop characters from the stack and store them back in the string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
