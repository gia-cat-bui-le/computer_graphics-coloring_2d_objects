#ifndef _CIRCLE_H_

#define _CIRCLE_H_

#include <GL/glut.h>
#include <cmath>

#include "../shape.h"

# define MY_PI 3.14159265358979323846

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