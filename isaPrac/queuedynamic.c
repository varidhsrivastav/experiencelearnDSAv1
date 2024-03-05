#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct
{
    int *array;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->array = (int *)malloc(capacity * sizeof(int));
    if (!queue->array)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
    return queue->size == queue->capacity;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

// Function to resize the queue
void resizeQueue(Queue *queue, int newCapacity)
{
    queue->array = (int *)realloc(queue->array, newCapacity * sizeof(int));
    if (!queue->array)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = newCapacity;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        // If the queue is full, resize it
        int newCapacity = queue->capacity * 2;
        resizeQueue(queue, newCapacity);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to peek the front element of the queue
int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->array[queue->front];
}

// Function to display the elements of the queue
void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = 0; i < queue->size; ++i)
    {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main()
{
    // Create a queue with capacity 5
    Queue *queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Display the elements of the queue
    display(queue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Display the elements of the queue after dequeue
    display(queue);

    // Enqueue more elements into the queue
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    // Display the elements of the queue after enqueue
    display(queue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Display the elements of the queue after dequeue
    display(queue);

    // Free memory allocated for the queue array and the queue structure itself
    free(queue->array);
    free(queue);

    return 0;
}
