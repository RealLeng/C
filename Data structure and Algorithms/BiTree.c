#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchird,*rchild;
}BiTNode,*BiTree;

char Get_c()
{
    char a;
    scanf("%c",&a);
    return a;
}

void CreatTree(BiTree *s)
{
    char ch;
    ch=getchar();
    if(ch=='#')
      *s=NULL;
    else
    {
        *s=(BiTree)malloc(sizeof(BiTNode));
        if(!*s)
        exit(0);
        (*s)->data=ch;
        CreatTree(&(*s)->lchird);
        CreatTree(&(*s)->rchild);
    }
}
void Assign()
{}
void InsertChird()
{}
void DeleteChird()
{}
void PreorderTraverse(BiTree s)
{
    if(s==NULL)
       return;
    printf("%c\n",s->data);
    PreorderTraverse(s->lchird);
    PreorderTraverse(s->rchild);
}
void InorderTraverse(BiTree s)
{
    if(!s)
    return;
    
    PreorderTraverse(s->lchird);printf("%c\n",s->data);
    PreorderTraverse(s->rchild);
}
void PostoderTraverse(BiTree s)
{
    if(!s)
    return;
    
    PreorderTraverse(s->lchird);
    PreorderTraverse(s->rchild);printf("%c\n",s->data);
}
void OrderTraverse()
{}

int main()
{
    BiTree s;
    CreatTree(&s);
    PreorderTraverse(s);
    InorderTraverse(s);
    PostoderTraverse(s);
}