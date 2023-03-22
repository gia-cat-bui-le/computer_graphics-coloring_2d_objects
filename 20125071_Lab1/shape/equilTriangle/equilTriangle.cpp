#include "equilTriangle.h"

EquilTriangle::EquilTriangle(Point start, Point end) : Shape(start, end) {}

EquilTriangle::~EquilTriangle() {}

void EquilTriangle::draw()
{
    int side = getSideLength();
    Point p;
    if (start.x < end.x) {
        end.x = start.x + (side >> 1);
        p = Point(start.x - (side >> 1), end.y);
    }
    else {
        end.x = start.x - (side >> 1);
        p = Point(start.x + (side >> 1), end.y);
    }

    glBegin(GL_LINE_LOOP);

    glVertex2i(start.x, start.y);
    glVertex2i(end.x, end.y);
    glVertex2i(p.x, p.y);

    glEnd();
    glFlush();
}

int EquilTriangle::getSideLength()
{
    unsigned int h = abs(end.y - start.y);
    int side = (double)(h << 1) / sqrt(3.0);

    return side;
}