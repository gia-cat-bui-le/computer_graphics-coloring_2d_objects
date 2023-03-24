#include "rgbColor.h"

bool RGBColor::operator==(RGBColor &other)
{
    return (r == other.r && g == other.g && b == other.b);
}

RGBColor getPixel(int x, int y) {
    unsigned char* ptr = new unsigned char[3];
    glReadPixels(x, MAX_Y - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
    RGBColor color = { ptr[0], ptr[1], ptr[2] };

    delete[] ptr;

    return color;
}

void putPixel(int x, int y, RGBColor color) {
    unsigned char* ptr = new unsigned char[3];
    ptr[0] = color.r, ptr[1] = color.g, ptr[2] = color.b;

    glRasterPos2i(x, MAX_Y - y);
    glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
    glFlush();

    delete[] ptr;
}