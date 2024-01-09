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

struct Node* extractSublist(struct Node** head, int start, int end) {
    if (*head == NULL || start > end) {
        return NULL;
    }

    struct Node *current = *head;
    int count = 1;

    while (current != NULL && count < start) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return NULL;
    }

    struct Node* sublistHead = current;

    while (current != NULL && count < end) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return NULL;
    }

    struct Node* sublistEnd = current;
    struct Node* nextAfterSublist = current->next;

    if (sublistEnd->next != NULL) {
        sublistEnd->next->prev = NULL;
    }
    sublistEnd->next = NULL;

    if (sublistHead->prev != NULL) {
        sublistHead->prev->next = nextAfterSublist;
    } else {
        *head = nextAfterSublist;
    }

    return sublistHead;
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

void displaySublist(struct Node* sublistHead) {
    printf("Extracted sublist: ");
    while (sublistHead != NULL) {
        printf("%d ", sublistHead->data);
        sublistHead = sublistHead->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    display(head);

    struct Node* extractedSublist = extractSublist(&head, 2, 4);

    displaySublist(extractedSublist);

    printf("List after extracting sublist: ");
    display(head);

    deleteList(&head);

    return 0;
}
