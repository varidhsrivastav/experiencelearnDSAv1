#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct {
    int* array;
    int capacity;
    int top;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->array = (int*)malloc(capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        // If the stack is full, resize it
        int newCapacity = stack->capacity * 2;
        stack->array = (int*)realloc(stack->array, newCapacity * sizeof(int));
        if (!stack->array) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top];
}

// Function to resize the stack
void resizeStack(Stack* stack, int newCapacity) {
    stack->array = (int*)realloc(stack->array, newCapacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = newCapacity;
}

int main() {
    // Create a stack with capacity 5
    Stack* stack = createStack(5);

    // Push elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    
    // Resize the stack
    resizeStack(stack, 10);

    // Push more elements onto the stack after resizing
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);

    // Peek and pop elements from the stack
    printf("Top element of the stack: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element of the stack after pop: %d\n", peek(stack));

    // Free memory allocated for the stack array and the stack structure itself
    free(stack->array);
    free(stack);

    return 0;
}
