//
//  projectile.c
//
//  Created by V.H. Belvadi on 03/03/17.
//
//  Using functions and automatically plotting to gnuplot.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>

FILE *output;
float deg, v, g=9.81, d, x[100], y[100];
float rad, t1, t2, max, f=0.75;
float s[100],h[100];
int i=0, j=0, k=0, l=0, m=0, n=0, p=0;
int Y, N;
char filename[100], opt;
char * commandsForGnuplot[] = {"plot 'plot.temp' w linespoints"};

float angle(float deg){
    rad=deg*M_PI/180;
    return(rad);
}

float distance(float v, float rad){
    d=v*v*sin(2*rad)/g;
    return(d);
}

float height(float v, float rad){
    max=v*v*sin(rad)*sin(rad)/(2*g);
    return(max);
}

int main() {
    
    system("clear");
    
    printf("\n\nEnter the angle of throw:\t");
    scanf("%f",&deg);
    printf("\n\nEnter the velocity of throw:\t");
    scanf("%f",&v);
ASK:printf("\n\nPlease pick a filename to output data into:\t");
    scanf("%s",filename);
    if(0 == access(filename, 0)){
       printf("\n\nThis file exists. Do you want to add data to it (Y) or create a new file (N)?\t");
CHOICE:scanf(" %c",&opt); // The space before %c here is extremely important.
        Y=strncmp(&opt,"Y",1);
        N=strncmp(&opt,"N",1);
        if(Y==0){
            
        }
        else if(N==0){
            goto ASK;
        }
        else {
            printf("\n\nUnrecognised command. Please choose Y or N:\t");
            goto CHOICE;
        }
    }
    
    FILE * temp = fopen("plot.temp", "w");
    output=fopen(filename,"a+");
    
    system("clear");
    
    rad=angle(deg);
    d=distance(v,rad);
    max=height(v,rad);
    t1=tan(rad);
    t2=g/(2*v*v*cos(rad)*cos(rad));
    
    j=0;
    while(x[k]<=d){
        x[k]=j*d/100;
        y[k]=x[k]*t1-x[k]*x[k]*t2;
        if(y<0)
            break;
        fprintf(output, "%10.6f\t%15.6f\n",x[k],y[k]);
        fprintf(temp, "%10.6f\t%15.6f\n",x[k],y[k]);
        j++;
    }
    l=j;
    
    printf("\n\nAngle of throw in radian = %0.5f",rad);
    printf("\n\nMaximum height = %0.3f",max);
    printf("\n\nRange of the projectile = %0.3f",d);
    
    fclose(output);
    printf("\n\nThe output has been written to %s.\n\n",filename);
    
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    
    return 0;
}