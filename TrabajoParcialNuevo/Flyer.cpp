#include "pch.h"
#include "Flyer.h"

Flyer::Flyer() {
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	height = 0;
	witdh = 0;
	type = 1;
	speed = 1;
	lives = 1;
}

Flyer::Flyer(float x, float y, char dir)
{
	
	this->direccion = dir;

	switch (direccion)
	{
	case 'W':
		type = 1;
		this->x = x + 1;
		this->y = y - 1;
		break;
	case 'S':
		type = 1;
		this->x = x + 2;
		this->y = y + 3;
		break;
	case 'A':
		type = 2;
		this->x = x - 1;
		this->y = y + 1;
		break;
	case 'D':
		type = 2;
		this->x = x + 4;
		this->y = y + 2;
		break;
	}

	dx = 0;
	dy = 0;
	speed = 1;
	lives = 1;
}

Flyer::~Flyer() {}

void Flyer::move() {
	if (direccion == 'W' || direccion == 'S')
	{
		type = 1;
		dx = 0;
		dy = (direccion == 'W') ? -1 : 1;
	}
	else if (direccion == 'A' || direccion == 'D')
	{
		type = 2;
		dy = 0;
		dx = (direccion == 'A') ? -1 : 1;
	}

	x += dx * speed;
	y += dy * speed;
}

void Flyer::draw() {
	if (type == 1) //arriba - abajo
	{
		height = 2;
		witdh = 1;
	}
	else if (type == 2) //derecha - izquierda
	{
		height = 1;
		witdh = 2;
	}

	int rep = 1;
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			if (rep == 1) colorEntity(250, 250, 250);
			else colorEntity(123, 123, 123);
			cursorEntity(x + c, y + f);
			cout << char(145);
			rep++;
		}
	}
}

char Flyer::getDireccion() { return direccion; }
void Flyer::setDireccion(char direccion) { this->direccion = direccion; }