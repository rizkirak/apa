#ifndef BEBEK_HPP
#define BEBEK_HPP
#include "Unggas.hpp"
class Bebek : public Unggas{
    public:
        Bebek(char* _nama);
        ~Bebek();
        void bersuara();
};


#endif 