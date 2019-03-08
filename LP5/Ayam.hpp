#ifndef AYAM_HPP
#define AYAM_HPP
#include "Unggas.hpp"
class Ayam : public Unggas{
    public:
        Ayam(char* _nama);
        virtual ~Ayam();
        virtual void bersuara();
};


#endif 