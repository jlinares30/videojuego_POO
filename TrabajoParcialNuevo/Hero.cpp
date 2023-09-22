#include "pch.h"
#include "Hero.h"

Hero::Hero() {
	x = 4;
	y = 4;
	dx = 0;
	dy = 0;
	speed = 1;
	height = 4;
	witdh = 4;
	type = 3;
	lives = 3;
	direccion = 'W';
	cargado = false;
}
Hero::~Hero() {}

void Hero::move(bool mover) {
	

	if (mover)
	{
		if (direccion == 'W') // arriba
		{
			dx = 0;
			dy = -1;
		}
		else if (direccion == 'S') // abajo
		{
			dx = 0;
			dy = 1;
		}
		else if (direccion == 'A') // izquierda
		{
			dx = -1;
			dy = 0;
		}
		else if (direccion == 'D') // derecha
		{
			dx = 1;
			dy = 0;
		}
	}
	else
	{
		dy = dx = 0;
		/*if (direccion == 'W') y += 1;
		else if (direccion == 'S') y -= 1;
		else if (direccion == 'A') x += 1;
		else if (direccion == 'D') x -= 1;*/
	}

	x += dx * speed;
	y += dy * speed;

	dy = dx = 0;
}


void Hero::draw() {

	for (int f = 0; f < height; f++)//recorrer las filas
	{
		for (int c = 0; c < witdh; c++)//recorrer las columnas
		{
			cursorEntity(x + c, y + f);

			if (direccion == 'D') //derecha
			{
				if (dibujoUno[f][c] == 0) colorEntity(12, 12, 12);
				else if (dibujoUno[f][c] == 1) colorEntity(199, 107, 31);
				else if (dibujoUno[f][c] == 2) colorEntity(255, 185, 133);
				else if (dibujoUno[f][c] == 3) colorEntity(31, 185, 7);
			}

			if (direccion == 'A') //izquierda
			{
				if (dibujoDos[f][c] == 0) colorEntity(12, 12, 12);
				else if (dibujoDos[f][c] == 1) colorEntity(199, 107, 31);
				else if (dibujoDos[f][c] == 2) colorEntity(255, 185, 133);
				else if (dibujoDos[f][c] == 3) colorEntity(31, 185, 7);
			}

			if (direccion == 'W' || direccion == 'S') //arriba y abajo
			{
				if (dibujoTres[f][c] == 0) colorEntity(12, 12, 12);
				else if (dibujoTres[f][c] == 1) colorEntity(199, 107, 31);
				else if (dibujoTres[f][c] == 2) colorEntity(255, 185, 133);
				else if (dibujoTres[f][c] == 3)	colorEntity(31, 185, 7);

			}

			cout << char(219);
		}
	}
}

char Hero::getDireccion() { return direccion; }
void Hero::setDireccion(char direccion) { this->direccion = direccion; }
bool Hero::getCargado() { return cargado; }
void Hero::setCargado(bool cargado) { this->cargado = cargado; }