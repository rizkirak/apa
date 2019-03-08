/**
    Kelas Generik Warna, memiliki tiga atribut R,G dan B.
*/

#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Warna {
public:
    // Ctor tanpa parameter
	Warna<T>();
    // Ctor berparameter, parameter berturut-turut R,G,B
    Warna<T>(T, T, T);
    // cctor
    Warna<T>(const Warna<T>&);
    // Operator=
    Warna<T>& operator=(const Warna<T>&);

    // Getter dan setter
    T getRed() const;
    T getGreen() const;
    T getBlue() const;
    
    void setRed(T);
    void setGreen(T);
    void setBlue(T);

    //menghasilkan perbedaan absolut antara nilai R, G, dan B (Warna(abs(r1-r2),abs(g1-g2),abs(b1-b2)))
    T countDifference(Warna<T>); 

    // Operator overloading, mengubah nilai warna
    Warna<T> operator +(const Warna<T>&) const; //rnew=r1+r2, gnew=g1+g2, bnew = b1+b2
    Warna<T> operator -(const Warna<T>&) const; //rnew=r1-r2, gnew=g1-g2, bnew = b1-b2
private:
	T r;
	T g;
	T b;
};

template <class T>
Warna<T>::Warna(){
	
}

template <class T>
Warna<T>::Warna(T red, T green, T blue){
	this->r = red;
	this->g = green;
	this->b = blue;
}

template <class T>
Warna<T>::Warna(const Warna<T>& w){
	this->r = w.r;
	this->g = w.g;
	this->b = w.b;
}

template <class T>
Warna<T>& Warna<T>::operator =(const Warna<T>& w){
	this->r = w.r;
	this->g = w.g;
	this->b = w.b;
	
	return *this;
}

template <class T>
T Warna<T>::getRed() const{
	return r;
}

template <class T>
T Warna<T>::getGreen() const{
	return g;
}

template <class T>
T Warna<T>::getBlue() const{
	return b;
}

template <class T>
void Warna<T>::setRed(T red){
	this->r = red;
}

template <class T>
void Warna<T>::setGreen(T green){
	this->g = green;
}

template <class T>
void Warna<T>::setBlue(T blue){
	this->b = blue;
}

template <class T>
T Warna<T>::countDifference(Warna<T> n){
	return (abs(this->r - n.r) + abs(this->g - n.g) + abs(this->b - n.b));
}

template <class T>
Warna<T> Warna<T>::operator +(const Warna<T>& n) const{
	Warna<T> w;
	w.r = this->r + n.r;
	w.g = this->g + n.g;
	w.b = this->b + n.b;
	
	return w;
}

template <class T>
Warna<T> Warna<T>::operator -(const Warna<T>& n) const{
	Warna<T> w;
	w.r = this->r - n.r;
	w.g = this->g - n.g;
	w.b = this->b - n.b;
	
	return w;
}
