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
// insert at front
Node * insertFront(Node * head, int data){
    
}
// insert at end
Node * InsertatEnd(Node * head, int data){
    Node * newnode = NULL;
    Node *curr;
    newnode=create(data);
    if(head==NULL){
        return head;
    }
    curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
        curr->next=newnode;
        newnode->prev=curr;
        return head;

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

int main(){
    Node* head=NULL;
    int data;
    int data2=30;
    int data3=40;
    int data4=50;
    printf("Enter the data in the node");
    scanf("%d", &data);
    head=create(data);
    // display(head);
    InsertatEnd(head, data2);
    // display(head);
    InsertatEnd(head, data3);
    // display(head);
    InsertatEnd(head, data4);
    display(head);
    return 0;
}