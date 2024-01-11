#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int evaluatePostfixExpression(char* postfixExpression) {
    struct Stack* stack = createStack();
    int len = strlen(postfixExpression);

    for (int i = 0; i < len; i++) {
        if (isdigit(postfixExpression[i])) {
            push(stack, postfixExpression[i] - '0');
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (postfixExpression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator in expression.\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (!isEmpty(stack)) {
        int result = pop(stack);
        if (isEmpty(stack)) {
            return result;
        } else {
            printf("Invalid expression format.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Empty expression.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char postfixExpression[100];
    printf("Enter a postfix expression: ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);

    int result = evaluatePostfixExpression(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}