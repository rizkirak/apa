#ifndef UNGGAS_HPP
#define UNGGAS_HPP
class Unggas{
    public:
        Unggas(char* _nama);
        Unggas(const Unggas& U);
        Unggas& operator=(const Unggas& U);
        virtual ~Unggas();
        virtual void bersuara() = 0;
    protected:
        char* nama;
};


#endif 