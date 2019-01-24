#include <iostream>
using namespace std;

template <typename T> T Max(T a, T b){ return (a>b)?a:b; }

int main(){
	float a=2.1,b=1.9;
	cout << Max(a,b) << endl;
	return 0;
}