#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define the circular queue structure
typedef struct
{
    Node *rear;
} CircularQueue;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new empty circular queue
CircularQueue *createCircularQueue()
{
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!cq)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    cq->rear = NULL;
    return cq;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue *cq)
{
    return (cq->rear == NULL);
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue *cq, int data)
{
    Node *newNode = createNode(data);
    if (isEmpty(cq))
    {
        cq->rear = newNode;
        newNode->next = newNode; // Point to itself to form a circular link
    }
    else
    {
        newNode->next = cq->rear->next;
        cq->rear->next = newNode;
        cq->rear = newNode;
    }
    printf("%d enqueued to circular queue\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int data;
    if (cq->rear->next == cq->rear)
    { // Only one element in the circular queue
        data = cq->rear->data;
        free(cq->rear);
        cq->rear = NULL;
    }
    else
    {
        Node *temp = cq->rear->next;
        data = temp->data;
        cq->rear->next = temp->next;
        free(temp);
    }
    return data;
}

// Function to peek the front element of the circular queue
int peek(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return cq->rear->next->data;
}

// Function to display the elements of the circular queue
void display(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Circular queue is empty\n");
        return;
    }
    Node *current = cq->rear->next;
    printf("Circular queue elements: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cq->rear->next);
    printf("\n");
}

int main()
{
    // Create an empty circular queue
    CircularQueue *cq = createCircularQueue();

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

    // Display the elements of the circular queue after enqueue
    display(cq);

    // Dequeue elements from the circular queue
    printf("Dequeued element: %d\n", dequeue(cq));
    printf("Dequeued element: %d\n", dequeue(cq));

    // Display the elements of the circular queue after dequeue
    display(cq);

    // Free memory allocated for the circular queue structure itself will automatically free the nodes
    free(cq);

    return 0;
}
