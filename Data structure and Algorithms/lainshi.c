#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
typedef struct Node *List;
struct Node
{
    int x;
    char a[N];
    List Next;
};


List Makelists(int length,List p)
{
    List Ptrl;
    int i;
    srand(time(0));
    p=(List)malloc(sizeof(struct Node));
    p->Next=NULL;
    for(i=1;i<=length;i++)
    {
        Ptrl=(List)malloc(sizeof(struct Node));
        Ptrl->x=rand()%100+1;
        Ptrl->Next=p->Next;
        p->Next=Ptrl;
    }
    printf("The List has been made,and the frist node is %d,the length is %d",*p,length);
    return p;
}
void Makelistw(int length,List p)
{
    List Ptrl,r;
    int i;
    srand(time(0));
    p=(List)malloc(sizeof(struct Node));
    p->Next=NULL;
    r=p;
    for(i=1;i<=length;i++)
    {
        Ptrl=(List)malloc(sizeof(struct Node));
        Ptrl->x=rand()%100+1;
        r->Next=Ptrl;
        r=Ptrl;
    }
    r->Next=NULL;
    printf("The List has been made,and the frist node is %d,the length is %d",*p,length);
}
void Listinsert(int n,int a,List p)
{
    List Ptrl,r;
    int i;;
    Ptrl=(List)malloc(sizeof(List));
    Ptrl->x=a;
    r=p;
    for(i=1;i<=n;i++)
    {
        if(!r||i>n)
        exit;
        r=r->Next;
    }
    Ptrl->Next=r->Next;
    r->Next=Ptrl;
}
void Listdelete(int n,List p)
{
    List r,q;
    int i;
    r=p;
    while(r->Next&&i<n)
    {
        r=r->Next;
        i++;
    }
    if(!(r->Next)||i>n)
     exit;
    q=r->Next;
    r->Next=q->Next;
    free(q);
}
List ListClear()
{}
int Getlength()
{}
int Find()
{}
void Show(List p,int n)
{
    int i;
    List r;
    r=p;
    for(i=1;i<=n;i++)
    {
        r=r->Next;
        printf("x=%d ",r->x);
    }
    return 0;
}

int main()
{
    List p;
    p=Makelists(5,p);
    Show(p,2);
    Show(p,5);
}