#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int a,b,c, temp1, temp2;





    /*ALGORITMA*/
    scanf("%d %d %d", &a, &b, &c);
    temp1=a;
    a=c;
    temp2=b;
    b=temp1;
    c=temp2;
    printf("%d %d %d", a, b, c);







    return 0;
}
