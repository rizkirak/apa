#include "Circle.h"
#include <iostream>
using namespace std;

// inisiasi static member
int Circle::n=0;


// ctor
Circle::Circle(){
	radius=0;
	color="red";
	cout << "Tercipta = " << ++n << endl;
}
// constructor
Circle::Circle(double r, string c){
	radius=r;
	color=c;
	cout << "Tercipta = " << ++n << endl;
}
// cctor
Circle::Circle(const Circle& C){
	radius=C.getRadius();
	color=C.getColor();
	cout << "Tercipta = " << ++n << endl;
}
// dtor
Circle::~Circle(){
	cout << "Sisa = " << --n << endl;
}

// getter & setter
double Circle::getRadius() const {
	return radius;
}
string Circle::getColor() const {
	return color;
}
void Circle::setRadius(double r){
	radius=r;
}
void Circle::setColor(string c){
	color=c;
}
//function
double Circle::getArea() const {
	return radius*radius*3.14159265;
}