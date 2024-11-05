#include <stdio.h>

void f(int *a){
    *a=100;
}

int main()
{
int a;
a=2;
int *q=&a;
f(q);
printf("%d",a);
}

