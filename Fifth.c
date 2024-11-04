/*Design, Develop and Implement a Program in C/C++ for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized expressions with
the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Stack {
    char *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(capacity * sizeof(char));
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

void push(Stack *s, char value) {
    if (isFull(s)) {
        s->capacity *= 2; // Double the stack size
        s->arr = (char*)realloc(s->arr, s->capacity * sizeof(char));
    }
    s->arr[++s->top] = value;
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int isLeftAssociative(char op) {
    return op != '^';
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack *s = createStack(10);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            pop(s);
        } else if (isOperator(infix[i])) {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(infix[i]) && isLeftAssociative(infix[i])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    freeStack(s);
}

int main() {
    char *infix = (char *)malloc(256 * sizeof(char));
    char *postfix = (char *)malloc(256 * sizeof(char));

    printf("Enter infix expression: ");
    fgets(infix, 256, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    free(infix);
    free(postfix);
    return 0;
}