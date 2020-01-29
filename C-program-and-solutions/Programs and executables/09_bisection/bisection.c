//
//  bisection.c
//
//  Created by V.H. Belvadi on 07/03/17.
//
//  An error limit of 10^(-4) and an upper limit
//  of 25 for iterations are used. These can
//  be changed as required or even asked from
//  the user by deleting the initialisations
//  and using a regular scanf command.
//
//  For 3x^3-9x-5 guesses 1 and 2 work well.
//  A possible root for this equation is 1.962.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define error 0.0001

double functionOf(double x)
{
    return (3*x*x*x - 9*x - 5);
}

int main()
{
    double guess_one,guess_two,guess,solution,soln_one,soln_two,previous;
    int root_exists=0,root_found=0,i=0,decor;
    double f(double);
    
    system("clear");
    
    printf("\n\nThe equation being used is 3x^(3) - 9x - 5 = 0\n\n");
    printf("\nEnter two guesses:\t ");
    
    while(root_exists==0) // Check guesses
    {
        scanf("%lf %lf",&guess_one,&guess_two);
        soln_one=functionOf(guess_one);
        soln_two=functionOf(guess_two);
        if(soln_one*soln_two>0)
        {
            root_exists=0;
            printf("\n\nThe root does not lie between %lf and %lf.\n",guess_one,guess_two);
            printf("\nPlease enter two new guesses:\t ");
        }
        else
            root_exists=1;
    }
    printf("\n\nThere is a real root which lies between %lf and %lf.\n\n",guess_one,guess_two);
    while(root_found==0) // Solve till a root is found
    {
        printf("\nIteration %d\n",i);
        for(decor=0; decor<=12; decor++)
            printf("=");
        printf("\n\na[%d](-ve) \tb[%d](+ve) \tx[%d] \t\tf(x[%d])\n",i,i,i+1,i+1);
        printf("%lf\t",guess_one);
        printf("%lf\t",guess_two);
        guess=(guess_one+guess_two)/2;
        solution=functionOf(guess);
        printf("%lf\t",guess);
        printf("%lf\n\n",solution);
        if(solution < 0)
            guess_one=guess;
        else
            guess_two=guess;
        if(fabs(previous-solution) < error)
            root_found=1;
        else
            previous=solution;
        i=i+1;
    }
    printf("\n\nThe root of f(x) is %lf to an accuracy of %f\n\n",guess,error);
    
    return 0;
}