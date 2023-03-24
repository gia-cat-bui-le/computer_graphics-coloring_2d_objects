#ifndef _CIRCLE_H_

#define _CIRCLE_H_

#include <GL/glut.h>
#include <cmath>

#include "../shape.h"
#include "../../constant.h"

class Circle : public Shape
{
public:
    Circle(Point start, Point end);
    ~Circle();

    void draw();

private:
    double getRadius();
};

#endif