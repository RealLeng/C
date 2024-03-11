#include <stdio.h>
#include <stdlib.h>
const int N=20;
typedef struct LNode *List;
struct LNode 
{
    int a[20];
    int last;
};

List Makempty()
{
    List Ptrl;
    Ptrl=(List)malloc(sizeof(struct LNode));
    Ptrl->last=-1;
    printf("The list has been Made!\n");
    return Ptrl;
}

int find(int x,List Ptrl)
{
    int i=0;
    while(i<=Ptrl->last&&Ptrl->a[i]!=x)
    {
        i++;
    }
    if(i>Ptrl->last)
    {
        printf("No this number\n");
        return -1;
    }
    else return i;
} 
void insert(int x,int i,List Ptrl)
{
    int j;
    if(Ptrl->last==N-1)
    {
        printf("表满\n");
        return 0;
    }
    if(i<1||i>Ptrl->last+2)
    {
        printf("位置不合法\n");
        return 0;
    }
    for(j=Ptrl->last;j>=i-1;j--)
    {
        Ptrl->a[j+1]=Ptrl->a[j];
    }
    Ptrl->a[i-1]=x;
    Ptrl->last++;
    printf("Last is %d\n",Ptrl->last+1);
    return 0;
}
void delete(int i,List Ptrl)
{
    int j;
    if(i<1||i>Ptrl->last+1)
    {
        printf("无此元素\n");
        return 0;
    }
    for(j=i;j<=Ptrl->last;j++)
    {
        Ptrl->a[j-1]=Ptrl->a[j];
    }
    Ptrl->last--;
    printf("Last is %d\n",Ptrl->last+1);
    return 0;
}
void Showlist(List Ptrl)
{
    int j;
    for(j=0;j<=Ptrl->last;j++)
    {
        printf("第%d位是%d ",j+1,Ptrl->a[j]);
    }
    printf("\n");
    return 0;
}
int main()
{
    struct LNode L;
    List Ptrl;
    Ptrl=&L;
    Ptrl=Makempty();
    insert(1,1,Ptrl);
    Showlist(Ptrl);
    insert(2,2,Ptrl);
    Showlist(Ptrl);
    insert(3,3,Ptrl);
    Showlist(Ptrl);
    insert(4,4,Ptrl);
    Showlist(Ptrl);
    delete(2,Ptrl);
    Showlist(Ptrl);
    printf("1是第%d位\n",find(1,Ptrl)+1);
    return 0;
}