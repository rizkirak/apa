#include <iostream>
using namespace std;

/*
class A {
public:
	A() { cout << "ctor A" << endl;}
	virtual void Print() { cout << "A" << endl;}
};
class B : public A {
public:
	B() { cout << "ctor B" << endl;}
	virtual void Print() { cout << "B" << endl; }  //redefine
	void CPrint() {A::Print();}  //rename
};

int main() {
	A *a = new A(); a->Print();
	B *b = new B(); b-> Print(); b->CPrint();
	return 0;
}
*/

class Weapon { // ABSTRACT
public :
	// pure virtual function
	virtual void features()=0;
};

class Gun : public Weapon {
public :
	void features(){
		cout << "Feature of Gun" << endl;
	}
};

class Loader {
public :
	void load(Weapon *w){
		w->features();
	}
};

int main(){
	Loader l;
	Weapon *w;
	Gun g;
	w=&g;
	l.load(w);
	return 0;
}