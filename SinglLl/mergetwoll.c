// How to merge two sorted linked list ?
#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of a linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node* merged_list = NULL;

    // Base cases
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    // Pick the smaller value
    if (l1->data <= l2->data) {
        merged_list = l1;
        merged_list->next = mergeSortedLists(l1->next, l2);
    } else {
        merged_list = l2;
        merged_list->next = mergeSortedLists(l1, l2->next);
    }

    return merged_list;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    // Create two sorted linked lists
    append(&l1, 1);
    append(&l1, 3);
    append(&l1, 5);

    append(&l2, 2);
    append(&l2, 4);
    append(&l2, 6);

    // Merge the two sorted linked lists
    Node* merged_list = mergeSortedLists(l1, l2);

    // Print the merged linked list
    printList(merged_list);

    return 0;
}




					// 😉😉😉😉Please upvote if it helps 😉😉😉😉
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
// 	    // if list1 happen to be NULL
// 		// we will simply return list2.
//         if(list1 == NULL)
//             return list2;
		
// 		// if list2 happen to be NULL
// 		// we will simply return list1.
//         if(list2 == NULL)
//             return list1;
        
//         ListNode * ptr = list1;
//         if(list1 -> val > list2 -> val)
//         {
//             ptr = list2;
//             list2 = list2 -> next;
//         }
//         else
//         {
//             list1 = list1 -> next;
//         }
//         ListNode *curr = ptr;
        
// 		// till one of the list doesn't reaches NULL
//         while(list1 &&  list2)
//         {
//             if(list1 -> val < list2 -> val){
//                 curr->next = list1;
//                 list1 = list1 -> next;
//             }
//             else{
//                 curr->next = list2;
//                 list2 = list2 -> next;
//             }
//             curr = curr -> next;
                
//         }
		
// 		// adding remaining elements of bigger list.
//         if(!list1)
//             curr -> next = list2;
//         else
//             curr -> next = list1;
            
//         return ptr;
       
//     }
// };