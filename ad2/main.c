#include <stdio.h>
#include <stdlib.h>
#include "jam.h"
#include "point.h"
/*
int main()
{

    JAM J1,J2,J3;
    long a;


    BacaJAM(&J1);
    TulisJAM(J1);
    printf("JtD : %ld\n", JAMToDetik(J1));
    J2 = DetikToJAM(99999999);
    TulisJAM(J2);
    printf("%d\n", JEQ(J1,J2));
    printf("%d\n", JNEQ(J1,J2));
    printf("%d\n", JLT(J1,J2));
    printf("%d\n", JGT(J1,J2));
    J3=NextDetik(J1);
    TulisJAM(J3);
    J3=NextNDetik(J1, 100);
    TulisJAM(J3);
    J3=PrevDetik(J1);
    TulisJAM(J3);
    J3=PrevNDetik(J1, 100);
    TulisJAM(J3);
    printf("%ld\n", Durasi(J1,J2));


    POINT P1;
    BacaPOINT(&P1);
    Putar(&P1, 30.0);
    TulisPOINT(P1);






    return 0;
}
*/



int main()
{
    JAM J1, J2;
    long jam_min=99999999;
    long jam_max=-9999999, dur;
    int n,i;


    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        BacaJAM(&J1);
        BacaJAM(&J2);

        if (JLT(J1,J2))
        {
            dur=Durasi(J1, J2);
            if (JAMToDetik(J1)<jam_min)
            {
                jam_min=JAMToDetik(J1);
            }
            if (JAMToDetik(J2)>jam_max)
            {
                jam_max=JAMToDetik(J2);
            }


        }
        else
        {
            if (JAMToDetik(J2)<jam_min)
            {
                jam_min=JAMToDetik(J2);
            }
            if (JAMToDetik(J1)>jam_max)
            {
                jam_max=JAMToDetik(J1);
            }




        }
        printf("%ld\n", dur);







    }
    TulisJAM(DetikToJAM(jam_min));
    printf("\n");
    TulisJAM(DetikToJAM(jam_max));
    printf("\n");







}


















