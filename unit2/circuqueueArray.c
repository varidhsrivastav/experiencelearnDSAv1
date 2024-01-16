#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct {
    int items[MAXSIZE];
    int front, rear;
}CircularQueue;
void InitializeQueue(CircularQueue * q){
    q->front = q->rear = -1;
}

int isEmpty(CircularQueue *q){
    return (q->front == -1);
}
int isFull(CircularQueue *q){
    return ((q-> rear+1)% MAXSIZE==q->front);
}
void Enqueue(CircularQueue* q, int element){
    if(isFull(q))
    printf("Error: Queue is Full\n");
    else{
        if((q->front)=-1){q->front=0;}
        q->rear=(q->rear+1)%MAXSIZE;
        q->items[q->rear] = element;
        printf("\n  Enqueued %d \n",element);
        }
        }
int Dequeue(CircularQueue *q){
    int element;
    if(isEmpty(q)){
        printf("Error: Queue is Empty\n");
        return -1;
        }else{
            element = q->items[q->front];
            if(q->front==q->rear)//Only one item present
            q->front = q->rear = -1; //To set both front and rear
            else
            q->front = (q->front+1)%MAXSIZE;
            printf("\n Dequeued %d\n",element);
            return element;
            }
}
void DisplayQueue(CircularQueue *q){
    int i;
    if(isEmpty(q))
    {
        printf("\n Error : Queue is empty");
        return ;
        }
        printf("\n Items in the queue are:\n");
        for(i=q->front; i!=q->rear; i=(i+1)%MAXSIZE)
        {
            printf("%d ",q->items[i]);
            }
            printf("%d",q->items[i]);
            printf("\n");
        
}

int main(){
    CircularQueue q;
    // InitializeQueue(&q);
    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    DisplayQueue(&q);
    Dequeue(&q);
    DisplayQueue(&q);
    return 0;
}