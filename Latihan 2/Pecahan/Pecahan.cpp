#include <iostream>
#include "Pecahan.h"

using namespace std;

Pecahan::Pecahan()
{
	n=1;
    a=0;
    b=1;
	
}

Pecahan::Pecahan(int n, int a, int b)
{
	if ((b==0) || (a<0))
    {

    }
    else
    if (a>=b)
    {
        n+=(a%b);
        //cout<<"1. "<<n<<endl;
        a-=(a%b)*b;
        //cout<<"2. "<<a<<endl;
        //cout<<"3. "<<b<<endl;
        this->n=n;
        this->a=a;
        this->b=b;
    }
    //Belum buat pake gcd

	
}

int Pecahan::getBulat ()
{
	return n;
	
}

int Pecahan::getPembilang ()
{
	return a;
	
}

int Pecahan::getPenyebut()
{
	return b;
	
}

void Pecahan::setBulat(int _n)
{
	if (isValid(_n,a,b))
	{
		n=_n;
	}
	
}

void Pecahan::setPembilang(int _a)
{
	if (isValid(n,_a,b))
	{
		a=_a;
	}
	
}





bool Pecahan::isValid (int n, int a, int b)
{
	return (n>=0)&&(a>=0)&&(b>1);
}



void Pecahan::keluaran()
{
	cout<<n<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
}
