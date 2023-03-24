#ifndef _PENTAGON_H_

#define _PENTAGON_H_

#include "../polygon.h"

class Pentagon : public Polygon
{
public:
    Pentagon(Point start, Point end);
    ~Pentagon();
};

#endif