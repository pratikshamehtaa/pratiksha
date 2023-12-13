#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top];
    top--;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePrefix(char expression[]) {
    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            int operand1 = pop();
            int operand2 = pop();

            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }

    return pop();
}

int main() {
    char prefixExpression[MAX_SIZE];

    printf("Enter the prefix expression: ");
    fgets(prefixExpression, MAX_SIZE, stdin);
    prefixExpression[strlen(prefixExpression) - 1] = '\0'; // Remove the newline character

    int result = evaluatePrefix(prefixExpression);

    printf("Result of the prefix expression: %d\n", result);

    return 0;
}
