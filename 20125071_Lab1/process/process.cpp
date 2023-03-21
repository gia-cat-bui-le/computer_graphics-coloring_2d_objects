#include "process.h"

Process::Process() {}

Process::~Process() {}

void Process::initMenu()
{
    int triangleMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Isosceles Right Triangle", ISOS_RIGHT_TRIANGLE);
    glutAddMenuEntry("Equilateral Triangle", EQUILATERAL_TRIANGLE);

    int quadrilateralMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Rectangle", RECTANGLE);
    glutAddMenuEntry("Square", SQUARE);

    int ovalMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Circle", CIRCLE);
    glutAddMenuEntry("Ellipse", ELLIPSE);

    int polygonMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Pentagon", PENTAGON);
    glutAddMenuEntry("Hexagon", HEXAGON);

    int otherShapeMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Arrow", ARROW);
    glutAddMenuEntry("Star", STAR);

    int signMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Plus Sign", PLUS_SIGN);
    glutAddMenuEntry("Minus Sign", MINUS_SIGN);
    glutAddMenuEntry("Multiplication Sign", MULTIPLICATION_SIGN);
    glutAddMenuEntry("Divide Sign", DIVIDE_SIGN);

    int colorMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Red", COLOR_RED);
    glutAddMenuEntry("Green", COLOR_GREEN);
    glutAddMenuEntry("Blue", COLOR_BLUE);

    int menuIdMenu = glutCreateMenu(processMenuEvent);
    glutAddMenuEntry("Line", LINE);
    glutAddSubMenu("Triangle", triangleMenu);
    glutAddSubMenu("Quadrilateral", quadrilateralMenu);
    glutAddSubMenu("Oval", ovalMenu);
    glutAddSubMenu("Polygon", polygonMenu);
    glutAddSubMenu("Other Shape", otherShapeMenu);
    glutAddSubMenu("Sign", signMenu);
    glutAddSubMenu("Choose color", colorMenu);

    glutAddMenuEntry("Quit", -1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Process::processMenuEvent(int value)
{
    glutPostRedisplay();
}

void Process::boundaryFill(int x, int y, RGBColor fillColor, RGBColor boundaryColor)
{
    RGBColor currentColor = getPixel(x, y);
    if (currentColor == fillColor || currentColor == boundaryColor)
    {
        return;
    }
    putPixel(x, y, fillColor);
    boundaryFill(x - 1, y, fillColor, boundaryColor);
    boundaryFill(x, y + 1, fillColor, boundaryColor);
    boundaryFill(x + 1, y, fillColor, boundaryColor);
    boundaryFill(x, y - 1, fillColor, boundaryColor);
}

void Process::processMouseEvent(int button, int state, int x, int y)
{
}