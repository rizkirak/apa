#include <string>
using namespace std;

class Circle {
public :
	// default constructor
	Circle(double radius=1.0, string color="red");

	// ctor
	Circle();
	// cctor
	Circle(const Circle&);
	// dtor
	~Circle();

	// getter
	double getRadius() const;
	string getColor() const;

	// setter
	void setRadius(double);
	void setColor(string);

	// function
	double getArea() const;
private:
	double radius;
	string color;
	static int n;
};