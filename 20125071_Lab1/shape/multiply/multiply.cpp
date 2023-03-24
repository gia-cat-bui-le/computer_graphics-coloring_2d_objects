#include "multiply.h"

Multiply::Multiply(Point start, Point end) : Shape(start, end) {}

Multiply::~Multiply() {}

double Multiply::getRadius() {
    return sqrt(double((start.x - end.x) * (start.x - end.x)) + double((start.y - end.y) * (start.y - end.y)));
}

vector<Point> Multiply::getVertices()
{
    int w = getRadius() / 3.0;
    int h = w << 1;

    vector<Point> v;

    // Point 0
    int x = start.x;
    int y = start.y + w;
    v.push_back(Point(x, y));

    // Point 1
    x += h;
    y += h;
    v.push_back(Point(x, y));

    // Point 2
    x += w;
    y -= w;
    v.push_back(Point(x, y));

    // Point 3
    x -= h;
    y -= h;
    v.push_back(Point(x, y));

    // Point 4
    x += h;
    y -= h;
    v.push_back(Point(x, y));

    // Point 5
    x -= w;
    y -= w;
    v.push_back(Point(x, y));

    // Point 6
    x -= h;
    y += h;
    v.push_back(Point(x, y));

    // Point 7
    x -= h;
    y -= h;
    v.push_back(Point(x, y));

    // Point 8
    x -= w;
    y += w;
    v.push_back(Point(x, y));

    // Point 9
    x += h;
    y += h;
    v.push_back(Point(x, y));

    // Point 10
    x -= h;
    y += h;
    v.push_back(Point(x, y));

    // Point 11
    x += w;
    y += w;
    v.push_back(Point(x, y));

    return v;
}

void Multiply::draw()
{
    vector<Point> vertices = getVertices();
    glBegin(GL_LINE_LOOP);

    for (auto p : vertices) {
        glVertex2i(p.x, p.y);
    }

    glEnd();
    glFlush();
}