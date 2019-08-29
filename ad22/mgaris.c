#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "garis.h"




int main()
{
	GARIS L, L2;
	BacaGARIS(&L);
	TulisGARIS(L);
	printf("%f\n", PanjangGARIS(L));
	printf("%f\n", Gradien(L));
	GeserGARIS(&L, 1,5);
	TulisGARIS(L);
	BacaGARIS(&L2);
	printf("%d\n", IsTegakLurus(L,L2));
	printf("%d\n", IsSejajar(L,L2));
	return 0;
	
	
}




