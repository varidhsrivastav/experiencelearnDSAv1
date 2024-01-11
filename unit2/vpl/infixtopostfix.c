#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
    // commented turbo
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

int precedence(char operator) {
    if (operator == '^') {
        return 3;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    }
    return -1;
}

void infixToPostfix(char* infixExpression, char* postfixExpression) {
    struct Stack* stack = createStack();
    int i = 0, j = 0;
    char ch, popped;

    while ((ch = infixExpression[i++]) != '\0') {
        if (ch >= 'a' && ch <= 'z') {
            postfixExpression[j++] = ch;
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && stack->top->data != '(') {
                popped = pop(stack);
                postfixExpression[j++] = popped;
            }
            pop(stack); 
        } else {
            while (!isEmpty(stack) && precedence(ch) <= precedence(stack->top->data)) {
                popped = pop(stack);
                postfixExpression[j++] = popped;
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        popped = pop(stack);
        postfixExpression[j++] = popped;
    }
    postfixExpression[j] = '\0';
}

int main() {
    char infixExpression[100], postfixExpression[100];
    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}