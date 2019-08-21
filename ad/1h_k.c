#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int i,a;
    float sum;



    /*ALGORITMA*/
    i=0;
    sum=0;
    while (i<1000)
    {
        i+=1;
        if (i%2==0)
        {
            sum-=(float)1/i;
           //printf("-1/%d\n", i);
        }
        else
        {
            sum+=(float)1/i;
            //printf("1/%d\n", i);
        }



    }
    printf("%f", sum);







    return 0;
}
