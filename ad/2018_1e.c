#include <stdio.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0





int KarakterToInteger(char x);
boolean IsAnA(char x);


int main()
{
	/*KAMUS*/
	char CC;
	
	
	
	
	
	
	
	
	/*ALGORITMA*/
	scanf("%c", &CC);
	switch (CC)
	{
		case '0' ... '9' :
			printf("%d", KarakterToInteger(CC));
			break;
		default :
			if (IsAnA)
			{
				printf("Bukan angka, tapi merupakan karakter A");
				
			}
			else
			{
				printf("Bukan angka dan bukan karakter A");
				
			}
		
		
		
		
		
	}






	
	
}


int KarakterToInteger(char x)
{
	switch (x)
	{
			case '0' :
				return 0;
				break;
			
			case '1' :
				return 1;
				break;
			case '2' :
				return 2;
				break;
			case '3' :
				return 3;
				break;
				
			case '4' :
				return 4;
				break;
				
			case '5' :
				return 5;
				break;
				
			case '6' :
				return 6;
				break;
				
			case '7' :
				return 7;
				break;
				
			case '8' :
				return 8;
				break;
				
			case '9' :
				return 9;
				break;
		
	}
	
	
	
	
	
	
}

boolean IsAnA (char x)
{
	return (x=='A');
	
}
