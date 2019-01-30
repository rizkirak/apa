#include <iostream>
#include "Pecahan.h"

using namespace std;


int main()
{
	//Deklarasi Variabel
	int b,c,d;
	Pecahan *e;
	
	
	
	Pecahan a(1,3,2);
	a.keluaran();
	b=a.getBulat ();
	cout<<"getBulat = "<<b<<endl;
	c=a.getPembilang ();
	cout<<"getPembilang = "<<c<<endl;
	d=a.getPenyebut();
	cout<<"getPenyebut = "<<d<<endl;
	//cout<<"makan"<<endl;
	a.setBulat(1);
	a.keluaran();
	a.setPembilang(2);
	a.keluaran();
	//cout<<Pecahan::isValid(1,1,2)<<endl;
	
	e=new Pecahan[10];
	
}
