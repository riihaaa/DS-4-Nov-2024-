/*Design, Develop and Implement a menu driven Program in C for the following operations on STACK of
Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("Pushed %d onto stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return -1;
    }
    return s->arr[s->top--];
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int checkPalindrome(int num) {
    Stack *s = createStack(10); // Assume max 10 digits for simplicity
    int original = num;

    while (num > 0) {
        push(s, num % 10);
        num /= 10;
    }

    int isPalin = 1;
    while (original > 0) {
        if (pop(s) != original % 10) {
            isPalin = 0;
            break;
        }
        original /= 10;
    }

    free(s->arr);
    free(s);
    return isPalin;
}

int main() {
    int initialCapacity, choice, value;

    printf("Enter initial stack capacity: ");
    scanf("%d", &initialCapacity);
    
    Stack *s = createStack(initialCapacity);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                value = pop(s);
                if (value != -1) {
                    printf("Popped %d from stack\n", value);
                }
                break;
            case 3:
                printf("Enter an integer to check for palindrome: ");
                scanf("%d", &value);
                if (checkPalindrome(value)) {
                    printf("%d is a palindrome\n", value);
                } else {
                    printf("%d is not a palindrome\n", value);
                }
                break;
            case 4:
                displayStack(s);
                break;
            case 5:
                free(s->arr);
                free(s);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}