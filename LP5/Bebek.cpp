#include "Bebek.hpp"
#include <iostream>
using namespace std;

Bebek::Bebek(char* _nama) :Unggas(_nama) {
    cout << "Bebek bernama " << nama << " menetas! :D" << endl;
}
Bebek::~Bebek(){
    cout << "Bebek bernama " << nama << " mati T.T" << endl;
}
void Bebek::bersuara(){
    cout << nama << ": \"Kwek kwek!\"" << endl;
}