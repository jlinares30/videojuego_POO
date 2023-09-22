#pragma once
#include "Entity.h"

class Ally : public Entity
{
public:
	Ally();
	Ally(float x, float y, char dir);
	~Ally();
	char getDir();
	void setDir(char dir);

	void move();
	void draw();
private:
	char dir;
	char figureA[3][3] =
	{
		{' ', '\\', '0'},
		{' ', '/', '|'},
		{'/', '_', '\\'},
	};
	char figureB[3][3] =
	{
		{'0','/', ' '},
		{'|', '\\', ' '},
		{'/', '_', '\\'},
	};
	char figureC[3][3] =
	{
		{' ', '0', ' '},
		{'/', '|', '\\'},
		{'/', '_', '\\'},
	};
};



