#include <stdio.h>
#include <stdlib.h>
#define Maxsize 12
struct Stack
{
    int Date[Maxsize];
    int top1;
    int top2;
};
typedef struct Stack *S;

S InitStack(S e)
{
    S s;
    s=(S)malloc(sizeof(struct Stack));
    s->top1=-1;
    s->top2=Maxsize;
    return s;
}

S DestroyStack(S s)
{
    free(s);
    return NULL;
}
void ClearStack()
{}
void StackEmpty()
{}
void GetTop()
{}
void Push(S s,int e,int stacknumber)
{
    if(stacknumber==1)
    {
        if(s->top2-s->top1==1)
        {
            printf("FULL");
            return;
        }
        s->top1++;
        s->Date[s->top1]=e;
        return;
    }
    if(stacknumber==2)
    {
        if(s->top2-s->top1==1)
        {
            printf("FULL");
            return;
        }
        s->top2--;
        s->Date[s->top2]=e;
        return;
    }
    
}
void Pop(S s,int stacknumber)
{
    if(stacknumber==1)
    {
        if(s->top1==-1)
    {
        return;
    }
    s->top1--;
    }
    if(stacknumber==2)
    {
        if(s->top2==-1)
    {
        return;
    }
    s->top2++;
    }
}
int StackLength(S s)
{
    int e=s->top1+1;
    return e;
}
void show(S s,int stacknumber)
{
    int i;
    if(stacknumber==1)
    {
        for(i=0;i<=s->top1;i++)
    {
        printf("%d ",s->Date[i]);
    }
    printf("\n");
    }
    if(stacknumber==2)
    {
        for(i=Maxsize-1;i>=s->top2;i--)
    {
        printf("%d ",s->Date[i]);
    }
    printf("\n");
    }

    
}
int main()
{
    S s;
    s=InitStack(s);
    Push(s,1,1);
    show(s,1);
    Push(s,2,1);
    show(s,1);
    Push(s,3,2);
    show(s,2);
    Pop(s,1);
    show(s,1);
    Push(s,4,2);
    show(s,2);
    Push(s,5,2);
    show(s,2);
    return 0;
}