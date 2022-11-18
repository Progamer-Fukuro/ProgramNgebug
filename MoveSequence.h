#ifndef MOVE_SEQUENCE
#define MOVE_SEQUENCE

#include <vector>
#include "Matrix1D.h"

class Point2D
{
    public:
        int x;
        int y;

        Point2D(){}
        Point2D(int x_, int y_) : x(x_), y(y_) {}

        Point2D operator+(const Point2D& obj) {return Point2D(x + obj.x, y + obj.y);}
        Point2D operator-(const Point2D& obj) {return Point2D(x - obj.x, y - obj.y);}
        Point2D operator*(const Point2D& obj) {return Point2D(x * obj.x, y - obj.y);}
};

class MoveSequence : public Matrix1D<Point2D>
{
    public:
        MoveSequence(){}
        MoveSequence(int ln_) {Matrix1D::resize(ln_);}

        int getLength();
        void stepForward();

        MoveSequence operator+(const MoveSequence&);
        MoveSequence operator-(const MoveSequence&);
};

#endif //MOVE_SEQUENCE