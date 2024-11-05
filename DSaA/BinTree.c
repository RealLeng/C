#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BiTNode *BiTree;
struct BiTNode{
    int data;
    BiTree left,right;
};

int InitBiTree(BiTree *T)
{
    (*T)=NULL;
    return 0;
}
void CreateBiTree(BiTree *T)
{
    char s;
    s=getchar();
    if(s=='#') *T=NULL;
    else {
    *T=(BiTree)malloc(sizeof(BiTree));
    if(!T) {
        return;
        printf("Waring! Assignment worried");
    }
    (*T)->data=s;
    CreateBiTree(&(*T)->left);
    CreateBiTree(&(*T)->right);
    }
}

void preodertraversal(BiTree T)
{
    if(T)
    {
        printf("%c",T->data);
        preodertraversal(T->left);
        preodertraversal(T->right);
    }
    
}
void 

int main()
{
    BiTree T;
    InitBiTree(&T);
    CreateBiTree(&T);
    preodertraversal(T);
}