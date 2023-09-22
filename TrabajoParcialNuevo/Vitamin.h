#pragma once
#include "Entity.h"
class Vitamin :public Entity
{
public:
	Vitamin(float x, float y);
	~Vitamin();

	void draw() override;

private:
	char figure[4][3] =
	{
		{' ','_',' '},
		{'/',' ','\\'},
		{'|',' ','|'},
		{'|','_','|'}
	};
};