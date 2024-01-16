#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

typedef struct {
    DynamicArray array;
} Queue;

DynamicArray createDynamicArray() {
    DynamicArray array;
    array.data = (int *) malloc(1 * sizeof(int));
    array.size = 0;
    array.capacity = 1;
    return array;
}

void insertIntoDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *) realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = element;
}
int deleteFromDynamicArray(DynamicArray *array) {
    if (array->size == 0) {
        printf("Queue is empty. Cannot delete an element.\n");
        exit(0);
    }
    int deletedElement = array->data[0];
    for (int i = 0; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    return deletedElement;
}

Queue createQueue() {
    Queue queue;
    queue.array = createDynamicArray();
    return queue;
}

int isQueueEmpty(Queue queue) {
    return queue.array.size == 0;
}

void enqueue(Queue *queue, int element) {
    insertIntoDynamicArray(&queue->array, element);
}

int dequeue(Queue *queue) {
    return deleteFromDynamicArray(&queue->array);
}

int front(Queue queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot get the front element.\n");
        exit(0);
    }
    return queue.array.data[0];
}

int size(Queue queue) {
    return queue.array.size;
}

int main() {
    Queue queue = createQueue();
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Front element of the queue is %d\n", front(queue));
    printf("Size of the queue is %d\n", size(queue));
    printf("Dequeued element is %d\n", dequeue(&queue));
    printf("Dequeued element is %d\n", dequeue(&queue));
    printf("Front element of the queue is %d\n", front(queue));
    printf("Size of the queue is %d\n", size(queue));
    return 0;
}