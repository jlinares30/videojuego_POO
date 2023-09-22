#include "pch.h"
#include "Ally.h"

Ally::Ally()
{

}

Ally::Ally(float x, float y, char dir) {
	this->x = x;
	this->y = y;
	this->dir = dir;
	if (dir == 'W')//arriba
	{
		dx = 0;
		dy = -1;
	}
	else if (dir == 'S')//abajo
	{
		dx = 0;
		dy = 1;
	}
	else if (dir == 'A')//izquierda
	{
		dx = -1;
		dy = 0;
	}
	else if (dir == 'D')//derecha
	{
		dx = 1;
		dy = 0;
	}

	speed = 1;
	height = 3;
	witdh = 3;
	lives = 1;
}

Ally::~Ally() {}

char Ally::getDir() {
	return dir;
}
void Ally::setDir(char dir) {
	this->dir = dir;
}
void Ally::move() {
	switch (dir)
	{
	case 'W'://arriba
		dx = 0;
		dy = -1;
		break;

	case 'S'://abajo
		dx = 0;
		dy = 1;
		break;

	case 'A'://izquierda
		dx = -1;
		dy = 0;
		break;

	case 'D'://derecha
		dx = 1;
		dy = 0;
		break;
	}

	x += dx * speed;
	y += dy * speed;
}

void Ally::draw() {
	colorEntity(154, 246, 193);
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			cursorEntity(x + c, y + f);
			switch (dir)
			{
			case 'D': //derecha
				cout << figureA[f][c];
				break;
			case 'A': //izquierda
				cout << figureB[f][c];
				break;
			case 'W': //arriba
				cout << figureC[f][c];
				break;
			case 'S': //abajo
				cout << figureC[f][c];
				break;
			}
		}
	}
}
