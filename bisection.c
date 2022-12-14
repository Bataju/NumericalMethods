#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float function(float x)
{
    return log(x)*sin(x);
}

int main()
{
    const float e=0.0005;//tolerable error
    int n, count;
    float a, b, c, result;
    printf("Set the range\nEnter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    if((function(a)*function(b))>0)
    {
        printf("The function values are of the same sign at the endpoints of the range given.");
        exit(-1);
    }
    else if((function(a)*function(b))==0)
    {
        //either a or b is the solution
        if(function(a)==0)
        {
            printf("Solution in the given range: %f\n", a);
        }
        if(function(b)==0)
        {
            printf("Solution in the given range: %f", b);
        }
        //in case both the endpoints are the solutions.
        exit(0);
    }
    else
    {
        count=0;
        //max times the loop should execute
        n = (log(fabs(b-a))-log(e))/log(2);
        do
        {
            count++;
            c=(a+b)/2;
            if((function(a)*function(c))<0)
                b=c;
            else
                a=c;
            if(count==2*n)
            {
                printf("No solution in the region");
                exit(-1);
            }
        } while (fabs(function(c))>=e);
        result = c;
    }
    printf("Solution in the given range: %f", result);
    return 0;
}