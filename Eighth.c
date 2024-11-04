/*Design, Develop and Implement a menu driven Program in C for the following operations on Singly
Linked List (SLL)
a. Create a SLL.
b. Insert at Beginning
c. Insert at Last
d. Insert at any random location
e. Delete from Beginning
f. Delete from Last
g. Delete node after specified location
h. Search for an element
i. Show
j. Exit*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createSLL() {
    Node *head = NULL, *temp = NULL;
    int data;
    char choice;

    do {
        printf("Enter data for node: ");
        scanf("%d", &data);
        Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtLast(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position) {
    Node *newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromLast(Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAfterPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    Node *temp = *head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after the given position\n");
        return;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void searchElement(Node *head, int data) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", data);
}

void showList(Node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    Node *temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a Singly Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at any random location\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Last\n");
        printf("7. Delete node after specified location\n");
        printf("8. Search for an element\n");
        printf("9. Show\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createSLL();
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromLast(&head);
                break;
            case 7:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 8:
                printf("Enter element to search for: ");
                scanf("%d", &data);
                searchElement(head, data);
                break;
            case 9:
                showList(head);
                break;
            case 10:
                while (head != NULL) {
                    Node *temp = head;
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