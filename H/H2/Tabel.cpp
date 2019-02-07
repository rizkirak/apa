/*
 * Nama     : Dery Rahman A
 * NIM      : 13515097
 * Topik    : Praktikum ADT dengan Pointer
 * Tanggal  : 2-02-2017
 */

#include "Tabel.h"

Tabel::Tabel(){
    size=defaultSize;
    data_=new int[defaultSize];
    for(int i=0;i<defaultSize;i++){
        data_[i]=Nil;
    }
}

Tabel::Tabel(int size){
    this->size=size;
    data_=new int[size];
    for(int i=0;i<size;i++){
        data_[i]=Nil;
    }
}

Tabel::Tabel(const Tabel& t){
    size=t.size;
    data_=new int[size];
    for(int i=0;i<size;i++){
        data_[i]=t.data_[i];
    }
}

Tabel::~Tabel(){
    size=0;
    delete data_;
}

int Tabel::GetSize(){
    return size;
}

int* Tabel::GetData(){
    return data_;
}

bool Tabel::IsEmpty(){
    for(int i=0;i<size;i++){
        if(data_[i]!=Nil)
            return false;
    }
    return true;
}

bool Tabel::IsFull(){
    int count=0;
    for(int i=0;i<size;i++){
        if(data_[i]!=Nil) count++;
    }
    return size==count;
}

void Tabel::Add(int x){
    int i=0;
    for(int i=0;i<size;i++){
        if(data_[i]==Nil){
            data_[i]=x;
            break;
        }
    }
}

int Tabel::Del(int i){
    int x=data_[i];
    data_[i]=Nil;
    return x;
}

void Tabel::DelX(int x){
    for(int i=0;i<size;i++){
        if(data_[i]==x){
            data_[i]=Nil;
            break;
        }
    }
}

int Tabel::NbElmt(){
    int count=0;
    for(int i=0;i<size;i++){
        if(data_[i]!=Nil) count++;
    }
    return count;
}

int Tabel::Sum(){
    int sum=0;
    for(int i=0;i<size;i++){
        if(data_[i]!=Nil) sum+=data_[i];
    }
    return sum;
}

bool Tabel::Or(){
    for(int i=0;i<size;i++){
        if(data_[i]==1) return true;
    }
    return false;
}

Tabel Tabel::Accumulate(){
    int acc=this->Sum();
    delete data_;
    size=1;
    data_=new int[size];
    data_[0]=acc;
    return *this;
}

bool Tabel::IsEq(Tabel t){
    if(size!=t.size) return false;
    for(int i=0;i<size;i++){
        if(data_[i]!=t.data_[i]) return false;
    }
    return true;
}

bool Tabel::IsBit(int i){
    return data_[i]==1 || data_[i]==0;
}