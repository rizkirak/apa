#include "Matriks.h"
int main(){
    Matriks M;
    Matriks N(2,2);
    Matriks O = M;
    O.SetData(0,0,2);
    M = O; 
}