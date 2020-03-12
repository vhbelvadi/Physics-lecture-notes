#include<stdio.h>

int main()
{
    FILE *input;
    int n,i;
    float x[20],sum=0,avg;;
    char name[20];
    
    printf("\n\nEnter the name of the input file: \t");
    scanf("%s", name);
    
    printf("\n\nEnter the number of rows of data:\t");
    scanf("%d",&n);
    
    input = fopen(name,"r");
    
    for(i=0; i<n; i++){
	fscanf(input,"%f",&x[i]);
	sum=sum +x[i];
    }
    
    fclose(input);
    
    printf("\n\nThe sum is %3.2f.",sum);
    printf("\n\nThe average is %3.2f.\n\n",sum/i);
    
    return 0;
}