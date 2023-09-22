#pragma once
#include "Entity.h"

class EnemyOne : public Entity
{
private:
	char dir;

	char figure[4][3][3] =
	{
		{ //0 - derecha
		{' ', char(220), '/'},
		{'/', '#', ' '},
		{'/', '>', ' '},
		},

		{ //1 - izquierda
		{char(92), char(220), ' '},
		{' ', '#', char(92)},
		{' ', '<', char(92)},
		},

		{ //2 - abajo
		{char(92), char(220), '/'},
		{' ', '#', ' '},
		{'/', ' ', char(92)},
		},

		{ //4 - arriba
		{' ', char(220), ' '},
		{'/', '#', char(92)},
		{'/', ' ', char(92)},
		},
	};
	/*
	char figureA[3][3] =
	{
		{' ', char(220), '/'},
		{'/', '#', ' '},
		{'/', '>', ' '},
	};
	char figureB[3][3] =
	{
		{char(92), char(220), ' '},
		{' ', '#', char(92)},
		{' ', '<', char(92)},
	};
	char figureC[3][3] =
	{
		{char(92), char(220), '/'},
		{' ', '#', ' '},
		{'/', ' ', char(92)},
	};
	char figureD[3][3] =
	{
		{' ', char(220), ' '},
		{'/', '#', char(92)},
		{'/', ' ', char(92)},
	};*/

public:
	EnemyOne();
	EnemyOne(float x, float y, char dir);

	~EnemyOne();

	char getDir();
	void setDir(char dir);

	void move();
	void draw();

};

