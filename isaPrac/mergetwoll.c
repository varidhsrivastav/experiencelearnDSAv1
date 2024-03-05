#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    if (l1) {
        current->next = l1;
    } else if (l2) {
        current->next = l2;
    }
    
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// Function to create a new node with given data
struct ListNode* newNode(int data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Creating first linked list: 1 -> 3 -> 5
    struct ListNode* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);
    
    // Creating second linked list: 2 -> 4 -> 6
    struct ListNode* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);
    
    // Merging the two linked lists
    struct ListNode* mergedList = mergeTwoLists(l1, l2);
    
    // Printing the merged linked list
    printf("Merged Linked List: ");
    printList(mergedList);
    
    return 0;
}
