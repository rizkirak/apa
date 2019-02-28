#include <iostream>
#include "Jurnal.hpp"
using namespace std; 

Jurnal::Jurnal(){
    data = new Artikel[DEFSIZE];
    size = 0;
}
Jurnal::Jurnal(Artikel* d, int s){
    size = s;
    data = new Artikel[DEFSIZE];
    for(int i = 0; i < size; i++){
        data[i] = d[i];
    }
}
Jurnal::Jurnal(const Jurnal& j){
    size = j.size;
    data = new Artikel[DEFSIZE];
    for(int i = 0; i < size; i++){
        data[i] = j.data[i];
    }
}
Jurnal::~Jurnal(){
    delete[] data;
}
Jurnal& Jurnal::operator= (const Jurnal& a){
    size = a.size;
    for(int i = 0; i < size; i++){
        data[i] = a.data[i];
    }
    return *this;
}

Artikel Jurnal::getData(int idx) const{
    return data[idx];
}
int Jurnal::getSize() const{
    return size;
}

void Jurnal::setData(int idx, const Artikel& a){
    if (idx<size){
        data[idx] = a;
    }
}
void Jurnal::setSize(int s){
    size = s;
}

void Jurnal::print() const{
    for (int i = 0; i < size; i++){
        cout << "Konten " << i+1 << endl;
        data[i].print(); 
    }
}
void Jurnal::add(const Artikel& a){
    data[size] = a;
    size++;
}
void Jurnal::insert(int idx, const Artikel& a){
    size++;
    for(int i = size; i > idx; i--){
        data[i] = data[i-1];
    }
    data[idx] = a;
}
int Jurnal::findByTahun(int t){
    int i = 0;
    bool found = false;
    while((i < size) && (!found)){
        if (data[i].getTahun() == t){
            found = true;
        }
        else{
            i++;
        }
    }
    return i;
}