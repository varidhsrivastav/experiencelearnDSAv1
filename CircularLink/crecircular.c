// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node *next;
// };

// struct Node * traverse(struct Node * head){
//     struct Node *ptr;
//     while(ptr !=head){
//         printf("Element: %d \n", ptr->data);
//         ptr=ptr->next;
//     }
// }

// int main(){
//     struct Node * head = (struct Node * )malloc (sizeof (struct Node)); 
//     struct Node * second = (struct Node * )malloc (sizeof (struct Node)); 
//     struct Node * third = (struct Node * )malloc (sizeof (struct Node)); 
//     struct Node * fourth = (struct Node * )malloc (sizeof (struct Node)); 
//     struct Node * fifth = (struct Node * )malloc (sizeof (struct Node)); 
//     head->data=7;
//     head->next=second;
//     second->data=8;
//     second->next=third;
//     third->data=9;
//     third->next=fourth;
//     fourth->data=10;
//     fourth->next=fifth;
//     fifth->data=11;
//     fifth->next=head;
//     traverse(head);
//     return 0;
//     }



//     // create nd print the circular linked list in c?

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createCircularLinkedList(struct Node **head_ref) {
    struct Node *temp = NULL;
    struct Node *head = NULL;
    int data;
    int choice;

    do {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = head;
        head = temp;
        printf("Do you want to continue? 1/0: ");
        scanf("%d", &choice);
    } while (choice == 1);

    *head_ref = head;
}

void printCircularLinkedList(struct Node *head) {
    struct Node *temp = head;

    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
int main() {
    struct Node *head = NULL;

    createCircularLinkedList(&head);
    printCircularLinkedList(head);

    return 0;
}