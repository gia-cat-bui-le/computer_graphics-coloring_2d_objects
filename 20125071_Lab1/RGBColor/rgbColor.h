#ifndef _RGBCOLOR_H_
#define _RGBCOLOR_H_

#include <GL/glut.h>

#include "../constant.h"

struct RGBColor
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    bool operator==(RGBColor &other);
};

const RGBColor RED = { 255, 0, 0 };
const RGBColor GREEN = { 0, 255, 0 };
const RGBColor BLUE = { 0, 0, 255 };
const RGBColor BLACK = { 0, 0, 0 };
const RGBColor WHITE = { 255, 255, 255 };

RGBColor getPixel(int x, int y);
void putPixel(int x, int y, RGBColor color);

#endif