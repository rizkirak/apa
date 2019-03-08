#include "Ayam.hpp"
#include <iostream>
using namespace std;

Ayam::Ayam(char* _nama) :Unggas(_nama) {
    cout << "Ayam bernama " << nama << " menetas! :D" << endl;
}
Ayam::~Ayam(){
    cout << "Ayam bernama " << nama << " mati T.T" << endl;
}
void Ayam::bersuara(){
    cout << nama << ": \"Tok petok petok!\"" << endl;
}