#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* ´æ´¢¿Õ¼ä³õÊ¼·ÖÅäÁ¿ */

typedef int Status; 
typedef int QElemType; /* QElemTypeÀàÐÍ¸ù¾ÝÊµ¼ÊÇé¿ö¶ø¶¨£¬ÕâÀï¼ÙÉèÎªint */

/* Ñ­»·¶ÓÁÐµÄË³Ðò´æ´¢½á¹¹ */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* Í·Ö¸Õë */
	int rear;		/* Î²Ö¸Õë£¬Èô¶ÓÁÐ²»¿Õ£¬Ö¸Ïò¶ÓÁÐÎ²ÔªËØµÄÏÂÒ»¸öÎ»ÖÃasdasdasdasdasd */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}

/* ³õÊ¼»¯Ò»¸ö¿Õ¶ÓÁÐQ */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ½«QÇåÎª¿Õ¶ÓÁÐ */
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

/* Èô¶ÓÁÐQÎª¿Õ¶ÓÁÐ,Ôò·µ»ØTRUE,·ñÔò·µ»ØFALSE */
Status QueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* ¶ÓÁÐ¿ÕµÄ±êÖ¾ */
		return TRUE;
	else
		return FALSE;
}

/* ·µ»ØQµÄÔªËØ¸öÊý£¬Ò²¾ÍÊÇ¶ÓÁÐµÄµ±Ç°³¤¶È */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* Èô¶ÓÁÐ²»¿Õ,ÔòÓÃe·µ»ØQµÄ¶ÓÍ·ÔªËØ,²¢·µ»ØOK,·ñÔò·µ»ØERROR */
Status GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear) /* ¶ÓÁÐ¿Õ */
		return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

/* Èô¶ÓÁÐÎ´Âú£¬Ôò²åÈëÔªËØeÎªQÐÂµÄ¶ÓÎ²ÔªËØ */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ¶ÓÁÐÂúµÄÅÐ¶Ï */
		return ERROR;
	Q->data[Q->rear]=e;			/* ½«ÔªËØe¸³Öµ¸ø¶ÓÎ² */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rearÖ¸ÕëÏòºóÒÆÒ»Î»ÖÃ£¬ */
			printf("r%d\n",Q->rear);					/* Èôµ½×îºóÔò×ªµ½Êý×éÍ·²¿ */
	return  OK;
}

/* Èô¶ÓÁÐ²»¿Õ£¬ÔòÉ¾³ýQÖÐ¶ÓÍ·ÔªËØ£¬ÓÃe·µ»ØÆäÖµ */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ¶ÓÁÐ¿ÕµÄÅÐ¶Ï */
		return ERROR;
	*e=Q->data[Q->front];				/* ½«¶ÓÍ·ÔªËØ¸³Öµ¸øe */
	Q->front=(Q->front+1)%MAXSIZE;	/* frontÖ¸ÕëÏòºóÒÆÒ»Î»ÖÃ£¬ */
	printf("f%d\n",Q->front);								/* Èôµ½×îºóÔò×ªµ½Êý×éÍ·²¿ */
	return  OK;
}

/* ´Ó¶ÓÍ·µ½¶ÓÎ²ÒÀ´Î¶Ô¶ÓÁÐQÖÐÃ¿¸öÔªËØÊä³ö */
Status QueueTraverse(SqQueue Q)
{ 
	int i;
	i=Q.front;
	while((i+Q.front)!=Q.rear)
	{
		visit(Q.data[i]);
		i=(i+1)%MAXSIZE;	printf("%d ",i);
	printf("%d",Q.rear);
	printf("\n");	}
	printf("\n");

	return OK;
}
int main()
{
	Status j;
	int i=0,l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);
    printf("³õÊ¼»¯¶ÓÁÐºó£¬¶ÓÁÐ¿Õ·ñ£¿%u(1:¿Õ 0:·ñ)\n",QueueEmpty(Q));

	printf("ÇëÊäÈëÕûÐÍ¶ÓÁÐÔªËØ(²»³¬¹ý%d¸ö),-1ÎªÌáÇ°½áÊø·û: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE-1);
    for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("É¾³ýµÄÔªËØÊÇ%d,²åÈëµÄÔªËØ:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	QueueTraverse(Q);
}