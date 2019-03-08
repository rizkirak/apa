#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int x, int y);
        Point(const Point& P);
        virtual ~Point();
        Point& operator =(const Point& rhs);
        int GetAbsis();
        int GetOrdinat();
        void SetOrdinat(int a);
        virtual void inverse();
        static int GetNbPoint();



        virtual void keluaran();

    //protected:

    protected:
        int *Data;
        static int NbPoint;






};

#endif // POINT_H
