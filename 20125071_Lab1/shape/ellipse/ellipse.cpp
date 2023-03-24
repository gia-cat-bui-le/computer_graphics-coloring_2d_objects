#include "ellipse.h"

Ellipse::Ellipse(Point start, Point end) : Shape(start, end) {}

Ellipse::~Ellipse() {}

void Ellipse::draw()
{
    int a = getMajorLength() >> 1;
    int b = getMinorLength() >> 1;

    int numSegment = 360;
    float theta = 2 * MY_PI / (float)numSegment;
    float c = cosf(theta);
    float s = sinf(theta);

    float t;

    float x = 1;
    float y = 0;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < numSegment; ++i)
    {
        glVertex2f((float)x * a / 2.0 + start.x, (float)y * b / 2.0 + start.y);
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }

    glEnd();
    glFlush();
}

int Ellipse::getMajorLength()
{
    return abs(start.x - end.x) << 1;
}

int Ellipse::getMinorLength()
{
    return abs(start.y - end.y) << 1;
}