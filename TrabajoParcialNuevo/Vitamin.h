#pragma once
#include "Entity.h"

class Vitamin : public Entity
{
private:
	int figure[5][3] =
	{
		{0, 1, 0},
		{2, 2, 2},
		{3, 3, 3},
		{2, 2, 2},
		{2, 2, 2},
	};

public:
	Vitamin();
	Vitamin(int x, int y);
	~Vitamin();

	void draw();
};

