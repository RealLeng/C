#include <stdio.h>

int is_prime(int i)
{
    int j;
    for(j=2;j<i;j++){
        if(i % j == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(){
    int n,i,sum=0;
    printf("Input your number:");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if (is_prime(i))
        {
            sum++;
            printf("%d ", i);
            if(sum % 5 == 0)
            { 
                printf("\n");
            }
        }
    }
    printf("\n the prime number is %d\n", sum);
}
