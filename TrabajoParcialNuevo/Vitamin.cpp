#include "pch.h"
#include "Vitamin.h"

Vitamin::Vitamin() {
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	height = 5;
	witdh = 3;
	type = 0;
	lives = 1;
}
Vitamin::Vitamin(int x, int y) {
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	height = 5;
	witdh = 3;
	type = 0;
	lives = 1;
}
Vitamin::~Vitamin() {}

void Vitamin::draw() {
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			cursorEntity(x + c, y + f);

			if (figure[f][c] == 0) colorEntity(12, 12, 12);
			else if (figure[f][c] == 1) colorEntity(26, 35, 82);
			else if (figure[f][c] == 2) colorEntity(22, 74, 186);
			else if (figure[f][c] == 3) colorEntity(183, 183, 183);

			cout << char(219);
		}
	}
}