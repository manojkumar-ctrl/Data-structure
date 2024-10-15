#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop the top element from the stack
char pop() {
    return stack[top--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if a character is an operand (a letter or number)
int isOperand(char c) {
    // Check if character is a letter (A-Z or a-z) or a digit (0-9)
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        // If character is operand, add it to output
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If character is operator, push it onto stack
        else if (isOperator(infix[i])) {
            push(infix[i]);
        }
    }

    // Pop all operators from the stack and add to output
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
