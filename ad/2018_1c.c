#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int HH;
	int MM;
	int DD;
	
	
	
	
} Jam;






int main()
{
	/*KAMUS*/
	Jam JamAwal, JamAkhir;
	int Durasi;
	
	
	
	
	
	/*ALGORITMA*/
	scanf("%d %d %d %d %d %d", &JamAwal.HH, &JamAwal.MM, &JamAwal.DD, &JamAkhir.HH, &JamAkhir.MM, &JamAkhir.DD);
	Durasi = JamAkhir.HH*3600+JamAkhir.MM*60+JamAkhir.DD-(JamAwal.HH*3600+JamAwal.MM*60+JamAwal.DD);
	printf("%d", Durasi);
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
