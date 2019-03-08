#include "Point.h"


#ifndef POINT3D_H
#define POINT3D_H


class Point3D : public Point
{
    public:
        Point3D();
        Point3D(int x, int y, int color);
        Point3D(const Point3D& P);
        ~Point3D();
        Point3D& operator =(const Point3D& rhs);
        int GetColor();
        void SetColor(int color);
        void inverse();
        
        
        
        /*
        int GetAbsis();
        int GetOrdinat();
        void SetOrdinat(int a);
        void inverse();
        static int GetNbPoint();
		*/


        void keluaran();

    //protected:

    private:
        int *c;






};

#endif // POINT_H
