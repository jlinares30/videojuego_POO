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

void Block::draw() {
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++) {
			cursorEntity(x + c, y + f);
			if (figure[f][c] == 1)colorEntity(224, 180, 26);
			if (figure[f][c] == 2)colorEntity(186, 147, 10);
			cout << char(219);
		}
	}
}