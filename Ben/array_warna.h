#include "warna.h"

/**
    Kelas ArrayWarna, menyimpan dua buah array, array pertama berisi objek T dan array kedua berisi objek Warna 
    Ukuran maksimum pada array ditandai dengan atribut size dan jumlah elemen pada array ditandai dengan atribut neff
*/

template <class T>
class ArrayWarna {
public:
    // cctor tanpa parameter dengan ukuran maksimum 10
	ArrayWarna<T>();
    // Membuat sebuah ArrayWarna dengan ukuran maksimum n
    ArrayWarna<T>(int);
    // cctor
    ArrayWarna<T>(const ArrayWarna<T>&);
    // Operator=
    ArrayWarna<T>& operator=(const ArrayWarna<T>&);
    
    ~ArrayWarna<T>();

    // true jika array penuh
    bool isFull(){
		return size == neff;
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
    void addElement(T, Warna<T>);
    // Mengubah warna dan data pada index ke n
    void setElement(T, Warna<T>, int);

    // Mengembalikan data pada index ke n; n mungkin di luar index
    T getData(int);
    
    // Mengembalikan warna pada index ke n; n mungkin di luar index
    Warna<T> getWarna(int);
private:
	T *data;
	Warna<T> *warna;
	int size;
	int neff;
};

template <class T>
ArrayWarna<T>::ArrayWarna(){
	size = 10;
	data = new T [size];
	warna = new Warna<T> [size];
	neff = 0;
}

template <class T>
ArrayWarna<T>::ArrayWarna(int n){
	size = n;
	data = new T [size];
	warna = new Warna<T> [size];
	neff = 0;
}

template <class T>
ArrayWarna<T>::~ArrayWarna(){
	delete [] data;
	delete [] warna;
}

template <class T>
ArrayWarna<T>::ArrayWarna(const ArrayWarna<T>& m){
	size = m.size;
	data = new T [size];
	warna = new Warna<T> [size];
	neff = m.neff;
	
	for(int i=0;i<neff;i++){
		data[i] = m.data[i];
		warna[i] = m.warna[i];
	}
}

template <class T>
ArrayWarna<T>& ArrayWarna<T>::operator=(const ArrayWarna<T>& m){
	delete [] data;
	delete [] warna;
	
	size = m.size;
	data = new T [size];
	warna = new Warna<T> [size];
	neff = m.neff;
	
	for(int i=0;i<neff;i++){
		data[i] = m.data[i];
		warna[i] = m.warna[i];
	}
	
	return *this;
}

template <class T>
void ArrayWarna<T>::addElement(T obj, Warna<T> col){
	data[neff] = obj;
	warna[neff] = col;
	
	neff++;
}

template <class T>
void ArrayWarna<T>::setElement(T obj, Warna<T> col, int idx){
	data[idx] = obj;
	warna[idx] = col;
}

template <class T>
T ArrayWarna<T>::getData(int idx){
	if(idx < neff && !(this->isEmpty()) && idx >= 0){
		return data[idx];
	}
}

template <class T>
Warna<T> ArrayWarna<T>::getWarna(int idx){
	if(idx < neff && !(this->isEmpty()) && idx >= 0){
		return warna[idx];
	}
}
