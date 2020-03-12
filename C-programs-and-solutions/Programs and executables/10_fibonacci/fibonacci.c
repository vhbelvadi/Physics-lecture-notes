#include<stdio.h>

int main() {
    
    int a=0, b=1, c, n, counter=0;
    
    printf("\nEnter a limit:\t");
    scanf("%d",&n);
    n-=2;
    printf("%d \t",a);
    
    do {
        printf("%d \t",b);
        c=a+b;
        a=b;
        b=c;
        counter++;
    } while ( counter <= n ) ;
    
    printf("\n");
    
    return 0;
}