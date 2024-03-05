#include <stdio.h>
#include <stdlib.h>

// Define the circular queue structure
typedef struct {
    int* array;
    int capacity;
    int front;
    int rear;
    int size;
} CircularQueue;

// Function to create a new circular queue
CircularQueue* createCircularQueue(int capacity) {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (!cq) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    cq->array = (int*)malloc(capacity * sizeof(int));
    if (!cq->array) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    cq->capacity = capacity;
    cq->front = -1;
    cq->rear = -1;
    cq->size = 0;
    return cq;
}

// Function to check if the circular queue is full
int isFull(CircularQueue* cq) {
    return (cq->size == cq->capacity);
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* cq) {
    return (cq->size == 0);
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* cq, int data) {
    if (isFull(cq)) {
        printf("Circular queue is full\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % cq->capacity;
    cq->array[cq->rear] = data;
    cq->size++;
    printf("%d enqueued to circular queue\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = cq->array[cq->front];
    if (cq->front == cq->rear) { // Last element in the circular queue
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->capacity;
    }
    cq->size--;
    return data;
}

// Function to peek the front element of the circular queue
int peek(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return cq->array[cq->front];
}

// Function to display the elements of the circular queue
void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty\n");
        return;
    }
    printf("Circular queue elements: ");
    int i = cq->front;
    int count = 0;
    while (count < cq->size) {
        printf("%d ", cq->array[i]);
        i = (i + 1) % cq->capacity;
        count++;
    }
    printf("\n");
}

int main() {
    // Create a circular queue with capacity 5
    CircularQueue* cq = createCircularQueue(5);

    // Enqueue elements into the circular queue
    enqueue(cq, 1);
    enqueue(cq, 2);
    enqueue(cq, 3);

    // Display the elements of the circular queue
    display(cq);

    // Dequeue elements from the circular queue
    printf("Dequeued element: %d\n", dequeue(cq));
    printf("Dequeued element: %d\n", dequeue(cq));

    // Display the elements of the circular queue after dequeue
    display(cq);

    // Enqueue more elements into the circular queue
    enqueue(cq, 4);
    enqueue(cq, 5);
    enqueue(cq, 6);

    // Display the elements of the circular queue after enqueue
    display(cq);

    // Dequeue elements from the circular queue
    printf("Dequeued element: %d\n", dequeue(cq));
    printf("Dequeued element: %d\n", dequeue(cq));

    // Display the elements of the circular queue after dequeue
    display(cq);

    // Free memory allocated for the circular queue array and the circular queue structure itself
    free(cq->array);
    free(cq);

    return 0;
}
