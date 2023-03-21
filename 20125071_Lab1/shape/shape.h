#ifndef _SHAPE_H_

#define _SHAPE_H_
#include <GL/glut.h>

class Point
{
public:
    int x, y;
    Point(int x, int y);
    Point(const Point &other);
    ~Point();
    Point& operator=(const Point &other);
};

class Shape
{
public:
    Shape(Point start, Point end);
    ~Shape();
    virtual void draw() = 0;
    void updateEnd(Point newEnd);

protected:
    Point start, end;
};

#endif _SHAPE_H_