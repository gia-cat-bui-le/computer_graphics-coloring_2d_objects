#include "line.h"

Line::Line(Point start, Point end) : Shape(start, end) {}

Line::~Line() {}

void Line::draw()
{
	glBegin(GL_LINES);

	glVertex2i(start.x, start.y);
	glVertex2i(end.x, end.y);

	glEnd();
	glFlush();
}