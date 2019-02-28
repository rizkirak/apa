#include "Circle.hpp"
#include <iostream>
using namespace std;

//ctor
Circle::Circle(float radius){
    this->radius = radius;
}
// getter & setter
float Circle::getRadius() const{
    return radius;
}
void Circle::setRadius(float radius){
    this->radius = radius;
}

// implementasi area (method untuk menghitung luas)
// untuk nilai phi gunakan nilai 3.14
float Circle::area(){
    return 3.14*radius*radius;
}
// implementasi perimeter (method untuk menghitung keliling)
// untuk nilai phi gunakan nilai 3.14
float Circle::perimeter(){
    return 6.28*radius;
}
// implementasi print (method untuk menampilkan informasi)
//format: CIRCLE(radius) diahkhiri endline
//contoh: CIRCLE(7)
void Circle::print(){
    cout << "CIRCLE(" << radius << ')' << endl;
}