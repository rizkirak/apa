#include "AyamJago.hpp"
#include <iostream>
using namespace std;

AyamJago::AyamJago(char* _nama) :Ayam(_nama) {
    cout << "AyamJago bernama " << nama << " menetas! :D" << endl;
}
AyamJago::~AyamJago(){
    cout << "AyamJago bernama " << nama << " mati T.T" << endl;
}
void AyamJago::bersuara(){
    cout << nama << ": \"Kukuruyuk!!\"" << endl;
}