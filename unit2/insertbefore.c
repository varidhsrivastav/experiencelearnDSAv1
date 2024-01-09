#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node * create(int data){
    Node * new = NULL;
    new = (Node *)malloc(sizeof(Node));
    if(new==NULL){
        printf("Memory Allocation Fial");
        return 0;
    }else{
        new->data=data;
        new->next=NULL;
        new->prev=NULL;
    }
    return new;
}
void display(Node* head){
    Node * ptr;
    if(head==NULL){
        printf("Null");
        return;
    }else{
        for(ptr=head; ptr!=NULL; ptr=ptr->next){
            printf("%d ->", ptr->data);
        }
    }
}

Node * insertBefore(Node * head, int before, int data){
    Node * newNode = create(data);
    if(head == NULL || newNode == NULL){
        return NULL;
    }
    Node * temp = head;
    while(temp != NULL){
        if(temp->data == before){
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    Node *head = create(10);
    head->next = create(20);
    head->next->prev = head;
    head->next->next = create(30);
    head->next->next->prev = head->next;
    printf("data before entering \n");
    display(head);
    head = insertBefore(head, 20, 25);
    printf("\n data after entering \n");
    display(head);
    return 0;
}