#ifndef _EQUIL_TRIANGLE_H_

#define _EQUIL_TRIANGLE_H_

#include <GL/glut.h>
#include <cmath>

#include "../shape.h"

class EquilTriangle : public Shape
{
public:
    EquilTriangle(Point start, Point end);
    ~EquilTriangle();

    void draw();

private:
    int getSideLength();
};

#endif