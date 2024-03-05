#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * insertatFront(struct Node * head,int data){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }else{
        struct Node * ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        newNode->next=head;
        ptr->next=newNode;
        head=newNode;
    }return head;
    
}
struct Node * insertafterlast(struct Node * head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
        return head;
    }
    struct Node* p = head;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}


void traverse(struct Node * head){
    struct Node *ptr=head;
     do{
        printf("%d\n", ptr->data);
        ptr = ptr->next;
        }while (ptr!=head);
}


int main(){
    struct Node * head=(struct Node*)malloc(sizeof(struct Node));
    head=NULL;
    for(int i=50; i<=55;i++){
        head=insertafterlast(head, i);
    }
    traverse(head);
    head=insertatFront(head,23);
    printf("Inserting at front \n");
    traverse(head);
    return 0;
}