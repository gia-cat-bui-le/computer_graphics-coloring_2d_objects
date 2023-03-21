#ifndef _SQUARE_H_

#define _SQUARE_H_

#include <GL/glut.h>

#include "../shape.h"

class Square : public Shape
{
public:
    Square(Point start, Point end);
    ~Square();

    void draw();
};

#endif