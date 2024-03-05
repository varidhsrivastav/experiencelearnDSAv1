#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right; 
};
struct Node * createNode (int x) {
    struct Node *p;
    p= (struct Node *)malloc(sizeof(struct Node)); 
    p->data = x; 
    p->left=NULL;
    p->right=NULL;
    return p;
}
void  perorder(struct  Node* root){
    if(root!=NULL){
        printf("%d",root->data);
        perorder(root->left);
        perorder(root->right);
    }
}
void postOrder(struct Node *root){
     if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}
void InOrder(struct Node *root){
     if(root!=NULL){
        InOrder(root->left);
        printf("%d",root->data);
        InOrder(root->right);
    }
}
    int main(){
    struct Node *p=createNode(4);
    struct Node *p1=createNode(1);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(5);
    struct Node *p4=createNode(2);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    perorder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    InOrder(p);
    return 0;
}
