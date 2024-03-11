#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define ERROR 0
#define OK 1;
typedef int elemtype;
typedef struct
{
    int Data;
    int cur;
} Component,StaticLinkList[MAXSIZE];

void InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
    return 0;
}

void ListInsert(StaticLinkList space,int i,elemtype e)
{
    int j,k,l;
    k=MAXSIZE-1;
    if(i<1||i>Listlength(space)+1)
       return ERROR;
    j=malloc_SLL(space);
    if(j)
    {
        space[j].Data=e;
        for(l=1;l<=i-1;l++)
          k=space[k].cur;
        space[j].cur=space[k].cur;
        space[k].cur=j;
        return OK;
    }
    return ERROR;
}
void Listdelete(StaticLinkList space,int i)
{
    int j,k,l;
    k=MAXSIZE-1;
    for(l=1;l<=i-1;l++)
      k=space[k].cur;
    j=space[k].cur;
    space[k].cur=space[j].cur;
    free_SLL(space,j);
    return OK;
}
void Showlist(StaticLinkList space)
{   int k;
    k=MAXSIZE-1;
    while(space[k].cur)
    {
        k=space[k].cur;
        printf(" %d ",space[k].Data);
        
    }
    printf("\n");
    return OK;
}
int malloc_SLL(StaticLinkList space)
{
    int i=space[0].cur;
    if(i)
        space[0].cur=space[i].cur;
    return i;
}
void free_SLL(StaticLinkList space,int i)
{
    space[i].cur=space[0].cur;
    space[0].cur=i;
}
int Listlength(StaticLinkList space)
{
    int j=0,k;
    k=MAXSIZE-1;
    while(space[k].cur)
    {
        k=space[k].cur;
        j++;
    }
    return j;
}
int main()
{
    StaticLinkList space;
    InitList(space);
    ListInsert(space,1,1);
    Showlist(space);
    ListInsert(space,2,2);
    Showlist(space);
    ListInsert(space,3,3);
    Showlist(space);
    ListInsert(space,4,4);
    Showlist(space);
    Listdelete(space,2);
    Showlist(space);
    return 0;
}
