#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int static o=0,p=0,med=0,fed=0;
int map[50][50]={3};
char get_c()
{
    char c;
    scanf("c",&c);
    return c;
}
void drawmap()
{
    int n,m;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            switch(map[i][j])
            {
                case 0:printf("*");break;
                case 1:printf("@");break;
                case 3:printf(" ");break;
            }
        }printf("\n");
    }
}
void move(int n,int m)
{
    if(o<50&&p<50)
    {
        map[o][p]=med;
        fed=map[o+n][p+m];
        map[o+n][p+m]=3;
        med=fed;
        o=o+n;
        p=p+m;
    }
    else
    {
        printf("Worry!");
    }
}
int main()
{
    char c;
    
    for(;;)
    {
        system("cls");
        drawmap();
        c=get_c();
        switch(c)
        {
            case'w':move(1,0);break;
            case'a':move(0,-1);break;
            case's':move(-1,0);break;
            case'd':move(0,1);break;
            case'z':map[o][p]=1;med=map[o][p];break;
            case'x':map[o][p]=0;med=map[o][p];break;
            default:break;
        }
        
    }
    return 0;
}