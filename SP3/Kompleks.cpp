#include "Kompleks.h"
#include <iostream>
using namespace std;

int Kompleks::n_kompleks = 0;

Kompleks::Kompleks(){
    real = 0;
    imaginer = 0;
    n_kompleks++;
}

// ctor dengan parameter
Kompleks::Kompleks(int real, int imaginer){
    this->real = real;
    this->imaginer = imaginer;
    n_kompleks++;
}

//mengembalikan bagian riil
int Kompleks::GetReal() const{
    return real;
}

// mengembalikan bagian imaginer
int Kompleks::GetImaginer() const{
    return imaginer;
}

// mengisi bagian riil
void Kompleks::SetReal(int _real){
    real = _real;
}

// mengisi bagian imaginer
void Kompleks::SetImaginer(int _imaginer){
    imaginer = _imaginer;
}

// operator overloading

// operator+ untuk melakukan penjumlahan dengan rumus berikut
// (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& K1, const Kompleks& K2){
    return Kompleks(K1.real + K2.real, K1.imaginer + K2.imaginer);
}

// operator- untuk melakukan pengurangan dengan rumus berikut
// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& K1, const Kompleks& K2){
    return Kompleks(K1.real - K2.real, K1.imaginer - K2.imaginer);
}

// operator* untuk melakukan perkalian dengan rumus berikut
// (a + bi)(c + di) = ac + bci + adi + bd i^2 = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& K1, const Kompleks& K2){
    return Kompleks(K1.real*K2.real-K1.imaginer*K2.imaginer, K1.real*K2.imaginer+K2.real*K1.imaginer);
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta
// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& K, const int c){
    return Kompleks(c*K.real, c*K.imaginer);
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta (sifat komutatif)
Kompleks operator* (const int c, const Kompleks& K){
    return Kompleks(c*K.real, c*K.imaginer);
}

// mengembalikan jumlah instance yang pernah dibuat
int Kompleks::CountKompleksInstance(){
    return n_kompleks;
}

// mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
// contoh:
// 3+5i
// 0+0i
// -5-4i
void Kompleks::Print(){
    cout << real;
    if (imaginer >= 0){
        cout << '+';
    }
    cout << imaginer << 'i' << endl;
}