/*
 * Nama     : Dery Rahman A
 * NIM      : 13515097
 * Topik    : Praktikum Sekawan dan Inheritance
 * Tanggal  : 10-02-2017
 */

#include "SpecialMatriks.h"
#include "Matriks.h"
#include <iostream>
using namespace std;

SpecialMatriks::SpecialMatriks() : Matriks(){}
SpecialMatriks::SpecialMatriks(int n) : Matriks(n,n){}
SpecialMatriks::SpecialMatriks(const SpecialMatriks& sm) : Matriks(sm){}
SpecialMatriks::~SpecialMatriks(){}
SpecialMatriks& SpecialMatriks::operator= (SpecialMatriks& sm){
    for(int i=0;i<sm.n_brs;i++){
        for(int j=0;j<sm.n_kol;j++){
            this->b[i][j]=sm.b[i][j];
        }
    }
    return *this;
}
SpecialMatriks& SpecialMatriks::operator+ (SpecialMatriks sm2){
    int n_max=(n_brs<sm2.GetBrs())?sm2.GetBrs():n_brs;
    
    SpecialMatriks *mRes=new SpecialMatriks(n_max);
    for(int i=0;i<n_brs;i++){
        for(int j=0;j<n_kol;j++){
            mRes->b[i][j]=this->b[i][j];
        }
    }
    for(int i=0;i<sm2.GetBrs();i++){
        for(int j=0;j<sm2.GetKol();j++){
            mRes->b[i][j]=mRes->b[i][j] || sm2.b[i][j];
        }
    }

    return *mRes;   
}
SpecialMatriks& operator* (const SpecialMatriks& sm1, const SpecialMatriks& sm2){
    int n_max=(sm1.n_brs<sm2.n_brs)?sm2.n_brs:sm1.n_brs;
    
    SpecialMatriks *mRes=new SpecialMatriks(n_max);
    for(int i=0;i<sm1.n_brs;i++){
        for(int j=0;j<sm1.n_kol;j++){
            mRes->b[i][j]=sm1.b[i][j];
        }
    }
    for(int i=0;i<sm2.n_brs;i++){
        for(int j=0;j<sm2.n_kol;j++){
            if(i<sm1.n_brs && j<sm1.n_kol)
                mRes->b[i][j]=mRes->b[i][j] && sm2.b[i][j];
            else
                mRes->b[i][j]=sm2.b[i][j];
        }
    }
    
    return *mRes;
}

void SpecialMatriks::SetData (int i, int j, int v){
	if(v==1)
		this->b[i][j]=1;
	else
		this->b[i][j]=0;
}