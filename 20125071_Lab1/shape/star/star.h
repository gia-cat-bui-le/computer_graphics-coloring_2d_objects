#ifndef _STAR_H_

#define _STAR_H_

#include <cmath>

#include "../shape.h"
#include "../../constant.h"

class Star : public Shape
{
public:
    Star(Point start, Point end);
    ~Star();

    void draw();

private:
    double length;
    double radius;
    const double ANGLE_INCREMENT = MY_PI * 0.2;

    double getLength();
    double getRadius();

    void updateEnd(Point newEnd);
};

#endif