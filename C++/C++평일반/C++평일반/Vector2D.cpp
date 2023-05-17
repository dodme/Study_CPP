#include "Vector2D.h"

void Vector2D::SetVector(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2D::PrintVector()
{
	cout << "(" << x << " ," << y << ")" << endl;
}

double Vector2D::Distance(Vector2D pos1, Vector2D pos2)
{
	return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}