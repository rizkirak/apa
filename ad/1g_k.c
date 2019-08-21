#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int i, m, sum=0;





    /*ALGORITMA*/
    i=0;
    scanf("%d", &m);
    if (m==9999)
    {
        printf("Banyaknya bilangan = 0 dan jumlah = 0");
    }
    else
    {
        while (m!=9999)
        {
            sum +=m;
            i+=1;
            scanf("%d", &m);
        }
        printf("Banyaknya bilangan = %d dan jumlah = %d\n", i, sum);





    }








    return 0;
}
