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

void deleteNode(Node **head_ref, Node *del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != *head_ref) {
        Node *temp = *head_ref;
        while (temp->next != del)
            temp = temp->next;
        temp->next = del->next;
    }

    free(del);
    return;
}

void deleteByValue(Node **head_ref, int val) {
    if (*head_ref == NULL)
        return;

    Node *current = *head_ref;
    if (current->data == val) {
        *head_ref = current->next;
        free(current);
        current = *head_ref;
    }

    while (current->next != *head_ref) {
        if (current->next->data == val) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    if ((*head_ref)->data == val) {
        Node *temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
}

int main() {
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = head;
    printf("Original Circular linked list: \n");
    printList(head);
    int value = 2;
    printf("Deleting all nodes with value %d: \n", value);
    deleteByValue(&head, value);
    printf("Modified Circular linked list: \n");
    printList(head);

    return 0;
}