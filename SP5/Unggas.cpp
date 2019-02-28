#include <iostream>
#include <cstring>
#include "Unggas.hpp"
using namespace std;
#define DEFSIZE 10

Unggas::Unggas(char* _nama){
    nama = new char[DEFSIZE];
    strcpy(nama, _nama);
    cout << "Unggas bernama " << nama << " menetas! :D" << endl;
}
Unggas::Unggas(const Unggas& U){
    nama = new char[DEFSIZE];
    strcpy(nama, U.nama);
}
Unggas& Unggas::operator=(const Unggas& U){
    strcpy(nama, U.nama);
    return *this;
}
Unggas::~Unggas(){
    cout << "Unggas bernama " << nama << " mati T.T" << endl;
    delete nama;
}