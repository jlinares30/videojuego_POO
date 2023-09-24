#include "pch.h"
#include "Block.h"

Block::Block() {
	x = 0.0;
	y = 0.0;
	dx = 0.0;
	dy = 0.0;
	speed = 0.0;
	height = 2;
	witdh = 4;
	type = 1;
	lives = 1;
}

Block::Block(float x, float y, int type) {
	this->x = x;
	this->y = y;
	height = 2;
	witdh = 4;
	this->type = type;
	lives = 1;
}


Block::~Block() {

}

void Block::draw(int nivel) {
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++) {
			cursorEntity(x + c, y + f);
			if (figure[f][c] == 1)
			{
				switch (nivel)
				{
				case 1: colorEntity(224, 180, 26); break;
				case 2: colorEntity(91, 209, 12); break;
				case 3: colorEntity(111, 121, 154); break;
				}

			}

			if (figure[f][c] == 2)
			{
				switch (nivel)
				{
				case 1: colorEntity(186, 147, 10); break;
				case 2: colorEntity(64, 144, 11); break;
				case 3: colorEntity(76, 83, 107); break;
				}

			}

			cout << char(219);
		}
	}
}