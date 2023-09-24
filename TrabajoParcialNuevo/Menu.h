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



	void showMenu();
	void showInstructions();
	void showCredits();
	void mainMenu();

};

