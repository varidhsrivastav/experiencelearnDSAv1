#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int size;
    int* Q;
};

struct Queue* createQueue(int size) {
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->size = size;
    Q->front = Q->rear = -1;
    Q->Q = (int*)malloc(Q->size * sizeof(int));
    return Q;
}

int isFull(struct Queue* Q) {
    if ((Q->rear + 1) % Q->size == Q->front)
        return 1;
    return 0;
}

int isEmpty(struct Queue* Q) {
    if (Q->front == -1)
        return 1;
    return 0;
}

void enQueue(struct Queue* Q, int value) {
    if (isFull(Q)) {
        printf("Full\n");
        return;
    }
    if (Q->front == -1)
        Q->front = 0;
    Q->rear = (Q->rear + 1) % Q->size;
    Q->Q[Q->rear] = value;
    printf("Inserted %d\n", value);
}

int deQueue(struct Queue* Q) {
    int value = -1;
    if (isEmpty(Q)) {
        printf("Empty\n");
        return -1;
    }
    value = Q->Q[Q->front];
    if (Q->front == Q->rear) {
        Q->front = Q->rear = -1;
    }
    else {
        Q->front = (Q->front + 1) % Q->size;
    }
    return value;
}

int main() {
    struct Queue* Q = createQueue(5);

    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    enQueue(Q, 5);

    printf("%d\n", deQueue(Q));
    printf("%d\n", deQueue(Q));

    enQueue(Q, 6);
    enQueue(Q, 7);

    printf("%d\n", deQueue(Q));
    printf("%d\n", deQueue(Q));

    return 0;
}