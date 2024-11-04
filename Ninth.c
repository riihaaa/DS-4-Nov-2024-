/*Design, Develop and Implement a menu driven Program in C/C++ for the following operations on Doubly
Linked List (DLL)
a. Create a DLL.
b. Print all the elements in DLL in forward traversal order
c. Print all elements in DLL in reverse traversal order
d. Exit*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createDLL() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    char choice;

    do {
        printf("Enter data for node: ");
        scanf("%d", &data);
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

void printForward(Node* head) {
    Node* temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printReverse(Node* tail) {
    Node* temp = tail;
    printf("Reverse Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a Doubly Linked List\n");
        printf("2. Print all elements in DLL in forward traversal order\n");
        printf("3. Print all elements in DLL in reverse traversal order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createDLL();
                // Set tail to the last node for reverse printing
                tail = head;
                while (tail && tail->next != NULL) {
                    tail = tail->next;
                }
                break;
            case 2:
                printForward(head);
                break;
            case 3:
                printReverse(tail);
                break;
            case 4:
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}