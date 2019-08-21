#include <stdio.h>
#include <stdlib.h>




int main()
{
	/*KAMUS*/
	float I, R, V;
	
	
	
	
	/*ALGORITMA*/
	printf("Input nilai arus : ");
	scanf("%f", &I);
	printf("Input nilai hambatan : ");
	scanf("%f", &R);
	V=I*R;
	printf("Tegangan listrik = %f volt", V);
	
	return 0;
	
	
	
	
	
}
