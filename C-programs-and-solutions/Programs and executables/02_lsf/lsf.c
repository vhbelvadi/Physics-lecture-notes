//
//  lsf.c
//
//  Created by V.H. Belvadi on 02/03/17.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    FILE *input;
    int n,i,x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;
    float m,c;
    char name[20];
    
    system("clear");
    
    printf("\n\nEnter the name of the input file: \t");
    scanf("%s", name);
    
    printf("\n\nEnter the number of rows of data:\t");
    scanf("%d",&n);
    
    input = fopen(name,"r");
    
    for(i=0; i<n; i++)
        fscanf(input,"%d\t%d\n",&x[i],&y[i]);
    
    fclose(input);
    
    for(i=0;i<n;i++)
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +y[i];
        sumxy=sumxy +x[i]*y[i];
        
    }
    
    c=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    m=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    printf("\n\nThe line of best fit is y=%3.3fx +%3.3f \n\n",m,c);
    
    return 0;
}
