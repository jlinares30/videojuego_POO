#pragma once
#include "Entity.h"
#include "Flyer.h"

class Hero : public Entity
{
private:
	char direccion;
	int dibujoUno[4][4] = {
		{0, 1, 1, 0},
		{0, 1, 2, 0},
		{0, 3, 3, 0},
		{1, 0, 0, 1},
	};
	int dibujoDos[4][4] = {
		{0, 1, 1, 0},
		{0, 2, 1, 0},
		{0, 3, 3, 0},
		{1, 0, 0, 1},
	};
	int dibujoTres[4][4] = {
		{0, 1, 1, 0},
		{0, 2, 2, 0},
		{0, 3, 3, 0},
		{1, 0, 0, 1},
	};
	bool cargado;

public:
	Hero();
	~Hero();

	char getDireccion();
	void setDireccion(char direccion);
	bool getCargado();
	void setCargado(bool cargado);

	void move(bool mover);
	void draw();

};

