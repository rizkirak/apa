// Circle.hpp

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
  public:
    //ctor
    Circle(float radius);
    // getter & setter
    float getRadius() const;
    void setRadius(float radius);

    // implementasi area (method untuk menghitung luas)
    // untuk nilai phi gunakan nilai 3.14
    float area();
    // implementasi perimeter (method untuk menghitung keliling)
    // untuk nilai phi gunakan nilai 3.14
    float perimeter();
    // implementasi print (method untuk menampilkan informasi)
    //format: CIRCLE(radius) diahkhiri endline
    //contoh: CIRCLE(7)
    void print();
  private:
    float radius;
};

#endif
