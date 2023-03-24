#include "process.h"

Process::Process() {}

Process::~Process()
{
    if (currentShape)
    {
        delete currentShape;
    }
}

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
    switch (value)
    {
    case -1:
        cout << "Quit Program\n";
        exit(0);

    case COLOR_RED:
        chooseColor = 1;
        currentColor = RED;
        break;

    case COLOR_GREEN:
        chooseColor = 1;
        currentColor = GREEN;
        break;

    case COLOR_BLUE:
        chooseColor = 1;
        currentColor = BLUE;
        break;

    default:
        shape = value;
        chooseShape = 1;
        chooseStart = 1;
        rerenderScene = 1;
        isClean = 1;
        glutPostRedisplay();
        break;
    }
}

void Process::boundaryFill(int x, int y, RGBColor fillColor, RGBColor boundaryColor)
{
    if (x < 0 || MAX_X < x || y < 0 || MAX_Y < y)
    {
        return;
    }

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
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            rerenderScene = 1;
            if (chooseColor)
            {
                start = Point(x, y);
                chooseColor = 0;
                isColoring = 1;
            }
            else if (chooseShape)
            {
                isClean = 1;
                if (chooseStart)
                {
                    start = Point(x, MAX_Y - y);
                    chooseStart = 0;
                }
                else
                {
                    end = Point(x, MAX_Y - y);
                    if (currentShape)
                    {
                        delete currentShape;
                    }
                    switch (shape)
                    {
                    case LINE:
                        currentShape = new Line(start, end);
                        break;

                    case ISOS_RIGHT_TRIANGLE:
                        currentShape = new IsosRightTriangle(start, end);
                        break;

                    case EQUILATERAL_TRIANGLE:
                        currentShape = new EquilTriangle(start, end);
                        break;

                    case RECTANGLE:
                        currentShape = new Rectangle(start, end);
                        break;

                    case SQUARE:
                        currentShape = new Square(start, end);
                        break;

                    case CIRCLE:
                        currentShape = new Circle(start, end);
                        break;

                    case ELLIPSE:
                        currentShape = new Ellipse(start, end);
                        break;

                    case PENTAGON:
                        currentShape = new Pentagon(start, end);
                        break;

                    case HEXAGON:
                        currentShape = new Hexagon(start, end);
                        break;

                    case ARROW:
                        currentShape = new Arrow(start, end);
                        break;

                    case STAR:
                        currentShape = new Star(start, end);
                        break;

                    case PLUS_SIGN:
                        currentShape = new Plus(start, end);
                        break;

                    case MINUS_SIGN:
                        currentShape = new Minus(start, end);
                        break;

                    case MULTIPLICATION_SIGN:
                        currentShape = new Multiply(start, end);
                        break;

                    case DIVIDE_SIGN:
                        currentShape = new Division(start, end);
                        break;

                    default:
                        break;
                    }
                    chooseShape = 0;
                    isDrawing = 1;
                }
            }
        }
        glutPostRedisplay();
    }
}

void Process::renderScene()
{
    if (rerenderScene)
    {
        if (isClean)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            isClean = 0;
        }
        if (isDrawing && Process::currentShape)
        {
            currentShape->draw();
            isDrawing = 0;
        }
        if (isColoring)
        {
            boundaryFill(start.x, start.y, currentColor, WHITE);
            isColoring = 0;
        }
        glFlush();
    }
    rerenderScene = 0;
}