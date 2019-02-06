#include "Tabel.h"
#include <iostream>

using namespace std;

Tabel::Tabel()
{
    int i;
    size=defaultSize;
    data_=new int[size];
    for (i=0;i<size;i++)
    {
        data_[i]=0;
    }
}

Tabel::Tabel(int size)
{
    int i;
    this->size=size;
    data_=new int[this->size];
    for (i=0;i<size;i++)
    {
        data_[i]=0;
    }
}

Tabel::Tabel(const Tabel& t)
{
    int i;

    size=t.size;
    data_=new int[size];
    for (i=0;i<size;i++)
    {
        data_[i]=t.data_[i];
    }




    //return n;
}

Tabel::~Tabel()
{
    delete [] data_;



    //return b;
}

Tabel& Tabel::operator=(const Tabel& rhs)
{
    int i;
    if (this!=&rhs)
    {
        size=rhs.size;
        for (i=0;i<size;i++)
        {
            data_[i]=rhs.data_[i];
        }
    }
    return *this;

}

void Tabel::UData(int a)
{
    int i;

    for (i=0;i<=size;i++)
    {
        data_[i]=a;
    }

}






void Tabel::keluaran()
{
    int i;
    cout<<size<<endl;
    cout<<"Tabel :"<<endl;
    for (i=0;i<size;i++)
    {
        cout<<"Data ke -"<<i<<":"<<data_[i]<<endl;




    }




    //return a;
}

/*
void Pecahan::keluaran()
{
    cout<<n<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}
*/






/*
Pecahan::~Pecahan()
{
    //dtor
}
*/

