#ifndef _HEXAGON_H_

#define _HEXAGON_H_

#include "../polygon.h"

class Hexagon : public Polygon
{
public:
    Hexagon(Point start, Point end);
    ~Hexagon();
};

#endif