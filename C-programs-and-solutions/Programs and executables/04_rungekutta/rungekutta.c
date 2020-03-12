//
//  rungekutta.c
//
//  Created by V.H. Belvadi on 03/03/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float functionOf(float x, float y){
    // Code in the required function below
    // For now we have (y+x)/(y*x)
    return (y+x)/(y*x);
}

int main(){
    
    float K, K1, K2, K3, K4;
    float x0 , y0, x, y, i, interval;
    int j, n;
    
    system("clear");
    
    printf("\n\nSuggest any initial value for x:\t");
    scanf("%f", &x0);
    printf("\n\nSuggest any initial value for y:\t");
    scanf("%f", &y0);
    printf("\n\nEnter the number of iterations needed:\t");
    scanf("%d", &n);
    printf("\n\nEnter the skip between interations:\t");
    scanf("%f", &interval);
    
    printf("\n\n");
    
    x = x0;
    y = y0;
    for(i = x+interval, j = 0; j < n; i += interval, j++){
        K1 = interval * functionOf(x , y);
        K2 = interval * functionOf(x+interval/2, y+K1/2);
        K3 = interval * functionOf(x+interval/2, y+K2/2);
        K4 = interval * functionOf(x+interval, y+K3);
        K = (K1 + 2*K2 + 2*K3 + K4)/6;
        x = i;
        y = y + K;
        
        printf("\t\t\t x = %.2f \t y = %.4f\n", x, y);
        
        // inf means infinity, NaN is an error for which we provide an explanation
        if( isnan(x) || isnan(y) )
            printf("\nThere seems to be an error in line %d. \nCheck your suggested initial values \nsince not all initial values work \nfor all functions.",j);
    }
    
    printf("\n\n");
    
    return 0;
}