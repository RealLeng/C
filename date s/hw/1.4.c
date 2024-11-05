#include <stdio.h>

int main(){
    double height,sum=0;
    printf("Input your number:");
    scanf("%lf",&height);
    while(height>=0.1){
        double temp=height+height/2;
        sum+=temp;
        height=height/2;
    }
    printf("%lf", sum);
    return  0;
}
