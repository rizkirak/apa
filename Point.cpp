#include "Point.h"
#include "Printer.h"

class Point {
public:
    // Constructor
    // Set titik mula-mula ke (0, 0)
	Point(){
		x=0;y=0;
	}
    // Getter
    int getAbsis(){
    	return x;
    }
    int getOrdinat(){
    	return y;
    }
    // Setter
    void setAbsis(int x){
    	this->x=x;
    }
    void setOrdinat(int y){
    	this->y=y;
    }
    void print(){
    	Printer::print(x);
    	Printer::print(y);
    } // print absis, kemudian ordinat dengan memanfaatkan Printer
    private int x, y; // abscissa and ordinate
}