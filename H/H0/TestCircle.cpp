#include <iostream>
#include "Circle.h"
using namespace std;

int main(){
	Circle c1(1.2,"Blue");
	{
		Circle c2(c1);
	}
	cout << "BAM" << endl;
	return 0;
}