#include <stdio.h>
#include <math.h>

int main()
{
    double n,i;
    double sum;
    printf("Input your number:");
    scanf("%lf",&n);
    for(i=0;i<=n-1;i++)
    {
        sum+=pow(2,i);
    }
    printf("The number is %lf",sum);
}
