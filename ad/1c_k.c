#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int HH;
    int MM;
    int SS;
} Jam;






int main()
{
    /*KAMUS*/
    Jam JamAkhir, JamAwal;
    int a, b, s;




    /*ALGORITMA*/
    scanf("%d %d %d", &JamAwal.HH, &JamAwal.MM, &JamAwal.SS);
    scanf("%d %d %d", &JamAkhir.HH, &JamAkhir.MM, &JamAkhir.SS);
    a = JamAwal.HH*3600+JamAwal.MM*60+JamAwal.SS;
    b = JamAkhir.HH*3600+JamAkhir.MM*60+JamAkhir.SS;
    printf("%d", b-a);









    return 0;
}
