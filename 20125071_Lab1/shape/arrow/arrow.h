#ifndef _ARROW_H_

#define _ARROW_H_

#include <cmath>

#include "../shape.h"

class Arrow : public Shape
{
private:
public:
    Arrow(Point start, Point end);
    ~Arrow();

    void draw();

private:
    Point rectPoint1, rectPoint2, rectPoint3;
    Point trianglePoint1, trianglePoint2;

    int getLength();
    int getWidth();

    void updateEnd(Point newEnd);
    void updateOtherPoints();
};

#endif