#include "Artikel.hpp"
#include <iostream>
#include <cstring>
using namespace std;

Artikel::Artikel(){
    judul = new char[DEFSIZE];
    penulis = new char [DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        judul[i] = '\0';
        penulis[i] = '\0';
    }
    tahun = 0;
}
Artikel::Artikel(char* j, char* p, int t){
    judul = new char[DEFSIZE];
    penulis = new char [DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        judul[i] = '\0';
        penulis[i] = '\0';
    }
    strcpy(judul, j);
    strcpy(penulis, p);
    tahun = t;
}
Artikel::Artikel(const Artikel& a){
    judul = new char[DEFSIZE];
    penulis = new char [DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        judul[i] = '\0';
        penulis[i] = '\0';
    }
    strcpy(judul, a.judul);
    strcpy(penulis, a.penulis);
    tahun = a.tahun;
}
Artikel::~Artikel(){
    delete judul;
    delete penulis;
}
Artikel& Artikel::operator=(const Artikel& a){
    strcpy(judul, a.judul);
    strcpy(penulis, a.penulis);
    tahun = a.tahun;
    return *this;
}
char* Artikel::getJudul() const{
    return judul;
}
char* Artikel::getPenulis() const{
    return penulis;
}
int Artikel::getTahun() const{
    return tahun;
}

void Artikel::setJudul(char* j){
    strcpy(judul, j);
}
void Artikel::setPenulis(char* p){
    strcpy(penulis, p);
}
void Artikel::setTahun(int t){
    tahun = t;
}

void Artikel::print() const{
    cout << penulis << ". " << tahun << ". \"" << judul << "\"." << endl;
}
