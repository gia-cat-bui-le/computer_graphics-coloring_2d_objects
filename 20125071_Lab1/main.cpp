#include "main.h"

int MAX_X;
int MAX_Y;

Shape* Process::currentShape = 0;

void renderWindow(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (!Process::currentShape)
	{
		Process::currentShape = new IsosRightTriangle(Point(100, 100), Point(500, 300));
	}
	if (Process::currentShape)
	{
		Process::currentShape->draw();
	}
	delete Process::currentShape;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(MIN_X, w, MIN_Y, h);
	MAX_X = w;
	MAX_Y = h;
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Coloring 2D Object");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(renderWindow);
	glutReshapeFunc(reshape);

	Process::initMenu();

	glutMainLoop();

	return 1;
}