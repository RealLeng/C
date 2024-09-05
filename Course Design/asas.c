//Ð¡ÍõÍ¬Ñ§»¨ÁËÒ»ÏÂÎçÐ´µÄ»­Í¼Ð¡³ÌÐò
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int static o = 0, p = 0,med=0,fad=0;
int map[10][10]={{3},};
//µØÍ¼´óÐ¡µÄ»®¶¨
void drawmap()//»æÍ¼
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <10; j++)
		{
			switch (map[i][j])
			{
			case 0:printf("¡õ"); break;
			case 1:printf("¡ö"); break;
			case 3:printf("  "); break;
			default:break;
			}
		}printf("\n");
	}
}
void  move(int n,int m)//ÒÆ¶¯·½¸ñµÄº¯Êý
{
	if (o < 10 && p < 10)
	{
		map[o][p] = med;
		fad = map[o + n][p + m];
		map[o + n][p + m] = 3;
		med = fad;
		o = o + n;
		p = p + m;
	}
	else
	{
		printf("³¬³ö±ß½ç£¬ÖØÐÂÑ¡ÔñÒÆ¶¯Â·¾¶£º\n");//ÐÞ¸´¿ÉÄÜ´æÔÚµÄbug
	}
}
int main() 
{
	
	char c;
	
	for (;;)
	{
		system("cls");
		drawmap();
		c = _getch();
		switch (c)//¸Ä½øÁËÆä²Ù×÷·½Ê½Ê¹Æä²Ù×÷¸ü¼òµ¥Ò»µã
		{
		case 'a':move(0, -1); break;
		case 'w':move(-1, 0); break;
		case 's':move(1, 0); break;
		case 'd':move(0, 1); break;
		case 'c':map[o][p] = 1;med= map[o][p]; break;//±äÎª°×·½¸ñ
		case 'x':map[o][p] = 0;med = map[o][p]; break;//±äÎªºÚ·½¿ò
		default:exit(0);
		}
	}
}
