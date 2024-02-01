#include <stdio.h>
#include  <time.h>
#include <math.h>
clock_t start,stop;
double duration;
void f1(double a[],int n,double x)
{
    int i;
    double p=a[0];
    for(i=1;i<=n;i++)
    {
        p+=(a[i]*pow(x,i));
    }
}

void f2(double a[],int n,double x)
{
    int i;
    double p=a[n];
    for(i=n;i>0;i--)
    {
    	p=a[i-1]+x*p;
	}
}
int main()
{
    double a[10];
    int i;
    for(i=0;i<=9;i++)
    {
    	a[i]=i;
	}
    start=clock();
    for(i=1;i<100000;i++)
    {
    	f1(a,9,1.1);
	}
    f1(a,9,1.1);
    stop=clock();
    duration=((double)(stop-start)/CLK_TCK);
    printf("f1 duration=%f\n",duration);
    start=clock();
    for(i=1;i<100000;i++)
    {
    	f2(a,9,1.1);
	}
    stop=clock();
    duration=((double)(stop-start)/CLK_TCK);
    printf("f2 duration=%f\n",duration);
    return 0;
}