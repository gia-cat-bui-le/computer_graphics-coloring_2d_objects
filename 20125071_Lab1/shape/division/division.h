#ifndef _DIVISION_H_

#define _DIVISION_H_

#include "../rectangle/rectangle.h"
#include "../circle/circle.h"

class Division : public Shape
{
public:
    Division(Point start, Point end);
    ~Division();
    void draw();

private:
    void drawUpperCircle();
    void drawLowerCircle();
    void drawHorizontalLine();

    double getHeight();
    double getWidth();
};

#endif