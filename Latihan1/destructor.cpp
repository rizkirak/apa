#include <iostream>
using namespace std;
 
class A {
public :
    A ( int i ) : i ( i ) {} 
    ~A(){
        cout << "~a" << i << endl;
    }
private :
    int i;
};
 
int main()
{
    A a1(1);
    A* p;
 
    { // nested scope
        A a2(2);
        p = new A(3);
    } // a2 out of scope
 
    delete p; // calls the destructor of a3
}