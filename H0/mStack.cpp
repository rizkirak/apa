#include <iostream>
#include "Stack_generic.h"
using namespace std;

int main(){
	Stack<float>* pts;
	Stack<float> s1;
	pts = new Stack<float>;
	*pts << 20.3;
	*pts << 30.12;
	*pts << 40.1;
	pts->Print();
	s1=*pts;
	s1.Print();
	Stack<float> s2=*pts+s1;
	s2.Print();
	delete pts;
	return 0;
}