#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void makeCircular(struct ListNode* head) {
    if(head == NULL) {
        return;
    }
    
    struct ListNode* temp = head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = head;
}

void printCircularList(struct ListNode* head) {
    if(head == NULL) {
        return;
    }
    
    struct ListNode* temp = head;
    
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = 1;

    head->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->val = 2;

    head->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next->next->val = 3;

    head->next->next->next = NULL;

    makeCircular(head);

    printCircularList(head);

    return 0;
}