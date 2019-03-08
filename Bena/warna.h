#include <math.h>
/*
    Kelas Generik Warna, memiliki tiga atribut R,G dan B.
*/

template <class T>
class Warna {
public:
    // Ctor tanpa parameter
	Warna<T>() {
		r = 0;
		g = 0;
		b = 0;
	}
    // Ctor berparameter, parameter berturut-turut R,G,B
     Warna<T>(T _r, T _g, T _b) {
		r = _r;
		g = _g;
		b = _b;
	}
	
    // cctor
    Warna<T>(const Warna<T>& _T) {
		r = _T.r;
		g = _T.g;
		b = _T.b;
	}	
	
    // Operator=
     Warna<T>& operator=(const Warna<T>& _T) {
		r = _T.r;
		g = _T.g;
		b = _T.b;
		return *this;
	}

    // Getter dan setter
    T getRed() const {
		return r;
	}
	
    T getGreen() const {
		return g;
	}
	
    T getBlue() const {
		return b;
	}
    
    void setRed(T _T) {
		r = _T;
	}
	
    void setGreen(T _T) {
		g = _T;
	}
	
    void setBlue(T _T) {
		b = _T;
	}

    //menghasilkan perbedaan absolut antara nilai R, G, dan B [difference = abs(r1-r2) + abs(g1-g2) + abs(b1-b2)]
    T countDifference(Warna<T> _T) {
		T diff;
		
		diff = abs(r - _T.r) + abs(g - _T.g) + abs(b - _T.b);
		return diff;
	}

    // Operator overloading, mengubah nilai warna
    Warna<T> operator +(const Warna<T>& _T) const { //rnew=r1+r2, gnew=g1+g2, bnew = b1+b2
		r += _T.r; 
		g += _T.g;
		b += _T.b;
	}
	
    Warna<T> operator -(const Warna<T>& _T) const { //rnew=r1-r2, gnew=g1-g2, bnew = b1-b2
		r -= _T.r;
		g -= _T.g;
		b -= _T.b;
	}

private:
	T r;
	T g;
	T b;
};

