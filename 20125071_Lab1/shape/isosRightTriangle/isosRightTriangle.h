#ifndef _ISOS_RIGHT_TRIANGLE_

#define _ISOS_RIGHT_TRIANGLE_

#include <GL/glut.h>

#include "../shape.h"

class IsosRightTriangle : public Shape
{
public:
    IsosRightTriangle(Point start, Point end);
    ~IsosRightTriangle();

    void draw();
};

#endif