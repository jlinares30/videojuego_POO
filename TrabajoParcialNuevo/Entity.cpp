#include "pch.h"
#include "Entity.h"

Entity::Entity() {
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	height = 0;
	witdh = 0;
	type = 0;
	lives = 0;
}
Entity::~Entity() {

}

//SET
void Entity::setX(float x) { this->x = x; }
void Entity::setY(float y) { this->y = y; }
void Entity::setDx(float dx) { this->dx = dx; }
void Entity::setDy(float dy) { this->dy = dy; }
void Entity::setSpeed(float speed) { this->speed = speed; }
void Entity::setHeight(int height) { this->height = height; }
void Entity::setWitdh(int witdh) { this->witdh = witdh; }
void Entity::setType(int type) { this->type = type; }
void Entity::setLives(int lives) { this->lives = lives; }

//GET
float Entity::getX() { return x; }
float Entity::getY() { return y; }
float Entity::getDx() { return dx; }
float Entity::getDy() { return dy; }
float Entity::getSpeed() { return speed; }
int Entity::getHeight() { return height; }
int Entity::getWitdh() { return witdh; }
int Entity::getType() { return type; }
int Entity::getLives() { return lives; }

void Entity::colorEntity(int R, int G, int B)
{
	cout << "\x1B[38;2;" << R << ";" << G << ";" << B << "m";
}

void Entity::cursorEntity(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

void Entity::move() {

}

void Entity::draw() {

}

void Entity::erase() {
	for (int f = 0; f < height; f++)
	{
		for (int c = 0; c < witdh; c++)
		{
			cursorEntity(x + c, y + f);
			cout << " ";
		}
	}
}