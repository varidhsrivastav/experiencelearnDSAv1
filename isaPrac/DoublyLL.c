#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
struct Node * insertatPos(struct Node * head, int data, int pos){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    int currpos=1;
    struct Node * curr;
    if((pos<=1) || (head==NULL)){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return head;
    }else{
        curr=head;
        while((curr->next!=NULL) &&( currpos < (pos-1)) ){
            curr=curr->next;
            currpos++;
        }
       newNode->next=curr->next;
       newNode->prev=curr;
       curr->next=newNode;
       if(curr->next != NULL)
       (curr->next)->prev=newNode;
       
    }
    return head;
}
Node * inserinBetween(Node *head,int val,int pos){
   Node * newNode=(Node *)malloc(sizeof(Node));
   newNode->data=val;
    newNode->prev=NULL;
   if(pos<=1 || head==NULL){
    newNode->next = head;
    head->prev=newNode;
    head=newNode;
    return head;
   }else{
    Node *temp=head;
    int temp2=1;
    while((temp->next!=NULL )&& (temp2<(pos-1))){
        temp=temp->next;
        temp2++;
    }
        newNode->next=temp->next;
       newNode->prev=temp;
       temp->next=newNode;
       if(temp->next != NULL)
       (temp->next)->prev=newNode;
       

   }return head;
}
Node * insertatFront(Node * head,int val){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        return head;}
        else{
            newNode->next=head;
            newNode->prev=NULL;
            head->prev=newNode;
            head=newNode;
        }
        return head;
}
Node* createNode(Node * head, int val){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        return head;
    }else{
        Node * temp =head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        newNode->next=NULL;
        newNode->prev=temp;
        temp->next=newNode;
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
   if(head != NULL)
      head->prev = NULL;
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
   while(current->next->next != NULL)
      current = current->next;
   free(current->next);
   current->next = NULL;
   return head;
}
Node* deleteAtPos(Node * head, int pos)
{
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
   if(pos <= 1)
      return deleteFront(head);
   Node * current = head;
   int currPos = 1;
   while(current != NULL && currPos < pos)
   {
      current = current->next;
      currPos++;
   }
   if(current == NULL)
   {
      printf("Invalid position\n");
      return head;
   }
   if(current->next != NULL)
      current->next->prev = current->prev;
   if(current->prev != NULL)
      current->prev->next = current->next;
   free(current);
   return head;
}
void display(Node *head){
    if(head==NULL){
        printf("List is emplty");
    }else{
        Node * temp=head;
        while(temp!=NULL){
            printf("%d \t ",temp->data);
            temp=temp->next;}
    }
}
void displayReverse( Node* head) {
     Node* ptr;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("\nNodes of the list in reverse order are :\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}


int main(){
    Node *head =(Node*)malloc(sizeof(Node));
    head=NULL;
    for(int i=50;i<56;i++){
        head=createNode(head,i);
    }   
    display(head);
    displayReverse(head);
    head=insertatFront(head,22);
    printf("\n");
    display(head);
    head=inserinBetween(head,69,4);
    printf("\n");
    display(head);
    return 0;
}