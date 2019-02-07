#include <iostream>
using namespace std;

int main(){
	int i=1;
	int& r1=i;
	int&& r2=r1;
	r2++;
	cout << r1 << endl;
	return 0;
}