#ifndef _MULTIPLY_H_

#define _MULTIPLY_H_

#include <vector>

#include "../shape.h"

using namespace std;

class Multiply : public Shape
{
public:
    Multiply(Point start, Point end);
    ~Multiply();

    void draw();

private:
    double getRadius();
    vector<Point> getVertices();
};

#endif