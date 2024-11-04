/*Design, Develop and Implement a menu driven Program in C for the following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations.*/

#include <stdio.h>
#include <stdlib.h>

int *a, n, elem, i, pos;

void create() {
    printf("\nEnter the size of the array elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display() {
    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void insert() {
    printf("\nEnter the position for the new element: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &elem);
    pos = pos - 1;

    a = (int *)realloc(a, (n + 1) * sizeof(int));
    if (a == NULL) {
        printf("Memory reallocation failed!");
        exit(1);
    }

    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = elem;
    n = n + 1;
}

void del() {
    printf("\nEnter the position of the element to be deleted: ");
    scanf("%d", &pos);
    pos = pos - 1;
    elem = a[pos];

    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n = n - 1;
    a = (int *)realloc(a, n * sizeof(int));

    printf("\nThe deleted element is: %d\n", elem);
}

int main() {
    int ch;
    create();
    display();

    while (1) {
        printf("\n\n-------- Menu ----------\n");
        printf("1. Insert\n2. Delete\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: 
                insert();
                display();
                break;
            case 2: 
                del();
                display();
                break;
            case 3: 
                free(a);
                return 0;
            default: 
                printf("\nInvalid choice:\n");
                break;
        }
    }
}