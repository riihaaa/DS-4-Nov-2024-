/*Design, Develop and Implement a menu driven Program in C for the following operations on Circular QUEUE
of Characters
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit*/
#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    char *arr;
    int front;
    int rear;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int capacity) {
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (char *)malloc(capacity * sizeof(char));
    return queue;
}

int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

void enqueue(CircularQueue *queue, char value) {
    if (isFull(queue)) {
        printf("Overflow: Queue is full. Cannot insert '%c'.\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
    printf("Inserted '%c' into the queue.\n", value);
}

char dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Underflow: Queue is empty. Cannot delete.\n");
        return '\0';
    }
    char value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return value;
}

void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%c ", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    int capacity;
    printf("Enter the capacity of the circular queue: ");
    scanf("%d", &capacity);
    CircularQueue *queue = createQueue(capacity);
    
    int choice;
    char value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != '\0') {
                    printf("Deleted '%c' from the queue.\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                free(queue->arr);
                free(queue);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}