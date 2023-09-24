#pragma once
#include "Entity.h"

class Artifact : public Entity
{
private:
	char charParte;
	char figure1A[3][3] = {
		{'\\','|','/'},
		{'/','|','\\'},
		{' ','|',' '},
	};
	char figure1B[3][3] = {
		{' ','_',' '},
		{'/','o','\\'},
		{'|',' ','|'},
	};
	char figure1C[3][3] = {
		{'/','|','\\'},
		{'|','|','|'},
		{'|','|','|'},
	};
	char figure2A[3][3] = {
		{char(223),char(223),char(223)},
		{char(223),char(223),char(223)},
		{char(223),char(223),char(223)},
	};
	char figure2B[3][3] = {
		{char(178),char(178),char(178)},
		{char(178),char(178),char(178)},
		{char(178),char(178),char(178)},
	};
	char figure2C[3][3] = {
		{char(220),char(220),char(220)},
		{char(220),char(220),char(220)},
		{char(220),char(220),char(220)},
	};
	char figure2D[3][3] = {
		{char(177),char(177),char(177)},
		{char(177),char(177),char(177)},
		{char(177),char(177),char(177)},
	};
	char figure3A[3][3] = {
		{'-','-','-'},
		{'|',' ','|'},
		{'-','-','-'},
	};
	char figure3B[3][3] = {
		{'/','-','\\'},
		{'/',' ','\\'},
		{'/','_','\\'},
	};
	char figure3C[3][3] = {
		{'/',' ','\\'},
		{'|',' ','|'},
		{'|','_','|'},
	};
	char figure3D[3][3] = {
		{'/','|','\\'},
		{'|','|','|'},
		{'|','|','|'},
	};
	char figure3E[3][3] = {
		{'-','-','-'},
		{'|',' ','|'},
		{'\\','_','/'},
	};

public:
	Artifact();
	Artifact(float x, float y, int type);
	~Artifact();

	void draw();
};