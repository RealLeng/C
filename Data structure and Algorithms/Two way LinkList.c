#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct DulNode
{
    int Data;
    struct Node *prior;
    struct Node *next;
} DulNode, *DuLinkList;

void MakeList(int length,DuLinkList p)
{
    srand(time(0));
    DuLinkList Ptrl,r;
    int i;
    p->next=p;
    p->prior=p;
    r=p;
    for(i=1;i<=length;i++)
    {
        Ptrl=(DuLinkList)malloc(sizeof(struct DulNode));
        Ptrl->Data=rand();
        r->next=Ptrl;
        Ptrl->prior=r;
        r=Ptrl;
    }
    Ptrl->next=p;
    p->prior=Ptrl;
    return 0;
}

void ShowList1(DuLinkList p)
{
    DuLinkList r;
    int i;

}