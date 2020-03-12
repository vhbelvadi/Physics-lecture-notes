//
//  trapezoidalrule.c
//
//  Created by V.H. Belvadi on 02/03/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float functionOf(float x){
    // Code in the required function below
    // For now we have y = x^4
    return(pow(x,4));
}

int main()
{
    int i,n;
    float x0,xn,h,t,y[20],so,se,ans,x[20];
    
    system("clear");
    
    printf("\n\nEnter the two limits:\t");
    scanf("%f%f",&x0,&xn);
    printf("\n\nEnter the width of an interval:\t");
    scanf("%f",&h);
    
    if(xn<x0){
        t=xn;
        xn=x0;
        x0=t;
    }
    
    n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
    
    system("clear");
        
    printf("\n\n\nSummary:\nUpper limit = %f\nLower limit = %f\nNumber of intervals = %d\nWidth of an interval ~ %f",xn,x0,n,h);
    printf("\n\nThe values of y are\n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=functionOf(x[i]);
        printf("\t\t\ty%d = %f\n",i,y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    printf("\nThe integration yields %f\n\n",ans);
    
    return 0;
}