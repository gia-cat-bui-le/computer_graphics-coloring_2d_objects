#include "rectangle.h"

Rectangle::Rectangle(Point start, Point end) : Shape(start, end) {}

Rectangle::~Rectangle() {}

void Rectangle::draw()
{
	glBegin(GL_LINE_LOOP);

	glVertex2i(start.x, start.y);
	glVertex2i(end.x, start.y);
	glVertex2i(end.x, end.y);
	glVertex2i(start.x, end.y);

	glEnd();
	glFlush();
}