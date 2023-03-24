#include "main.h"

int MAX_X;
int MAX_Y;

Shape* Process::currentShape = 0;
bool Process::isDrawing = 0;
bool Process::isColoring = 0;
bool Process::chooseShape = 0;
RGBColor Process::currentColor = BLACK;
bool Process::rerenderScene = 1;
bool Process::isClean = 1;
Point Process::start;
Point Process::end;
int Process::shape = 0;
bool Process::chooseColor = 0;
bool Process::chooseStart = 0;

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(MIN_X, w, MIN_Y, h);
	MAX_X = w;
	MAX_Y = h;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Coloring 2D Object");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Process::renderScene);
	glutReshapeFunc(reshape);
	glutMouseFunc(Process::processMouseEvent);

	Process::initMenu();

	glutMainLoop();

	return 1;
}