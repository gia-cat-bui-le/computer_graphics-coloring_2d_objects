#include "arrow.h"

Arrow::Arrow(Point start, Point end) : Shape(start, end) {
    updateOtherPoints();
}

Arrow::~Arrow() {}

void Arrow::draw()
{
    glBegin(GL_LINE_LOOP);

    glVertex2i(start.x, start.y);
    glVertex2i(rectPoint1.x, rectPoint1.y);
    glVertex2i(trianglePoint1.x, trianglePoint1.y);
    glVertex2i(end.x, end.y);
    glVertex2i(trianglePoint2.x, trianglePoint2.y);
    glVertex2i(rectPoint2.x, rectPoint2.y);
    glVertex2i(rectPoint3.x, rectPoint3.y);

    glEnd();
    glFlush();
}

int Arrow::getLength()
{
    return abs(start.x - end.x);
}

int Arrow::getWidth()
{
    return abs(start.y - end.y);
}

void Arrow::updateEnd(Point newEnd)
{
    Shape::updateEnd(newEnd);
    updateOtherPoints();
}

void Arrow::updateOtherPoints() {

    int length = getLength();
    int width = getWidth();

    rectPoint1 = rectPoint2 = rectPoint3 = start;
    if (start.x < end.x)
    {
        rectPoint1.x += (length << 1) / 3;
    }
    else
    {
        rectPoint1.x -= (length << 1) / 3;
    }
    rectPoint2 = trianglePoint1 = rectPoint1;

    if (start.y < end.y)
    {
        rectPoint2.y = rectPoint3.y += (width << 1);
        trianglePoint1.y -= width;
        trianglePoint2 = rectPoint2;
        trianglePoint2.y += width;
    }
    else
    {
        rectPoint2.y = rectPoint3.y -= (width << 1);
        trianglePoint1.y += width;
        trianglePoint2 = rectPoint2;
        trianglePoint2.y -= width;
    }
}