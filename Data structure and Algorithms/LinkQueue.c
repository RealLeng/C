#include<stdio.h>
#include<stdlib.h>
typedef struct QueueNode
{
    int Data;
    struct QueueNode *Next;
}QueueNode,*Queueqtr;

struct LQueue
{
    Queueqtr front,rear;
};
typedef struct LQueue LinkQueue;

LinkQueue *InitQueue(LinkQueue *s)
{
    s->front=s->rear=(Queueqtr)malloc(sizeof(QueueNode));
    s->front=s->rear;
    s->front->Next=NULL;
    return s;
}

void EnQueue(LinkQueue *s,int e)
{
    Queueqtr p;
    p=(Queueqtr)malloc(sizeof(struct QueueNode));
    p->Data=e;
    p->Next=NULL;
    s->rear->Next=p;
    s->rear=p;
    return;
}
void DeQueue(LinkQueue *s)
{
    if(s->front=s->rear){
        printf("EMPTY");
        return;
    }
    Queueqtr p;
    p=(Queueqtr)malloc(sizeof(struct QueueNode));
    p=s->front->Next;
    s->front=p->Next;
    free(p);
    return;
}
void ClearQueue(LinkQueue *s)
{
    Queueqtr p,q;
    s->rear=s->front;
    p=s->front->Next;
    s->front=NULL;
    while(p)
    {
        q=p;
        p=p->Next;
        free(q);
    }
    return;
}
void DeleteQueue(LinkQueue *s)
{
    if(s->front=s->rear){
        printf("EMPTY");
        return;
    }
    while(s->front)
    {
        s->rear=s->front->Next;
        free(s->front);
        s->front=s->rear;
    }

}
int QueueLength(LinkQueue *s)
{
    Queueqtr p;
    p=s->front->Next;
    int i=1;
    while(p!=NULL)
    {
        p=p->Next;
        i++;
    }
    return i;
}
int QueueShow(LinkQueue *s)
{
    Queueqtr p;
    p=s->front->Next;
    while(p!=NULL)
    {
        printf("%d",p->Data);
        p=p->Next;
    }
    printf("\n");
}


int main()
{
    LinkQueue *s;
    s=InitQueue(s);
    QueueShow(s);
    EnQueue(s,1);
    QueueShow(s);
    EnQueue(s,2);
    QueueShow(s);
    QueueShow(s);
    EnQueue(s,3);
    QueueShow(s);
    DeQueue(s);
    QueueShow(s);
    EnQueue(s,4);
    QueueShow(s);
    EnQueue(s,5);
    QueueShow(s);
    EnQueue(s,6);
    QueueShow(s);
    EnQueue(s,7);
    QueueShow(s);
    ClearQueue(s);
    EnQueue(s,1);
    QueueShow(s);
    EnQueue(s,2);
    QueueShow(s);
    return 0;
}