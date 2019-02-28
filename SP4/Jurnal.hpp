#ifndef JURNAL_H
#define JURNAL_H

#include "Artikel.hpp"

class Jurnal {
public:
    Jurnal();
    Jurnal(Artikel* d, int s);
    Jurnal(const Jurnal& j);
    ~Jurnal();
    Jurnal& operator= (const Jurnal& a);

    Artikel getData(int idx) const;
    int getSize() const;

    void setData(int idx, const Artikel& a);
    void setSize(int s);

    void print() const;
    void add(const Artikel& a);
    void insert(int idx, const Artikel& a);
    int findByTahun(int t);

private:
    Artikel* data;
    int size;
};

#endif