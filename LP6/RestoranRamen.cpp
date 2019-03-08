/*
Nama : Muhammad Rizki Fonna
NIM  : 13516001

*/

#include <map>
#include <iostream> 
#include "RestoranRamen.hpp"
using namespace std;

void RestoranRamen::tambahOrder(int n, int p)
{
    map<int, int>::iterator itr = this->daftarMeja.find(n);
    
    if(itr != this->daftarMeja.end())
    {
        this->daftarMeja[n]+=p;
    }
    else
    {
        this->daftarMeja.insert(pair<int, int>(n, p));
    }

}

int RestoranRamen::tutupOrder(int n)
{
    int temp = this->daftarMeja[n];
    this->daftarMeja.erase(n);
    return temp;
}

int RestoranRamen::cekTotal(int n)
{
    return this->daftarMeja[n];
}

int RestoranRamen::totalMeja()
{
    int count = 0;
    for(auto i = this->daftarMeja.begin(); i != this->daftarMeja.end(); i++){
        count++;
    }
    return count;
}

void RestoranRamen::cetakMeja()
{
    bool empty = true;
    
    for(auto i = this->daftarMeja.begin(); i != this->daftarMeja.end(); i++)
    {
        empty = false;
        cout << "Meja " << i->first << " = " << i->second << endl;
    }
    if(empty) cout << "Restoran kosong" << endl;
}
