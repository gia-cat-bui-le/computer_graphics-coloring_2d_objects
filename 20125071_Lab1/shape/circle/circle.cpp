#include "circle.h"

Circle::Circle(Point start, Point end) : Shape(start, end) {}

Circle::~Circle() {}

void Circle::draw()
{
    int numSegment = 360;
    float theta = MY_PI * 2 / (float)numSegment;
    float tangentialFactor = tanf(theta);

    float radialFactor = cosf(theta);

    float x = getRadius();
    float y = 0;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < numSegment; ++i)
    {
        glVertex2f(x + start.x, y + start.y);

        float tx = -y;
        float ty = x;

        x += tx * tangentialFactor;
        y += ty * tangentialFactor;

        x *= radialFactor;
        y *= radialFactor;
    }

    glEnd();

    glFlush();
}

double Circle::getRadius()
{
    return sqrt(double((start.x - end.x) * (start.x - end.x)) + double((start.y - end.y) * (start.y - end.y)));
}