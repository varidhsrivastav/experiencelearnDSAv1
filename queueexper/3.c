#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    Node* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

int dequeue(Node** head) {
    if(*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = *head;
    int data = temp->data;
    *head = temp->next;
    free(temp);

    return data;
}

int main() {
    Node* head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);

    printf("Dequeued value: %d\n", dequeue(&head));
    printf("Dequeued value: %d\n", dequeue(&head));

    enqueue(&head, 40);
    enqueue(&head, 50);

    printf("Dequeued value: %d\n", dequeue(&head));
    printf("Dequeued value: %d\n", dequeue(&head));

    return 0;
}