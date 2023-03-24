#ifndef _MINUS_H_

#define _MINUS_H_

#include "../rectangle/rectangle.h"

class Minus : public Rectangle
{
private:
public:
    Minus(Point start, Point end);
    ~Minus();
};

#endif