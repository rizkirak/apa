#include "warna.h"
#include <math.h>

/**
    Kelas ArrayWarna, menyimpan dua buah array, array pertama berisi objek T dan array kedua berisi objek Warna 
    Ukuran maksimum pada array ditandai dengan atribut size dan jumlah elemen pada array ditandai dengan atribut neff
*/

template <class T>
class ArrayWarna {
public:
    // cctor tanpa parameter dengan ukuran maksimum 10
	ArrayWarna<T>()
    {
        data = new T[10];
        warna = new Warna<T>[10];
        size = 10;
        neff = 0;
    }
    // Membuat sebuah ArrayWarna dengan ukuran maksimum n
    ArrayWarna<T>(int N)
    {
        data = new T[N];
        warna = new Warna<T>[N];
        size = 10;
        neff = 0;
    }
    // cctor
    ArrayWarna<T>(const ArrayWarna<T>& X)
    {
        data = new T[X.size];
        warna = new Warna<T>[X.size];
        size = 10;
        neff = X.neff;
        for (int i = 0; i<neff; i++){
            data[i] = X.data[i];
            warna[i] = X.warna[i];
        }
    }
    // Operator=
    ArrayWarna<T>& operator=(const ArrayWarna<T>& X){
        delete[] warna;
        delete[] data;
        data = new T[X.size];
        warna = new Warna<T>[X.size];
        size = 10;
        neff = X.neff;
        for (int i = 0; i<neff; i++){
            data[i] = X.data[i];
            warna[i] = X.warna[i];
        }
    }

    // true jika array penuh
    bool isFull(){
        return neff == size;
    }
    // true jika array kosong
    bool isEmpty(){
        return neff == 0;
    }

    // Getter
    int getSize() const{
        return size;
    }
    int getNeff() const{
        return neff;
    }
    
    // Menambahkan elemen warna dan data di akhir array
    void addElement(T D, Warna<T> W){
        if(!isFull()){
            data[neff] = D;
            warna[neff] = W;
            neff++;
        }
    }
    // Mengubah warna dan data pada index ke n
    void setElement(T D, Warna<T> W, int n){
        if(!isFull()){
            data[n] = D;
            warna[n] = W;
            neff++;
        }
    }

    // Mengembalikan data pada index ke n; n TIDAK mungkin di luar index
    T getData(int n){
        return data[n];
    }
    // Mengembalikan warna pada index ke n; n TIDAK mungkin di luar index
    Warna<T> getWarna(int n){
        return warna[n];
    }
private:
	T *data;
	Warna<T> *warna;
	int size;
	int neff;
};
