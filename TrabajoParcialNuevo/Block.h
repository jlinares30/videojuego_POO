#pragma once
#include "Entity.h"

class Block : public Entity
{
private:


public:
	Block();
	Block(float x, float y, int type);
	~Block();

	int figure[2][4] =
	{
		{1, 1, 2, 2},
		{1, 2, 2, 2},
	};

	void draw(int nivel);
};

