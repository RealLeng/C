#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int Data;
    struct StackNode *Next;
};
typedef struct StackNode *LinkStackPtr;

typedef struct Stack
{
    LinkStackPtr top;
    int count;
}Linkstack;

Linkstack *CreatStack(Linkstack *s)
{
    s->top=(LinkStackPtr)malloc(sizeof(struct StackNode));
    s->top=NULL;
    s->count=0;
    return s;
}

void Push(Linkstack *s,int e)
{
    LinkStackPtr c;
    c=(LinkStackPtr)malloc(sizeof(struct StackNode));
    c->Data=e;
    c->Next=s->top;
    s->top=c;
    s->count++;
}
void Pop(Linkstack *s,int *e)
{
    LinkStackPtr Fristcell;
    Fristcell=s->top;
    s->top=s->top->Next;
    *e=Fristcell->Data;
    free(Fristcell);
    s->count--;
    return;
}

void show(Linkstack *s)
{
    int i=1;
    LinkStackPtr c;
    c=s->top;
     while(i<=s->count)
    {
    	if(c)
    	{
        printf("%d",c->Data);c=c->Next;
        i++;
		}
		return;
    }
    printf("\n");
    return;
}

int main()
{
    Linkstack *s;
    int *c;
    s=CreatStack(s);
    Push(s,1);
    show(s);
    Push(s,2);
    show(s);
    Push(s,3);
    show(s);
    Pop(s,c);
    show(s);
    Push(s,3);
    show(s);
    Push(s,4);
    show(s);
    Push(s,5);
    show(s);
    return 0;
}


