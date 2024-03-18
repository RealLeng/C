#include <stdio.h>
#include <stdlib.h>
#define Maxsize 12
struct Stack
{
    int Date[Maxsize];
    int top;
};
typedef struct Stack *S;

S InitStack(S e)
{
    S s;
    s=(S)malloc(sizeof(struct Stack));
    s->top=-1;
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
void Push(S s,int e)
{
        if(s->top==11)
    {
        printf("Stack is full");
        return;
    }
    s->top++;
    s->Date[s->top]=e;
}
void Pop(S s)
{
    if(s->top==-1)
    {
        return;
    }
    s->top--;
}
int StackLength(S s)
{
    int e=s->top+1;
    return e;
}
void show(S s)
{
    int i;
    for(i=0;i<=s->top;i++)
    {
        printf("%d ",s->Date[i]);
    }
    printf("\n");
}
int main()
{
    S s;
    s=InitStack(s);
    Push(s,12);
    show(s);
    Push(s,12);
    show(s);
    Push(s,12);
    show(s);
    Pop(s);
    show(s);
    Push(s,12);
    show(s);
    Push(s,12);
    show(s);
    return 0;
}