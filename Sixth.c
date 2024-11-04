/*Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        s->capacity *= 2; 
        s->arr = (int*)realloc(s->arr, s->capacity * sizeof(int));
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return -1;
}

int evaluatePostfix(const char *postfix) {
    Stack *s = createStack(10);
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(s, postfix[i] - '0');
        } else {
            int operand2 = pop(s);
            int operand1 = pop(s);
            switch (postfix[i]) {
                case '+': push(s, operand1 + operand2); break;
                case '-': push(s, operand1 - operand2); break;
                case '*': push(s, operand1 * operand2); break;
                case '/': push(s, operand1 / operand2); break;
                case '%': push(s, operand1 % operand2); break;
                case '^': push(s, (int)pow(operand1, operand2)); break;
            }
        }
    }
    int result = pop(s);
    freeStack(s);
    return result;
}

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int choice;

    printf("Select an application:\n");
    printf("1. Evaluate Suffix Expression\n");
    printf("2. Solve Tower of Hanoi Problem\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            char postfix[100];
            printf("Enter a postfix expression: ");
            scanf("%s", postfix);
            int result = evaluatePostfix(postfix);
            printf("The result of the postfix expression is: %d\n", result);
            break;
        }
        case 2: {
            int n;
            printf("Enter the number of disks: ");
            scanf("%d", &n);
            printf("The moves to solve Tower of Hanoi with %d disks are:\n", n);
            towerOfHanoi(n, 'A', 'C', 'B');
            break;
        }
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}