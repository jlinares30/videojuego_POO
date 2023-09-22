#pragma once
#define HEIGHT 30
#define WITDH 130
#define HEIGHT_GAME 30
#define WITDH_GAME 130
#define WITDH_GAME_LATERAL 100
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;
using namespace System;

class Entity
{
protected:
	float x, y, dx, dy, speed;
	int height, witdh;
	int type, lives;

public:
	Entity();
	~Entity();

	//SET
	void setX(float x);
	void setY(float y);
	void setDx(float dx);
	void setDy(float dy);
	void setSpeed(float speed);
	void setHeight(int height);
	void setWitdh(int witdh);
	void setType(int type);
	void setLives(int vidas);

	//GET
	float getX();
	float getY();
	float getDx();
	float getDy();
	float getSpeed();
	int getHeight();
	int getWitdh();
	int getType();
	int getLives();

	void colorEntity(int R, int G, int B);

	void cursorEntity(int x, int y);

	virtual void move();
	virtual void draw();
	virtual void erase();

	//Rectangle getRectangle();

};

