#ifndef _RECTANGLE_H_

#define _RECTANGLE_H_
#include <GL/glut.h>

#include "../shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(Point start, Point end);
    ~Rectangle();

    void draw();
};

#endif