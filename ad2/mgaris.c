#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "garis.h"




int main()
{
	GARIS L;
	BacaGARIS(&L);
	TulisGARIS(L);
	printf("%f\n", PanjangGARIS(L));
	printf("%f\n", Gradien(L));
	GeserGARIS(&L, 1,5);
	TulisGARIS(L);
	return 0;
	
	
}




