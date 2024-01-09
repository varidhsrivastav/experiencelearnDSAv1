#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
     struct Node * next;
}Node;

 Node * create(int numnode){
    Node * head = NULL;
    Node * temp = NULL;
    Node * p = NULL;
    for(int i =0; i<numnode; i++){
        temp= (Node *)malloc(sizeof(Node));
        printf("Enter the data for the %d node", i+1);
        scanf("%d", &(temp->data));
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }else{
            p=head;
            while(p->next!=NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
 }
 void display(Node * head){
    Node * p = head;
    if(p->next==NULL){
        printf("out of memeory");
    }

        while(p != NULL){
            printf("Node data - %d ->", p->data);
            p=p->next;
        }
    
 }
int main(){
    int numnode=0;
    Node * head =NULL;
    printf("Enter the number of the node ");
    scanf("%d", &numnode);
    head=create(numnode);
    display(head);
    return 0;
}