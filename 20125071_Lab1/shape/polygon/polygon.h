#ifndef _POLYGON_H_

#define _POLYGON_H_

#include <cmath>

#include "../shape.h"
#include "../../constant.h"

class Polygon : public Shape
{
public:
    Polygon(Point start, Point end, int n);
    ~Polygon();

    void draw();

private:
    int n;

    int getSideLength();
};

#endif