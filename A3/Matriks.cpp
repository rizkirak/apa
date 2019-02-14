/*
 * Nama     : Dery Rahman A
 * NIM      : 13515097
 * Topik    : Praktikum Sekawan dan Inheritance
 * Tanggal  : 10-02-2017
 */

#include "Matriks.h"
#include <iostream>
using namespace std;

Matriks::Matriks() : n_brs(DEFSIZE), n_kol(DEFSIZE){
    this->b=new int*[this->n_brs];
    for(int i=0;i<this->n_brs;i++){
        this->b[i]=new int[this->n_kol];
        for(int j=0;j<this->n_kol;j++){
            this->b[i][j]=0;
        }
    }
}

Matriks::Matriks(int n, int m) : n_brs(n), n_kol(m){
    this->b=new int*[this->n_brs];
    for(int i=0;i<this->n_brs;i++){
        this->b[i]=new int[this->n_kol];
        for(int j=0;j<this->n_kol;j++){
            this->b[i][j]=0;
        }
    }
}

Matriks::Matriks(const Matriks& m) : n_brs(m.n_brs), n_kol(m.n_kol){
    this->b=new int*[this->n_brs];
    for(int i=0;i<this->n_brs;i++){
        this->b[i]=new int[this->n_kol];
        for(int j=0;j<this->n_kol;j++){
            this->b[i][j]=m.b[i][j];
        }
    }
}

Matriks::~Matriks(){
    for(int i=0;i<this->n_brs;i++)
        delete this->b[i];
    delete this->b;
}

Matriks& Matriks::operator= (Matriks& m){
    for(int i=0;i<m.n_brs;i++){
        for(int j=0;j<m.n_kol;j++){
            this->b[i][j]=m.b[i][j];
        }
    }
    return *this;
}

bool IsEqSize(Matriks m1, Matriks m2){
    return (m1.n_brs==m2.n_brs) && (m1.n_kol==m2.n_kol);
}

Matriks& Matriks::operator+ (Matriks m2){
    int brs_max=(this->n_brs<m2.n_brs)?m2.n_brs:this->n_brs;
    int kol_max=(this->n_kol<m2.n_kol)?m2.n_kol:this->n_kol;
    
    Matriks *mRes=new Matriks(brs_max,kol_max);
    for(int i=0;i<this->n_brs;i++){
        for(int j=0;j<this->n_kol;j++){
            mRes->b[i][j]=this->b[i][j];
        }
    }
    for(int i=0;i<m2.n_brs;i++){
        for(int j=0;j<m2.n_kol;j++){
            mRes->b[i][j]+=m2.b[i][j];
        }
    }

    return *mRes;                       
}

Matriks& operator* (const Matriks& m1, const Matriks& m2){
    int brs_max=(m1.n_brs<m2.n_brs)?m2.n_brs:m1.n_brs;
    int kol_max=(m1.n_kol<m2.n_kol)?m2.n_kol:m1.n_kol;
    
    Matriks *mRes=new Matriks(brs_max,kol_max);
    for(int i=0;i<m1.n_brs;i++){
        for(int j=0;j<m1.n_kol;j++){
            mRes->b[i][j]=m1.b[i][j];
        }
    }
    for(int i=0;i<m2.n_brs;i++){
        for(int j=0;j<m2.n_kol;j++){
            if(i<m1.n_brs && j<m1.n_kol)
                mRes->b[i][j]*=m2.b[i][j];
            else
                mRes->b[i][j]=m2.b[i][j];
        }
    }
    
    return *mRes;
}

ostream& operator<<(ostream &os, const Matriks& m){
    os<< "N = " << m.n_brs << endl;
    os<< "M = " << m.n_kol << endl;
    for(int i=0;i<m.n_brs;i++){
        for(int j=0;j<m.n_kol-1;j++){
            os << m.b[i][j] << " ";
        }
        os << m.b[i][m.n_kol-1] << endl;
    }
    return os;
}

void Matriks::SetData (int i, int j, int v){
    this->b[i][j]=v;
}
int Matriks::GetData (int i, int j){
    return this->b[i][j];
}

int Matriks::GetBrs(){
    return this->n_brs;
}
int Matriks::GetKol(){
    return this->n_kol;
}