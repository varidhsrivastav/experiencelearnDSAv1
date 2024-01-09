#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendCircularList(struct Node** head1, struct Node** head2) {
    struct Node* temp = *head1;
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    while (temp->next != *head1) {
        temp = temp->next;
    }
    temp->next = *head2;

    while ((*head2)->next != NULL) {
        *head2 = (*head2)->next;
    }

    (*head2)->next = *head1;
}

void printCircularList(struct Node* head) {
    struct Node* temp = head;

    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf(" (head)\n");
    } else {
        printf("Empty circular list.\n");
    }
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    if (head != NULL) {
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = head1; 

    head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = createNode(6);

    printf("Circular List 1: ");
    printCircularList(head1);

    printf("List 2: ");
    printCircularList(head2);

    appendCircularList(&head1, &head2);

    printf("Combined Circular List: ");
    printCircularList(head1);

    freeList(head1);  

    return 0;
}
