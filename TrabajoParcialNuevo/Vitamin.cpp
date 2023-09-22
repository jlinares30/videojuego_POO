#include "pch.h"
#include "Vitamin.h"
Vitamin::Vitamin(float x, float y) {
	this->x = x;
	this->y = y;
	height = 2;
	witdh = 4;
	type = 1;
	lives = 1;
}
Vitamin::~Vitamin() {

}

void Vitamin::draw() {
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++) {
			cursorEntity(x + c, y + f);
			cout << figure[f][c];
		}
	}
}
