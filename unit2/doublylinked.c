#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void printList(Node *head) {
    Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void deleteEven(Node **head_ref) {
    if (*head_ref == NULL)
        return;

    Node *current = *head_ref;
    Node *next;

    do {
        if (current->data % 2 == 0) {
            if (current->prev != NULL)
                current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            next = current->next;
            free(current);
            current = next;
        } else {
            current = current->next;
        }
    } while (current != *head_ref);
}

int main() {
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(4);
    head->next->next->next->prev = head->next->next;
    printf("Original Doubly linked list: \n");
    printList(head);
    printf("Doubly linked list after deletion of even values: \n");
    deleteEven(&head);
    printList(head);
    return 0;
}