#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int isOperand(char c) {
    // Check if character is a letter (A-Z or a-z) or a digit (0-9)
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {

        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        }
        
        else if (isOperator(infix[i])) {
            push(infix[i]);
        }
    }


    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
