#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int ele) {
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = ele;
        printf("Pushed element: %d\n", ele);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        int pele = stack[top];
        printf("Popped element: %d\n", pele);
        top--;
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, ch;
    while (1) {
        printf("\nEnter 1 for push, 2 for pop, 3 for display, 4 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &ch);
                push(ch);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

