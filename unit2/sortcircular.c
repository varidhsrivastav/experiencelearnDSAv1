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

struct Node* findNode(struct Node* head, int data) {
    struct Node* temp = head;
    if (head == NULL) {
        return NULL;
    }
    do {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL; 
}

void swapNodes(struct Node** head, int x, int y) {
    if (x == y) {
        return;
    }
    struct Node *prevX = NULL, *currX = *head;
    struct Node *prevY = NULL, *currY = *head;

    while (currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
    while (currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == *head) {
        *head = currY;
    } else if (currY == *head) {
        *head = currX;
    }

    if (prevX != NULL) {
        prevX->next = currY;
    }
    if (prevY != NULL) {
        prevY->next = currX;
    }

    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
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
    struct Node* head = NULL;

    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head;

    printf("Original Circular List: ");
    printCircularList(head);

    swapNodes(&head, 2, 4);

    printf("Circular List after swapping nodes 2 and 4: ");
    printCircularList(head);

    freeList(head);

    return 0;
}
