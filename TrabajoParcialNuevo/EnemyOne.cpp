#include "pch.h"
#include "EnemyOne.h"

EnemyOne::EnemyOne() {

}
EnemyOne::EnemyOne(float x, float y, char dir){
	this->x = x;
	this->y = y;
	this->dir = dir;
	if (dir == 'W')//arriba
	{
		dx = 0;
		dy = -1;
		type = 3;
	}
	else if (dir == 'S')//abajo
	{
		dx = 0;
		dy = 1;
		type = 2;
	}
	else if (dir == 'A')//izquierda
	{
		dx = -1;
		dy = 0;
		type = 1;
	}
	else if (dir == 'D')//derecha
	{
		dx = 1;
		dy = 0;
		type = 0;
	}

	speed = 0.5;
	height = 3;
	witdh = 3;
	lives = 1;

}
EnemyOne::~EnemyOne(){}

char EnemyOne::getDir() { return dir; }
void EnemyOne::setDir(char dir) { this->dir = dir; }

void EnemyOne::move() {
	
	switch (dir)
	{
	case 'W'://arriba
		dx = 0;
		dy = -1;
		type = 3;
		break;

	case 'S'://abajo
		dx = 0;
		dy = 1; 
		type = 2;
		break;

	case 'A'://izquierda
		dx = -1;
		dy = 0;
		type = 1;
		break;

	case 'D'://derecha
		dx = 1;
		dy = 0;
		type = 0;
		break;
	}

	x += dx * speed;
	y += dy * speed;
}
void EnemyOne::draw() {
	
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			cursorEntity(x + c, y + f);
			if (speed < 1) //sin velocidad aumentada
			{
				switch (figure[type][f][c])
				{
				case ' ': colorEntity(12, 12, 12);	break;
					case char(220) : colorEntity(236, 109, 15);	break;
						case char(92) : colorEntity(255, 191, 143);	break;
						case '/': colorEntity(255, 191, 143); break;
						case '#': colorEntity(76, 97, 241);	break;
						case '<': colorEntity(255, 191, 143); break;
						case '>': colorEntity(255, 191, 143); break;
				}
			}
			else //con velocidad aumentada
			{
				colorEntity(236, 64, 53);
			}
			cout << figure[type][f][c];
		}
	}
}