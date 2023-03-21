#include "isosRightTriangle.h"

IsosRightTriangle::IsosRightTriangle(Point start, Point end) : Shape(start, end) {}

IsosRightTriangle::~IsosRightTriangle() {}

void IsosRightTriangle::draw()
{
    end.y = start.y + end.x - start.x;
    Point p((start.x << 1) - end.x, end.y);
    glBegin(GL_LINE_LOOP);

    glVertex2i(start.x, start.y);
    glVertex2i(end.x, end.y);
    glVertex2i(p.x, p.y);

    glEnd();
    glFlush();
}