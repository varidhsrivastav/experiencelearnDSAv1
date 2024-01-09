#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node * createNode(int data){
    Node * NewNode= NULL;
    NewNode = (Node *)malloc(sizeof(Node)); 
    if (NewNode == NULL) {
        printf("Memory allocation failed.\n");
}else{
    NewNode->data=data;
    NewNode->next=NULL;
    NewNode->prev=NULL;
}
return NewNode;
}
// insert at rear
// curr=curr->next;
// curr->next=new;
// new-prev=curr;
Node * insertAtrear(Node *head, int data){
    Node *new, *curr;
    new = createNode(data);
    if(head==NULL){
        return new;
    }
    curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=new;
    new->prev=curr;
    return head;
}

void display(Node * head){
    Node * curr;
    if(head == NULL){
        printf("\nList is empty.");
        return;
    }
    printf("header -->");
    for(curr=head; curr!=NULL; curr=curr->next){
        printf("%d ->", curr->data);
        }
}

int main(){
    Node * head = NULL;
    int data;
    printf("Enter the data in the node");
    scanf("%d", &data);
    head=createNode(data);
    display(head);
    for(int i=0; i<3; i++){
    printf("Enter the data in the node");
    int data2;
    scanf("%d", &data2);
    insertAtrear(head,data2);
    }
    display(head);
    return 0;
}
