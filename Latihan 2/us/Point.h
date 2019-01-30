#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int x, int y);
        Point(const Point &p);
        ~Point();

        //getter dan setter
        int GetAbsis();
        int GetOrdinat();
        void SetOrdinat(int Y);

        void inverse();

        int GetNbPoint();

        void keluaran();


    private:
        int *Data;
        int NbPoint;





};

#endif // POINT_H
