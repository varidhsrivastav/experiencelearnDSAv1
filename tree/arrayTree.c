#include<stdio.h>
#include<stdlib.h>
char tree[10];
int root(char key){
    if(tree[0]!='\0')
        return 0;
    else{
        tree[0]=key;
        return 1;
    } 
}

int setLeft(char key, int parent){
    if(tree[parent]=='\0')
        printf("\n Can't set child at  this node");
    else
    tree[(parent *2)+1] = key;
    return 1;
}

int setRight(char kay, int parent){
    if(tree[parent]=='\0')
    printf(" \n Right Child can not be set for the root Node ");
    else 
        tree[(parent*2) +2 ]=kay;
    return 0;
}
void printTree() {
    int i;
    for(i=0;i<10;i++){
        if (tree[i] != '\0')
            printf("%c ",tree[i]);
        else
            printf("-");
    }
}

int searchNumber(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("\n Number not found in the tree.");
        return 0;
    } else {
        if (tree[parent] == key) {
            printf("\n Number found at node %c", tree[parent]);
            if (tree[(parent * 2) + 1] != '\0')
                printf("\n Left Child: %c", tree[(parent * 2) + 1]);
            if (tree[(parent * 2) + 2] != '\0')
                printf("\n Right Child: %c", tree[(parent * 2) + 2]);
            return 1;
        } else {
            searchNumber(key, (parent * 2) + 1);
            searchNumber(key, (parent * 2) + 2);
        }
    }
}
int main() {
    root('A');
    setLeft('c',0);
    setRight('b', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);
    printTree();
    printf("\nSearching for a number:");
    searchNumber('c', 0);
    // searchNumber('G', 0); 
  return 0;
}



