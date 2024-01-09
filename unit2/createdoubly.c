#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initCircularLinkedList(int n) {
    if (n == 0) {
        return NULL;
    }

    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 1;
    head->next = head;

    Node* current = head;

    for (int i = 2; i <= n; i++) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = head;

        current->next = new_node;
        current = new_node;
    }

    return head;
}

int main() {
    int numnode;
    printf("Enter the number of node ");
    scanf("%d", &numnode);
    Node* head = initCircularLinkedList(numnode);
    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    return 0;
}