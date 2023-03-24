#ifndef _LINE_H_

#define _LINE_H_

#include "../shape.h"

class Line : public Shape
{
public:
    Line(Point start, Point end);
    ~Line();

    void draw();
};

#endif