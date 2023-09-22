#include "pch.h"
#include "FlyerBase.h"

FlyerBase::FlyerBase()
{
	x = WITDH_GAME_LATERAL / 2 - 2;
	y = HEIGHT_GAME / 2 - 1;
	height = 2;
	witdh = 4;
}

FlyerBase::~FlyerBase() {}

void FlyerBase::draw() {

	cursorEntity(WITDH_GAME_LATERAL / 2 - 2, HEIGHT_GAME / 2 - 1);
	colorEntity(250, 250, 250); cout << char(178);
	colorEntity(123, 123, 123); cout << char(178);
	colorEntity(250, 250, 250); cout << char(178);
	colorEntity(123, 123, 123); cout << char(178);

	cursorEntity(WITDH_GAME_LATERAL / 2 - 2, HEIGHT_GAME / 2);
	colorEntity(123, 123, 123); cout << char(178);
	colorEntity(250, 250, 250); cout << char(178);
	colorEntity(123, 123, 123); cout << char(178);
	colorEntity(250, 250, 250); cout << char(178);
}