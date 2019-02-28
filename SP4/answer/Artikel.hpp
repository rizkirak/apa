#ifndef ARTIKEL_H
#define ARTIKEL_H
#define DEFSIZE 256


class Artikel {
public:
    Artikel();
    Artikel(char* j, char* p, int t);
    Artikel(const Artikel& a);
    ~Artikel();
    Artikel& operator= (const Artikel& a);
    char* getJudul() const;
    char* getPenulis() const;
    int getTahun() const;

    void setJudul(char* j);
    void setPenulis(char* p);
    void setTahun(int t);

    void print() const;

private:
    char* judul;
    char* penulis;
    int tahun;
};

#endif