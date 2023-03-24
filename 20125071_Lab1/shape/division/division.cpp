#include "division.h"

Division::Division(Point start, Point end) : Shape(start, end) {}

Division::~Division() {}

void Division::drawUpperCircle()
{
    int r = getHeight();
    Point center = start;
    Point otherPoint = start;
    center.y += r << 1;
    otherPoint.y += r + (r >> 1);
    Circle c(center, otherPoint);
    c.draw();
}

void Division::drawLowerCircle()
{

    int r = getHeight();
    Point center = start;
    Point otherPoint = start;
    center.y -= r << 1;
    otherPoint.y -= r + (r >> 1);
    Circle c(center, otherPoint);
    c.draw();
}

void Division::drawHorizontalLine()
{
    int h = getHeight();
    int w = getWidth();
    Point upperLeft = start;
    upperLeft.x -= w >> 1;
    upperLeft.y += h >> 1;

    Point bottomRight(upperLeft.x + w, upperLeft.y - h);
    Rectangle r(upperLeft, bottomRight);
    r.draw();
}

double Division::getHeight()
{
    return abs(start.y - end.y) << 1;
}

double Division::getWidth()
{
    return abs(start.x - end.x) << 1;
}

void Division::draw()
{
    drawUpperCircle();
    drawHorizontalLine();
    drawLowerCircle();
}