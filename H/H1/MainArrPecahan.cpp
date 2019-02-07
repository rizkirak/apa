/*
 * Nama : Dery Rahman A
 * Nim  13515097
//  */
#include <iostream>
using namespace std;
#include "Pecahan.h"

extern Pecahan * MyArrPecahan;

int main () {

// deklarasi variabel yang anda butuhkan
    int N;
    int n,a,b;
// program membaca nilai N
    cin >> N;
// program melakukan alokasi array MyArrPecahan sebanyak N
    Pecahan MyArrPecahan[N];
// Program mengulangi membaca N buah Pecahan dan menyimpannya dalam array
    Pecahan sum(0,0,1);
    
    for(int i=0;i<N;i++){
        cin >> n >> a >> b;
        Pecahan P1(n,a,b);
        MyArrPecahan[i]=P1;
        // cout << P1.getBulat() << P1.getPembilang() << P1.getPenyebut() << endl;
        sum.accumulate(P1);
    }
    
    cout << sum.getBulat() << " " << sum.getPembilang() << " " << sum.getPenyebut() << endl;
    
    Pecahan ArrLipat[N];
    int max=0;
    
    for(int i=0;i<N/2;i++,max++){
        Pecahan P2(0,0,1);
        P2=P2.add(MyArrPecahan[i],MyArrPecahan[N-1-i]);
        ArrLipat[i]=P2;
    }
    if((N%2)==1)
        ArrLipat[max++]=MyArrPecahan[(N/2)+1];
    
    
    for(int i=0;i<max;i++){
        cout << ArrLipat[i].getBulat() << " " << ArrLipat[i].getPembilang() << " " << ArrLipat[i].getPenyebut() << endl;
    }
    
    Pecahan Max(0,0,1);
    Pecahan Min(0,0,1);
    Min=Min.addWithThis(MyArrPecahan[0]);
    for(int i=0;i<N;i++){
        if(Max.isGTMe(MyArrPecahan[i]))
            Max=Max.addWithThis(MyArrPecahan[i]);
        
        if(Min.isLTMe(MyArrPecahan[i]))
            Min=Min.addWithThis(MyArrPecahan[i]);
    }
    cout << Max.getBulat() << " " << Max.getPembilang() << " " << Max.getPenyebut() << endl;
    cout << Min.getBulat() << " " << Min.getPembilang() << " " << Min.getPenyebut()<< endl;
    
    cout << Min.value() << endl;
    
/* program menghasilkan: (1) penjumlahan semua nilai pecahan, (2) beberapa baris berisi array yang disebut nilai “lipat”, (3) 1 baris berisi pecahan bernilai
 maksimum dan (4) 1 baris berisi pecahan bernilai minimumnya*/

// dan menuliskan dengan output sesuai format yang diberikan pada Contoh

return 0;

}