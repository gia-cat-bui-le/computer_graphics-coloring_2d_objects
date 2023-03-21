#ifndef _PROCESS_H_

#define _PROCESS_H_

#include <GL/glut.h>

#include "../RGBColor/rgbColor.h"
#include "../shape/shape.h"

class Process
{
public:
    static bool isDrawing;
    static bool isColoring;
    static Shape* currentShape;
    static RGBColor currentColor;

    static void initMenu();
    static void processMenuEvent(int value);
    static void boundaryFill(int x, int y, RGBColor fillColor, RGBColor boundaryColor);
    static void processMouseEvent(int button, int state, int x, int y);

    Process();
    ~Process();
};

#endif