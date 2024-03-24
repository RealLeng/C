#include<stdio.h>
#include <stdlib.h>
#define Queuesize 5

typedef struct Queue
{
    int Data[Queuesize];
    int front;
    int rear;
}*LpQueue;

LpQueue CreatQueue(LpQueue s)
{
    s=(LpQueue)malloc(sizeof(struct Queue));
    s->front=0;
    s->rear=0;
    return s;
}

void EnLpQueue(LpQueue s,int e)
{
    if((s->rear+1)%Queuesize==s->front)
    return;
    s->Data[s->rear]=e;s->rear=((s->rear+1)%Queuesize);
    printf("r%d\n",s->rear);
    return;
}

void DeQueue(LpQueue s,int *e)
{
    if(s->front==s->rear)
    return;
    *e=s->Data[s->front];
    s->front=((s->front+1)%Queuesize);
    return;
}

void show(LpQueue s)
{
    int i=s->front;
    while((i)!=s->rear)
    {
        printf("%d",s->Data[i]);
        i=(i+1)%Queuesize;
    }
    printf("\n");
    return ;
}

int main()
{
    LpQueue s;
    int *e;
    s=CreatQueue(s);
    EnLpQueue(s,1);
    show(s);
    EnLpQueue(s,2);
    show(s);
    EnLpQueue(s,3);
    show(s);
    DeQueue(s,e);
    show(s);
    EnLpQueue(s,4);
    show(s);
    EnLpQueue(s,5);
    show(s);
    return 0;
}
