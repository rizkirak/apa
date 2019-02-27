#include "Pecahan.h"
#include <iostream>
using namespace std;

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
int LCM(int nx, int ny){
    return nx*ny/GCD(nx,ny);
}

Pecahan::Pecahan(){
    n = 1;
    a = 0;
    b = 1;
} //menghasilkan nilai <1,0,1>
    // ctor dengan parameter, harus menjamin membentuk pecahan yang valid
Pecahan::Pecahan (int n, int a, int b){
    this->n = n;
    this->a = a;
    this->b = b;
    if(a>b){
        n += a/b;
        a = a%b;
        if (a == 0){
            b = 1;
        }
    }
    else if (a == b){
        n++;
        a = 0;
        b = 1;
    }
    if (a != 0){
        if (GCD(a,b) != 1){
            int gcd = GCD(a,b);
            a /= gcd;
            b /= gcd;
        }
    }
    else{
        b = 1;
    }
} //Prekondisi: n,a,b membentuk pecahan valid
/* n adalah bagian bulat positif, boleh nol   
    a adalah pembilang dan b adalah penyebut; 
    a/b adalah pecahan; a>=0; b > 0 (tidak boleh nol); b>a dan dinormalisasi
contoh: 1 2/4 adalah pecahan dengan n=1, a=2 dan b=4 disimpan sbg 1 1/2
contoh: 1 3/4 adalah pecahan dengan n=1, a=3 dan b=4
jika user memberikan 1 3/2 maka pecahan yang dibentuk adalah 2 1/2
<1,1,2) = 1 1/2; <0 1,2> = 1/2; <1,0,1> = 1.00; <1,0,4>=1.00; */
// dtor, operator= tidak perlu ditulis

// selector (getter) dan setter 
int Pecahan::getBulat (){
    return n;
}         //bagian bulat, n
int Pecahan::getPembilang (){
    return a;
}          //pembilang a
int Pecahan::getPenyebut(){
    return b;
}            //penyebut b  
// hanya boleh dilakukan jika dijamin dapat membentuk pecahan valid
// perhatikan set pada sebuah komponen harus menjamin tetap membentuk pecahan 
void Pecahan::setBulat(int _n){
    if (isValid(_n, a, b)){
        n = _n;
    }
}
void Pecahan::setPembilang(int _a){
    if (isValid(n, _a, b)){
        a = _a;
    }
    if(a>b){
        n += a/b;
        a = a%b;
        if (a == 0){
            b = 1;
        }
    }
    else if (a == b){
        n++;
        a = 0;
        b = 1;
    }
    if (a != 0){
        if (GCD(a,b) != 1){
            int gcd = GCD(a,b);
            a /= gcd;
            b /= gcd;
        }
    }
    else{
        b = 1;
    }
}
void Pecahan::setPenyebut(int _b){
    if (isValid(n, a, _b)){
        b = _b;
    }
    if(a>b){
        n += a/b;
        a = a%b;
        if (a == 0){
            b = 1;
        }
    }
    else if (a == b){
        n++;
        a = 0;
        b = 1;
    }
    if (a != 0){
        if (GCD(a,b) != 1){
            int gcd = GCD(a,b);
            a /= gcd;
            b /= gcd;
        }
    }
    else{
        b = 1;
    }
}
// cek validitas
bool Pecahan::isValid (int n, int a, int b){
    return n >= 0 && a >= 0 && b > 1;
} //hanya perlu cek apakah n>=0, a>=0, b >1 
// Aritmatika Pecahan
// semua operasi harus menjamin tetap membentuk pecahan valid.
// Misalnya 1 1/2 + 1 3/4 hasilnya adalah 3 1/4
// Jika pembilang dan penyebut sama, maka a = 0 dan b = 1
Pecahan Pecahan::addWithThis (Pecahan P){
    int tempb = b;
    b = LCM(b, P.b);
    a = b/tempb*a + b/P.b*P.a;
    n += P.n;
    if(a>b){
        n += a/b;
        a = a%b;
        if (a == 0){
            b = 1;
        }
    }
    else if (a == b){
        n++;
        a = 0;
        b = 1;
    }
    if (a != 0){
        if (GCD(a,b) != 1){
            int gcd = GCD(a,b);
            a /= gcd;
            b /= gcd;
        }
    }
    else{
        b = 1;
    }
    return *this;
} // Menghasilkan P + current objek
void Pecahan::accumulate(Pecahan P){
    int tempb = b;
    b = LCM(b, P.b);
    a = b/tempb*a + b/P.b*P.a;
    n += P.n;
    if(a>b){
        n += a/b;
        a = a%b;
        if (a == 0){
            b = 1;
        }
    }
    else if (a == b){
        n++;
        a = 0;
        b = 1;
    }
    if (a != 0){
        if (GCD(a,b) != 1){
            int gcd = GCD(a,b);
            a /= gcd;
            b /= gcd;
        }
    }
    else{
        b = 1;
    }
} // Mennambahkan P ke current objek
Pecahan Pecahan::add(Pecahan P1, Pecahan P2){
    int tempb = P1.b;
    P1.b = LCM(P1.b, P2.b);
    P1.a = P1.b/tempb*P1.a + P1.b/P2.b*P2.a;
    P1.n += P2.n;
    if(P1.a>P1.b){
        P1.n += P1.a/P1.b;
        P1.a = P1.a%P1.b;
        if (P1.a == 0){
            P1.b = 1;
        }
    }
    else if (P1.a == P1.b){
        P1.n++;
        P1.a = 0;
        P1.b = 1;
    }
    if (P1.a != 0){
        if (GCD(P1.a,P1.b) != 1){
            int gcd = GCD(P1.a,P1.b);
            P1.a /= gcd;
            P1.b /= gcd;
        }
    }
    else{
        P1.b = 1;
    }
    return P1;
} /* menghasilkan P1+P2 tanpa menyentuh current object, untuk sementara walau “aneh”, realisasikan */
// operator logika
bool Pecahan::isEQMe(Pecahan P){
    return value() == P.value();
} //true jika P sama dengan current object
bool Pecahan::isGTMe(Pecahan P){
    return value() < P.value();
} //true P > current object
bool Pecahan::isLTMe(Pecahan P){
    return value() > P.value();
} // trus jika P < current object
//operator lain
float Pecahan::value(){
    return n + (float) a/b;
} // menghasilkan nilai pecahan, misalnya 1 3/4 menjadi 1.75