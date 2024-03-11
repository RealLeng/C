#include <stdio.h>
void printfN(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d",i);
    }
}
int main ()
{
    int n;
    scanf("%d",&n);
    printfN(n);
    return 0;
}