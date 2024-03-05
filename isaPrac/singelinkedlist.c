#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// insert
Node *createNewList(Node *head, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    head=newNode;
    return head;
}

Node * createll(Node * head,int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head==NULL)
        head=newNode;
    else{
        struct Node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        } 
        temp->next=newNode;
    }
    return head;
    
}
Node * insertatfront(Node * head, int val){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return head;
    }else{
        newNode->next=head;
        head=newNode;
    }
        return head;
}
Node*insertatIndex(Node *head, int val, int pos){
    Node * newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    if(pos==0 || head==NULL){
        newNode->next=head;
        head=newNode;
        return head;
    }else{
        int temp=1;
        Node *temp2=head;
        temp2=head;
        while((temp < (pos-1)) && (temp2->next!=NULL)){
            temp++;
            temp2=temp2->next;
        }
        printf("temp2 data =%d",temp2->data);
        printf("temp data =%d",temp);

        newNode->next=temp2->next;
        temp2->next=newNode;
    }
    return head;
}
Node*insertafterIndex(Node *head, int val, int pos){
    Node * newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    if(pos==0 || head==NULL){
        newNode->next=head;
        head=newNode;
        return head;
    }else{
        int temp=1;
        Node *temp2=head;
        temp2=head;
        while((temp < (pos-1)) && (temp2->next!=NULL)){
            temp++;
            temp2=temp2->next;
        }
        newNode->next=temp2->next->next;
        temp2->next->next=newNode;
    }
    return head;
}

Node * sortList(Node * head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node * current = head;
    Node * next = NULL;
    int swapped = 1;

    while (swapped) {
        swapped = 0;
        current = head;
        while (current->next != next) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        next = current;
    }

    return head;
}

// delete
Node* deleteFront(Node * head)
{
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
   Node * temp = head;
   head = head->next;
   free(temp);
   return head;
}

Node* deleteLast(Node * head)
{
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
   if(head->next == NULL)
   {
      free(head);
      return NULL;
   }
   Node * current = head;
   Node * previous = NULL;
   while(current->next != NULL)
   {
      previous = current;
      current = current->next;
   }
   previous->next = NULL;
   free(current);
   return head;
}


void display(struct Node * head){
    struct Node * ptr=head;
    if(head==NULL){
        printf("List is empty\n");
    }
    printf("The list is:\n");
        printf("HEAD-> \t");
    while(ptr != NULL) {
        printf("%d ->\t",ptr->data);
        ptr=ptr->next;
        }
        printf("NULL\n");
}

int main(){
    Node * head= (Node *)malloc(sizeof(Node));
    head=NULL;
    for(int i=1;i<=5;i++){
        head=createll(head,i);
    }
    display(head);
     head=insertatfront(head,0);
     display(head);
     head=insertatIndex(head,56,3);
     display(head);
     head=insertafterIndex(head,55,3);
     display(head);
      head = sortList(head);
    display(head);
    printf("deletin last element");
    head=deletelast(head);
    display(head);
    printf("Deleting first element");
    head=deleteFront(head);
    display(head);
    return 0;
}

