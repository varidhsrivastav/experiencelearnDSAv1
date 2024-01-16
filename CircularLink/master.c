#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} *NODE;

NODE create(int n);
NODE insert_f(int n,NODE tail);
NODE insert_r(int n,NODE tail);
NODE insert_p(int p,int n,NODE tail);
NODE delete_f(NODE tail);
NODE delete_r(NODE tail);
NODE delete_p(int p,NODE tail);
NODE display(NODE tail);

int main()
{
    NODE tail = NULL;
    printf("Creating a node\n");
    tail = create(1);
    display(tail);

    printf("\nInserting a node at front\n");
    tail = insert_f(0,tail);
    display(tail);

    printf("\nInserting nodes at rear\n");
    tail = insert_r(2,tail);
    tail = insert_r(3,tail);
    tail = insert_r(5,tail);
    tail = insert_r(6,tail);
    display(tail);

    printf("\nInserting a node at position 5\n");
    tail = insert_p(5,4,tail);
    display(tail);

    printf("\nDeleting the first node\n");
    tail = delete_f(tail);
    display(tail);

    printf("\nDeleting the last node\n");
    tail = delete_r(tail);
    display(tail);

    printf("\nDeleting a node at position 4\n");
    tail = delete_p(4,tail);
    display(tail);

    return 0;
}

NODE create(int n)
{
    NODE new = (NODE)malloc(sizeof(struct Node));

    if(new==NULL)
    {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    new->data = n;
    new->next = new;
    return new;
}

NODE insert_f(int n,NODE tail)
{
    NODE new = create(n);
    NODE temp = tail;

    if(tail == NULL)
    {
        tail = new;
    }
    else
    {
        new->next = temp->next;
        temp->next = new;
    }
    return tail;
}

NODE insert_r(int n,NODE tail)
{
    NODE new = create(n);
    NODE temp = tail;

    if(tail == NULL)
    {
        tail = new;
    }
    else
    {
        new->next = temp->next;
        temp->next = new;
        tail = new;
    }
    return tail;
}

NODE insert_p(int p,int n,NODE tail)
{
    if(p == 1)
    {
        tail = insert_f(n,tail);
        return tail;
    }

    NODE new = create(n);
    NODE temp = tail->next;

    for(int i = 1 ; i<p-1 ; i++)
    {
        temp = temp->next;
    }

    if(temp == tail->next)
    {
        printf("Inavlid position");
        return tail;
    }
    else if(temp->next == tail->next)
    {
        tail = insert_r(n,tail);
        return tail;
    }

    new->next = temp->next;
    temp->next = new;
    return tail;
}

NODE delete_f(NODE tail)
{
    NODE temp;
    if(tail->next == tail)
    {
        temp = tail;
        free(temp);
        return NULL;
    }
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
    return tail;
}

NODE delete_r(NODE tail)
{
    NODE temp,curr;
    curr = tail;
    temp = tail->next;
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail = temp;
    free(curr);
    return tail;
}

NODE delete_p(int p,NODE tail)
{
    if(p == 1)
    {
        tail = delete_f(tail);
        return tail;
    }

    NODE prev = NULL;
    NODE temp = tail->next;

    for(int i = 0 ; i<p-1 ; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == tail->next)
    {
        printf("Invalid position\n");
        return tail;
    }
    else if(temp->next == tail->next)
    {
        tail = delete_r(tail);
        return tail;
    }

    prev->next = temp->next;
    free(temp);
    return tail;
}

NODE display(NODE tail)
{
    NODE temp = tail->next;

    if(tail == NULL)
    {
        printf("List is empty!");
        exit(EXIT_FAILURE);
    }

    printf("\nHEADER ->");
    do
    {
        printf(" %d ->",temp->data);
        temp = temp->next;
    } while(temp != tail->next);
    printf(" TAIL\n");
}