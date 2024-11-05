#include <stdio.h>

int main()
{
    int i,n,sum=0;
    printf("Input your number:");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
    	int temp=i*(i+1);
        sum+=temp;
    }
    printf("%d",sum);
}
