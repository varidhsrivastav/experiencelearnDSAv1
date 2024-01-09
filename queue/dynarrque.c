#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size,f,r;
    int *arr;
};
int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val){
    if(isfull(q))
        printf("Queue is Full\n");
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q))
        printf("Queue is empty\n");
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int*)malloc(sizeof(int)*q.size);
    // enque few elements
    if(isempty(&q)){
        printf("queue is empty \n");
    }
    printf("adding the element in the queue");
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    printf("Dequeing element %d \n", dequeue(&q));
    printf("Dequeing element %d \n", dequeue(&q));
    if(isempty(&q)){
        printf("queue is empty \n");
    }
    if(isfull(&q)){
        printf("queue is full \n");
    }else{
        printf("baigan \n");
    }
    return 0;
}