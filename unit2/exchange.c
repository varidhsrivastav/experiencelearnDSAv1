#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void exchangeNodes(struct Node** head, int x, int y) {
    if (x == y) {
        return;
    }

    struct Node *nodeX = NULL, *nodeY = NULL;
    struct Node *temp = *head;

    while (temp != NULL) {
        if (temp->data == x) {
            nodeX = temp;
        } else if (temp->data == y) {
            nodeY = temp;
        }
        temp = temp->next;
    }

    if (nodeX == NULL || nodeY == NULL) {
        return;
    }

    if (nodeX->prev != NULL) {
        nodeX->prev->next = nodeY;
    } else {
        *head = nodeY;
    }

    if (nodeY->prev != NULL) {
        nodeY->prev->next = nodeX;
    } else {
        *head = nodeX;
    }

    if (nodeX->next != NULL) {
        nodeX->next->prev = nodeY;
    }
    if (nodeY->next != NULL) {
        nodeY->next->prev = nodeX;
    }

    struct Node* tempPrev = nodeX->prev;
    struct Node* tempNext = nodeX->next;
    nodeX->prev = nodeY->prev;
    nodeX->next = nodeY->next;
    nodeY->prev = tempPrev;
    nodeY->next = tempNext;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Example usage
int main() {
    struct Node* head = NULL;
    
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    display(head);

    exchangeNodes(&head, 2, 4);

    printf("List after exchanging nodes with data 2 and 4: ");
    display(head);

    deleteList(&head);

    return 0;
}
