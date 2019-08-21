#include <stdio.h>
#include <stdlib.h>


void PROCTUKAR (int *a, int *b);


int main()
{
	int a,b,c;
	
	
	scanf("%d %d %d", &a, &b ,&c);
	PROCTUKAR(&a,&c);
	PROCTUKAR(&b,&c);
	printf("%d %d %d", a,b,c);
	
	
	
	
	
	
	
}





void PROCTUKAR (int *a, int *b)
{
	int Temp;
	
	
	Temp=*a;
	*a=*b;
	*b=Temp;
	
	
}
