#include <stdio.h>

#define SIZE 5

typedef struct CircularQueue {
   int items[SIZE];
   int front;
   int rear;
} CircularQueue;

int is_full(CircularQueue* queue) {
   return (queue->rear + 1) % SIZE == queue->front;
}

int is_empty(CircularQueue* queue) {
   return queue->front == queue->rear;
}

void enqueue(CircularQueue* queue, int data) {
   if(is_full(queue)) {
       printf("Queue is full. Cannot enqueue %d\n", data);
       return;
   }

   queue->items[queue->rear] = data;
   queue->rear = (queue->rear + 1) % SIZE;
}

int dequeue(CircularQueue* queue) {
   if(is_empty(queue)) {
       printf("Queue is empty. Cannot dequeue\n");
       return -1;
   }

   int data = queue->items[queue->front];
   queue->front = (queue->front + 1) % SIZE;

   return data;
}

int main() {
   CircularQueue queue = {.front = 0, .rear = 0};

   enqueue(&queue, 10);
   enqueue(&queue, 20);
   enqueue(&queue, 30);
   enqueue(&queue, 40);
   enqueue(&queue, 50); 

   printf("Dequeued value: %d\n", dequeue(&queue));
   printf("Dequeued value: %d\n", dequeue(&queue));
   printf("Dequeued value: %d\n", dequeue(&queue));
   printf("Dequeued value: %d\n", dequeue(&queue));
   printf("Dequeued value: %d\n", dequeue(&queue)); 

   return 0;
}