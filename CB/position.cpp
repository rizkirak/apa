#include "position.h"
#include <iostream>

using namespace std;

position::position()
{
    //ctor

    X=0;
    Y=0;

}

position::position(int x,int y)
{
    //ctor
    X=x;
    Y=y;
}

void position::print()
{
    //ctor
    cout<<X<<','<<Y<<endl;
}

