#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
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

void sortedInsert(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        Node *current = *head_ref;
        while (current->next != *head_ref && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    Node *head = NULL;
    sortedInsert(&head, 5);
    sortedInsert(&head, 10);
    sortedInsert(&head, 0);
    sortedInsert(&head, 15);
    sortedInsert(&head, 2);
    sortedInsert(&head, 7);
    sortedInsert(&head, 12);
    printf("Original Circular linked list: \n");
    printList(head);
    int value = 8;
    printf("Inserting node with value %d: \n", value);
    sortedInsert(&head, value);
    printf("Modified Circular linked list: \n");
    printList(head);
    return 0;
}