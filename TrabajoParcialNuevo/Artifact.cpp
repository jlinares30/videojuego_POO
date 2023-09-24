#include "pch.h"
#include "Artifact.h"


Artifact::Artifact() {
	dx = 0;
	dy = 0;
	lives = 1;
	x = 0;
	y = 0;
	height = 3;
	witdh = 3;
	type = 0;
}

Artifact::Artifact(float x, float y, int type) {
	dx = 0;
	dy = 0;
	lives = 1;
	this->x = x;
	this->y = y;
	height = 3;
	witdh = 3;
	this->type = type;
}


Artifact::~Artifact() {

}

void Artifact::draw() {
	Console::ForegroundColor = ConsoleColor::Cyan;

	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			cursorEntity(x + c, y + f);
			switch (type)
			{
			case 1:
				cout << figure1A[f][c];
				break;

			case 2:
				cout << figure1B[f][c];
				break;

			case 3:
				cout << figure1C[f][c];
				break;

			case 4:
				cout << figure2A[f][c];
				break;

			case 5:
				cout << figure2B[f][c];
				break;

			case 6:
				cout << figure2C[f][c];
				break;

			case 7:
				cout << figure2D[f][c];
				break;

			case 8:
				cout << figure3A[f][c];
				break;

			case 9:
				cout << figure3B[f][c];
				break;

			case 10:
				cout << figure3C[f][c];
				break;

			case 11:
				cout << figure3D[f][c];
				break;

			case 12:
				cout << figure3E[f][c];
				break;

			default:
				break;
			}
		}
	}
}