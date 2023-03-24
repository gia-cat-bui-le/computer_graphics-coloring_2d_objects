#include "plus.h"

Plus::Plus(Point start, Point end) : Shape(start, end)
{
    getInfo();
}

Plus::~Plus() {}

void Plus::draw()
{
    getInfo();
    glBegin(GL_LINE_LOOP);

    for (auto p : vertices)
    {
        glVertex2i(p.x, p.y);
    }

    glEnd();
    glFlush();
}

void Plus::getInfo()
{
    vertices = getVertices();
    radius = getRadius();
}

vector<Point> Plus::getVertices()
{
    vector<Point> v;
    int width = getRadius() * 0.4;
    int height = width << 1;

    // Point 0
    int x = start.x - (width >> 1);
    int y = start.y + height + (width >> 1);
    v.push_back(Point(x, y));

    // Point 1
    x += width;
    v.push_back(Point(x, y));

    // Point 2
    y -= height;
    v.push_back(Point(x, y));

    // Point 3
    x += height;
    v.push_back(Point(x, y));

    // Point 4
    y -= width;
    v.push_back(Point(x, y));

    // Point 5
    x -= height;
    v.push_back(Point(x, y));

    // Point 6
    y -= height;
    v.push_back(Point(x, y));

    // Point 7
    x -= width;
    v.push_back(Point(x, y));

    // Point 8
    y += height;
    v.push_back(Point(x, y));

    // Point 9
    x -= height;
    v.push_back(Point(x, y));

    // Point 10
    y += width;
    v.push_back(Point(x, y));

    // Point 11
    x += height;
    v.push_back(Point(x, y));

    return v;
}

double Plus::getRadius()
{
    return sqrt(double((start.x - end.x) * (start.x - end.x)) + double((start.y - end.y) * (start.y - end.y)));
}