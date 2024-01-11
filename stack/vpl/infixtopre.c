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

void infixToPrefix(char* infixExpression, char* prefixExpression) {
    struct Stack* operandStack = createStack();
    struct Stack* operatorStack = createStack();
    int i = strlen(infixExpression) - 1, j = 0;
    char ch, popped;

    while (i >= 0) {
        ch = infixExpression[i--];

        if (ch >= 'a' && ch <= 'z') {
            prefixExpression[j++] = ch;
        } else if (ch == ')') {
            push(operatorStack, ch);
        } else if (ch == '(') {
            while (!isEmpty(operatorStack) && operatorStack->top->data != ')') {
                popped = pop(operatorStack);
                prefixExpression[j++] = popped;
            }
            pop(operatorStack); 
        } else {
            while (!isEmpty(operatorStack) && precedence(ch) < precedence(operatorStack->top->data)) {
                popped = pop(operatorStack);
                prefixExpression[j++] = popped;
            }
            push(operatorStack, ch);
        }
    }

    while (!isEmpty(operatorStack)) {
        popped = pop(operatorStack);
        prefixExpression[j++] = popped;
    }
    prefixExpression[j] = '\0';

    int len = strlen(prefixExpression);
    for (int k = 0; k < len / 2; k++) {
        char temp = prefixExpression[k];
        prefixExpression[k] = prefixExpression[len - k - 1];
        prefixExpression[len - k - 1] = temp;
    }
}

int main() {
    char infixExpression[100], prefixExpression[100];
    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPrefix(infixExpression, prefixExpression);

    printf("Prefix expression: %s\n", prefixExpression);

    return 0;
}