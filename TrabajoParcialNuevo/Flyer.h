#pragma once
#include "Entity.h"

class Flyer : public Entity
{
private:
	char direccion;

public:
	Flyer();
	Flyer(float x, float y, char dir);
	~Flyer();

	void move();
	void draw();

	char getDireccion();
	void setDireccion(char direccion);
};

