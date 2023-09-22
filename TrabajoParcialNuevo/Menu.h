#pragma once
#include "GameManager.h"

class Menu
{
private:
	GameManager* gameManager;

public:
	Menu();
	~Menu();

	void cursor(int x, int y);
	void color(int R, int G, int B);

	void textoLento(char* texto);

	void showMenu();
	void showInstructions();
	void showCredits();
	void mainMenu();

};

