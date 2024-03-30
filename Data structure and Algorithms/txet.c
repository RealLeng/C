#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ´æ´¢¿Õ¼ä³õÊ¼·ÖÅäÁ¿ */

typedef int Status;		/* StatusÊÇº¯ÊýµÄÀàÐÍ,ÆäÖµÊÇº¯Êý½á¹û×´Ì¬´úÂë£¬ÈçOKµÈ */

/* ÓÃÓÚ¹¹Ôì¶þ²æÊ÷********************************** */
int treeIndex=1;
typedef char String[24]; /*  0ºÅµ¥Ôª´æ·Å´®µÄ³¤¶È */
String str;

Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
/* ************************************************ */

typedef char TElemType;
TElemType Nil=' '; /* ×Ö·ûÐÍÒÔ¿Õ¸ñ·ûÎª¿Õ */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* ½áµã½á¹¹ */
{
   TElemType data;		/* ½áµãÊý¾Ý */
   struct BiTNode *lchild,*rchild; /* ×óÓÒº¢×ÓÖ¸Õë */
}BiTNode,*BiTree;


/* ¹¹Ôì¿Õ¶þ²æÊ÷T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ¡£²Ù×÷½á¹û: Ïú»Ù¶þ²æÊ÷T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ÓÐ×óº¢×Ó */
			DestroyBiTree(&(*T)->lchild); /* Ïú»Ù×óº¢×Ó×ÓÊ÷ */
		if((*T)->rchild) /* ÓÐÓÒº¢×Ó */
			DestroyBiTree(&(*T)->rchild); /* Ïú»ÙÓÒº¢×Ó×ÓÊ÷ */
		free(*T); /* ÊÍ·Å¸ù½áµã */
		*T=NULL; /* ¿ÕÖ¸Õë¸³0 */
	}
}

/* °´Ç°ÐòÊäÈë¶þ²æÊ÷ÖÐ½áµãµÄÖµ£¨Ò»¸ö×Ö·û£© */
/* #±íÊ¾¿ÕÊ÷£¬¹¹Ôì¶þ²æÁ´±í±íÊ¾¶þ²æÊ÷T¡£ */
void CreateBiTree(BiTree *T)
{ 
	char ch;
	
	 /*scanf("%c",&ch);*/ 
	ch=str[treeIndex++];

	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* Éú³É¸ù½áµã */
		CreateBiTree(&(*T)->lchild); /* ¹¹Ôì×ó×ÓÊ÷ */
		CreateBiTree(&(*T)->rchild); /* ¹¹ÔìÓÒ×ÓÊ÷ */
	}
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ */
/* ²Ù×÷½á¹û: ÈôTÎª¿Õ¶þ²æÊ÷,Ôò·µ»ØTRUE,·ñÔòFALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ¡£²Ù×÷½á¹û: ·µ»ØTµÄÉî¶È */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ¡£²Ù×÷½á¹û: ·µ»ØTµÄ¸ù */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ£¬pÖ¸ÏòTÖÐÄ³¸ö½áµã */
/* ²Ù×÷½á¹û: ·µ»ØpËùÖ¸½áµãµÄÖµ */
TElemType Value(BiTree p)
{
	return p->data;
}

/* ¸øpËùÖ¸½áµã¸³ÖµÎªvalue */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ */
/* ²Ù×÷½á¹û: Ç°ÐòµÝ¹é±éÀúT */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%d\n",T);
	printf("%c",T->data);/* ÏÔÊ¾½áµãÊý¾Ý£¬¿ÉÒÔ¸ü¸ÄÎªÆäËü¶Ô½áµã²Ù×÷ */
	PreOrderTraverse(T->lchild); /* ÔÙÏÈÐò±éÀú×ó×ÓÊ÷ */
	PreOrderTraverse(T->rchild); /* ×îºóÏÈÐò±éÀúÓÒ×ÓÊ÷ */
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ */
/* ²Ù×÷½á¹û: ÖÐÐòµÝ¹é±éÀúT */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ÖÐÐò±éÀú×ó×ÓÊ÷ */
	printf("%c",T->data);/* ÏÔÊ¾½áµãÊý¾Ý£¬¿ÉÒÔ¸ü¸ÄÎªÆäËü¶Ô½áµã²Ù×÷ */
	InOrderTraverse(T->rchild); /* ×îºóÖÐÐò±éÀúÓÒ×ÓÊ÷ */
}

/* ³õÊ¼Ìõ¼þ: ¶þ²æÊ÷T´æÔÚ */
/* ²Ù×÷½á¹û: ºóÐòµÝ¹é±éÀúT */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* ÏÈºóÐò±éÀú×ó×ÓÊ÷  */
	PostOrderTraverse(T->rchild); /* ÔÙºóÐò±éÀúÓÒ×ÓÊ÷  */
	printf("%c",T->data);/* ÏÔÊ¾½áµãÊý¾Ý£¬¿ÉÒÔ¸ü¸ÄÎªÆäËü¶Ô½áµã²Ù×÷ */
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("¹¹Ôì¿Õ¶þ²æÊ÷ºó,Ê÷¿Õ·ñ£¿%d(1:ÊÇ 0:·ñ) Ê÷µÄÉî¶È=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("¶þ²æÊ÷µÄ¸ùÎª: %c\n",e1);

	printf("\nÇ°Ðò±éÀú¶þ²æÊ÷:");
	PreOrderTraverse(T);
	printf("\nÖÐÐò±éÀú¶þ²æÊ÷:");
	InOrderTraverse(T);
	printf("\nºóÐò±éÀú¶þ²æÊ÷:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\nÇå³ý¶þ²æÊ÷ºó,Ê÷¿Õ·ñ£¿%d(1:ÊÇ 0:·ñ) Ê÷µÄÉî¶È=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("Ê÷¿Õ£¬ÎÞ¸ù\n");
	
	return 0;
}