#include "shape.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point& Point::operator=(const Point &other)
{
    x = other.x;
    y = other.y;

    return *this;
}

Shape::Shape(Point start, Point end) : start(start), end(end) {}

Shape::~Shape() {}

void Shape::updateEnd(Point newEnd)
{
    end = newEnd;
}