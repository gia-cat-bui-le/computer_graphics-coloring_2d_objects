#include "square.h"

Square::Square(Point start, Point end) : Shape(start, end) {}

Square::~Square() {}

void Square::draw()
{
	end.y = start.y + end.x - start.x;
	glBegin(GL_LINE_LOOP);

	glVertex2i(start.x, start.y);
	glVertex2i(end.x, start.y);
	glVertex2i(end.x, end.y);
	glVertex2i(start.x, end.y);

	glEnd();
	glFlush();
}