#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    float T;





    /*ALGORITMA*/
    scanf("%f", &T);
    if (T<=0)
    {
        printf("Beku");
    }
    else if (T>0 && T<=100)
    {
        printf("Cair");
    }
    else
    {
        printf("Uap");
    }








    return 0;
}
