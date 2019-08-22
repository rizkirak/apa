#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;

    scanf("%d", &n);
    n=n/2;
    int bawah=2*n-1;
    int bintang=1;

    for (i=1;i<=n;i++)
    {
        int space=(bawah-(2*i-1))/2;
        for (j=1;j<=space;j++)
        {
            printf(" ");
        }

        for (j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        for (j=1;j<=space;j++)
        {
            printf(" ");
        }
        printf("\n");


    }
    for (i=n;i>=1;i--)
    {
        int space=(bawah-(2*i-1))/2;
        for (j=1;j<=space;j++)
        {
            printf(" ");
        }

        for (j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        for (j=1;j<=space;j++)
        {
            printf(" ");
        }
        printf("\n");


    }









    return 0;
}
