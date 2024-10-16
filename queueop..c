#include <stdio.h>
#define SIZE 5

int isFull(int rear) {
    return (rear == SIZE - 1);
}

int isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void insert(int queue[], int *front, int *rear, int value) {
    if (isFull(*rear)) {
        printf("Queue Overflow: Cannot insert %d, queue is full.\n", value);
    } else {
        if (*front == -1) *front = 0;
        (*rear)++;
        queue[*rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

void delete(int queue[], int *front, int rear) {
    if (isEmpty(*front, rear)) {
        printf(" Queue is empty\n");
    } else {
        printf("%d deleted from the queue.\n", queue[*front]);
        (*front)++;
    }
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[SIZE];
    int front = -1;
    int rear = -1;
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(queue, &front, &rear, value);
                break;
            case 2:
                delete(queue, &front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
