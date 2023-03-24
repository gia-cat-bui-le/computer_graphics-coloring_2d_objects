#ifndef _PLUS_H_

#define _PLUS_H_

#include "../shape.h"
#include <vector>

using namespace std;

class Plus : public Shape
{
public:
    Plus(Point start, Point end);
    ~Plus();

    void draw();

private:
    vector<Point> vertices;
    double radius;

    void getInfo();
    vector<Point> getVertices();
    double getRadius();
};

#endif