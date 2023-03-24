#ifndef _PROCESS_H_

#define _PROCESS_H_

#include <GL/glut.h>
#include <iostream>

#include "../RGBColor/rgbColor.h"
#include "../shape/shape.h"

#include "../shape/line/line.h"

#include "../shape/rectangle/rectangle.h"
#include "../shape/square/square.h"

#include "../shape/isosRightTriangle/isosRightTriangle.h"
#include "../shape/equilTriangle/equilTriangle.h"

#include "../shape/circle/circle.h"
#include "../shape/ellipse/ellipse.h"

#include "../shape/polygon/pentagon/pentagon.h"
#include "../shape/polygon/hexagon/hexagon.h"

#include "../shape/arrow/arrow.h"
#include "../shape/star/star.h"

#include "../shape/plus/plus.h"
#include "../shape/minus/minus.h"
#include "../shape/multiply/multiply.h"
#include "../shape/division/division.h"

using namespace std;

class Process
{
public:
    static bool isDrawing;
    static bool isColoring;
    static bool chooseShape;
    static bool chooseColor;
    static Shape *currentShape;
    static bool chooseStart;
    static RGBColor currentColor;
    static bool isClear;
    static bool rerenderScene;
    static Point start, end;
    static bool isClean;
    static int shape;

    static void initMenu();
    static void processMenuEvent(int value);
    static void boundaryFill(int x, int y, RGBColor fillColor, RGBColor boundaryColor);
    static void processMouseEvent(int button, int state, int x, int y);
    static void renderScene();

    Process();
    ~Process();

private:
};

#endif