#include <stdio.h>
#define Max 100
typedef struct sqlist
{
    int elem[Max];
    int length;
}sqlist;
typedef struct sqlist *s;

int initsqlist()
{
    s L;
    L=(s)malloc(sizeof(sqlist));
    L->length=0;
    return L;
}
int find(sqlist* L)
{
    
}
int main(){
    
}