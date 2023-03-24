#include "star.h"

Star::Star(Point start, Point end) : Shape(start, end)
{
    length = getLength();
    radius = getRadius();
}

Star::~Star() {}

double Star::getLength()
{
    return sqrt(double(start.x - end.x) * (start.x - end.x) + double((start.y - end.y) * (start.y - end.y)));
}

double Star::getRadius()
{
    return getLength() / (2.0 * sin(ANGLE_INCREMENT / 2.0));
}

void Star::updateEnd(Point newEnd)
{
    Shape::updateEnd(newEnd);
    length = getLength();
    radius = getRadius();
}

void Star::draw()
{
    glBegin(GL_LINE_LOOP);

    float angle = MY_PI / 2.0;

    for (int k = 0; k < 10; ++k) {
        float tempRadius = radius;
        float x, y;
        if (k & 1) {
            tempRadius /= 2.0;
            x = tempRadius * cos(angle) + (float)start.x;
            y = tempRadius * sin(angle) + (double)start.y - radius;
        }
        else {
            x = tempRadius * cos(angle) + (double)start.x;
            y = tempRadius * sin(angle) + (double)start.y - radius;
        }
        glVertex2f(x, y);
        angle += ANGLE_INCREMENT;
    }

    glEnd();
    glFlush();
}