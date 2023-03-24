#include "polygon.h"

Polygon::Polygon(Point start, Point end, int n) : Shape(start, end), n(n) {}

Polygon::~Polygon() {}

void Polygon::draw()
{
    double angleIncrement = 360.0 / (double)n;
    angleIncrement *= MY_PI / 180.0;
    glBegin(GL_LINE_LOOP);
    float angle = MY_PI / 2.0;
    double s = getSideLength();
    double radius = s / (2.0 * sin((double)angleIncrement / 2.0));
    for (int k = 0; k < n; ++k)
    {
        float x = radius * cos(angle) + (double)start.x;
        float y = radius * sin(angle) + (double)start.y - radius;
        glVertex2f(x, y);
        angle += angleIncrement;
    }
    glEnd();
    glFlush();
}

int Polygon::getSideLength()
{
    return sqrt(double((start.x - end.x) * (start.x - end.x)) + double((start.y - end.y) * (start.y - end.y)));
}