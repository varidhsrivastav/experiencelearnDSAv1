#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(char data) {
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

void push(struct Stack* stack, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    char popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void prefixToPostfix(char* prefixExpression, char* postfixExpression) {
    struct Stack* stack = createStack();
    int len = strlen(prefixExpression);
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefixExpression[i];

        if (isOperand(ch)) {
            postfixExpression[j++] = ch;
        } else {
            char operand1 = pop(stack);
            char operand2 = pop(stack);
            postfixExpression[j++] = operand1;
            postfixExpression[j++] = operand2;
            postfixExpression[j++] = ch;
        }
    }

    while (!isEmpty(stack)) {
        postfixExpression[j++] = pop(stack);
    }
    postfixExpression[j] = '\0';

    len = strlen(postfixExpression);
    for (int k = 0; k < len / 2; k++) {
        char temp = postfixExpression[k];
        postfixExpression[k] = postfixExpression[len - k - 1];
        postfixExpression[len - k - 1] = temp;
    }
}

int main() {
    char prefixExpression[100], postfixExpression[100];
    printf("Enter a prefix expression: ");
    fgets(prefixExpression, sizeof(prefixExpression), stdin);

    prefixToPostfix(prefixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}