#pragma once
#include "Block.h"
#include "Hero.h"
#include "EnemyOne.h"
#include "FlyerBase.h"
#include "Flyer.h"
#include "Ally.h"
#include "Artifact.h"
#include "Vitamin.h" 

class GameManager
{
private:
	vector<Hero*> hero;
	vector<Block*> blocks;
	vector<Ally*> allies; 
	vector< EnemyOne*> enemyOne;
	vector<FlyerBase*> flyerBase;
	vector<Flyer*> flyers;
	vector<Artifact*> artifacts1;
	vector<Vitamin*> vitamins;
	int cantHero = 0;
	int cantAlly;
	//int cantEnem2;
	bool enemyVelocidadAumentada;
	bool passLevel;
	int nivel;
	int cantBlock;
	int cantEnemy1;
	int cantFlyers;
	int cantArt;
	int cantTotalPieces;
	int posyBlock, posxBlock;

	time_t timeNow;
	struct tm timeNowLocal;
	int beginTime, diferenceTime;
	int timeCountSec;
	int totalTime;

	bool repeat = true;
	bool repeatEnemy;
	bool repeatAlly;

public:
	GameManager();
	~GameManager();

	void colorGame(int R, int G, int B)
	{
		cout << "\x1B[38;2;" << R << ";" << G << ";" << B << "m";
	}

	void cursorGame(int x, int y)
	{
		Console::SetCursorPosition(x, y);
	}

	void definir_consola_inicio();
	void definir_consola_juego();

	int getNivel();
	void setNivel(int nivel);

	void screenLoser();
	void screenWiner();
	void screenYouPass();
	void screenLateral();

	void eraseEntity();
	void eraserAll();
	void positionAll();
	void drawAll();
	void drawArtifact();
	void drawBlocks();
	bool collision(Entity* obj1, Entity* obj2);
	bool collisionWithBlock(Entity* obj1, Entity* obj2, char dir);

	void playLevel();
	//void nivelDos();
	//void nivelTres();
	void funcionamientoJuego();
};

