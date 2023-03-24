#ifndef _ELLIPSE_H_

#define _ELLIPSE_H_

#include <GL/glut.h>
#include <cmath>

#include "../shape.h"
#include "../../constant.h"

class Ellipse : public Shape
{
public:
    Ellipse(Point start, Point end);
    ~Ellipse();

    void draw();

private:
    int getMinorLength();
    int getMajorLength();
};

#endif