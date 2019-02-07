/*
 * Nama : Dery Rahman A
 * NIM  : 13515097
 */

#include "Pecahan.h"
#include <iostream>
using namespace std;

    // 5 sekawan
    // ctor tanpa parameter
Pecahan::Pecahan (){
    //menghasilkan nilai <1,0,1>
    // ctor dengan parameter, harus menjamin membentuk pecahan yang valid
    n=1;
    a=0;
    b=1;
}
Pecahan::Pecahan (int n, int a, int b){ //Prekondisi: n,a,b membentuk pecahan valid
    /* n adalah bagian bulat positif, boleh nol   
       a adalah pembilang dan b adalah penyebut; 
       a/b adalah pecahan; a>=0; b > 0 (tidak boleh nol); b>a dan dinormalisasi
       contoh: 1 2/4 adalah pecahan dengan n=1, a=2 dan b=4 disimpan sbg 1 1/2
       contoh: 1 3/4 adalah pecahan dengan n=1, a=3 dan b=4
       jika user memberikan 1 3/2 maka pecahan yang dibentuk adalah 2 1/2
       <1,1,2) = 1 1/2; <0 1,2> = 1/2; <1,0,1> = 1.00; <1,0,4>=1.00; 
    */
    if(a>=b){
        n+=a/b;
        a=a%b;
    }
    
    if(a==0)
        b=1;
    this->n=n;
    this->a=a;
    this->b=b;
}
// dtor, operator= tidak perlu ditulis

// selector (getter) dan setter 
int Pecahan::getBulat (){
        return n;
}
int Pecahan::getPembilang (){
    return a;
}
int Pecahan::getPenyebut(){
    return b;
} 
// perhatikan set pada sebuah komponen harus menjamin tetap membentuk pecahan 
void Pecahan::setBulat(int _n){
    n=_n;
}
void Pecahan::setPembilang(int _a){
    a=_a;
}
void Pecahan::setPenyebut(int _b){
    b=_b;
}
// cek validitas
bool Pecahan::isValid (int n, int a, int b){
    return n>=0 && a>=0 && b>=1;
}
int GCD (int nx, int ny) {
  int n1, n2;
  n1=nx; n2=ny;
  while(n1 != n2)
  {
    if(n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  return n1;
}
Pecahan Pecahan::addWithThis (Pecahan P){
    Pecahan P1(P.getBulat(),P.getPembilang(),P.getPenyebut());
    return P1;
}
void Pecahan::accumulate(Pecahan P){
    int fpb=GCD(this->b,P.getPenyebut());
    int pengali_1=P.getPenyebut()/fpb;
    int pengali_2=(this->b)/fpb;
    this->a=(this->a)*pengali_1+P.getPembilang()*pengali_2;
    this->b=(this->b)*pengali_1;
    this->n+=P.getBulat();
    if(a>=b){
        n+=a/b;
        a=a%b;
    }    
    if(a==0)
        b=1;
} // Mennambahkan P ke current objek
Pecahan Pecahan::add(Pecahan P1, Pecahan P2){
    int fpb=GCD(P1.getPenyebut(),P2.getPenyebut());
    int pengali_1=P2.getPenyebut()/fpb;
    int pengali_2=P1.getPenyebut()/fpb;
    int a3=P1.getPembilang()*pengali_1+P2.getPembilang()*pengali_2;
    int b3=P1.getPenyebut()*pengali_1;
    int n3=P1.getBulat()+P2.getBulat();
    if(a3>=b3){
        n3+=a3/b3;
        a3=a3%b3;
    }
        if(a3==0)
            b3=1;
    Pecahan P3(n3,a3,b3);
    return P3;
} /* menghasilkan P1+P2 tanpa menyentuh current object, untuk sementara walau “aneh”, realisasikan */
    // operator logika
bool Pecahan::isEQMe(Pecahan P){
    return this->n==P.getBulat() && this->a==P.getPembilang() && this->b==P.getPenyebut();    
}

bool Pecahan::isGTMe(Pecahan P){
    if(P.getBulat()>(this->n))
        return true;
    else if(P.getBulat()<(this->n))
        return false;
    else {
        int fpb=GCD(this->b,P.getPenyebut());
        int pengali_1=P.getPenyebut()/fpb;
        int pengali_2=(this->b)/fpb;
        if(P.getPembilang()*pengali_2>(this->a)*pengali_1)
            return true;
        else
            return false;
    }
}
bool Pecahan::isLTMe(Pecahan P){
    if(P.getBulat()<(this->n))
        return true;
    else if(P.getBulat()>(this->n))
        return false;
    else {
        int fpb=GCD(this->b,P.getPenyebut());
        int pengali_1=P.getPenyebut()/fpb;
        int pengali_2=(this->b)/fpb;
        if(P.getPembilang()*pengali_2<(this->a)*pengali_1)
            return true;
        else
            return false;
    }    
}
float Pecahan::value(){
    float decimal=(float)(this->a)/(float)(this->b);
    float _n=(float)n;
    return (float)n+decimal;
}