//
//  quadratic.c
//
//  Created by V.H. Belvadi on 02/03/17.
//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    
    float a,b,c;
    float d,root1,root2;
    
    system("clear");
    
    printf("\n\nEnter a, b and c of quadratic equation ax^2 + bx + c below: \n\n");
    scanf("%f%f%f",&a,&b,&c);
    
    d = b * b - 4 * a * c;
    
    if(d < 0){
        printf("\n\nThe equation has complex roots.\n\n");
        
        printf("They are ");
        printf("%.3f%+.3fi",-b/(2*a),sqrt(-d)/(2*a));
        printf("and %.3f%+.3fi.\n\n",-b/(2*a),-sqrt(-d)/(2*a));
        
        return 0;
    }
    else if(d==0){
        printf("The equation has two equal roots.\n\n");
        
        root1 = -b /(2* a);
        printf("They are both %.3f.\n\n",root1);
        
        return 0;
    }
    else{
        printf("The equation has are real roots.\n\n");
        
        root1 = ( -b + sqrt(d)) / (2* a);
        root2 = ( -b - sqrt(d)) / (2* a);
        printf("They are %.3f and %.3f.\n\n",root1,root2);
    }
    
    return 0;
}
