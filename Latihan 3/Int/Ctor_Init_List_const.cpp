#include<iostream>
using namespace std;

class Base
{
    private:
    const int c_var;
    public:
    Base(int c_var):c_var(c_var)
    {
        cout << "Value is " << c_var;
    }
};

int main()
{
    Base il(10);
}
