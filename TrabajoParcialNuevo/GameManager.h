#pragma once
#include "Block.h"
#include "Hero.h"
#include "EnemyOne.h"
#include "FlyerBase.h"
#include "Flyer.h"
#include "Ally.h"
#include "Vitamin.h"
#include "Artifact.h"
class GameManager
{
private:
	vector<Hero*> hero;
	vector<Block*> blocks;
	vector<Ally*> allies;
	vector< EnemyOne*> enemyOne;
	vector<FlyerBase*> flyerBase;
	vector<Flyer*> flyers;
	vector<Vitamin*> vitamins;
	vector<Artifact*> artifacts;
	Artifact* screenArtifact;

	int cantHero = 0;
	int cantAlly;
	//int cantEnem2;
	bool enemyVelocidadAumentada;
	bool passLevel;
	int nivel;
	int cantBlock;
	int cantEnemy1;
	int cantFlyers;
	int cantVitamin;
	int cantArtif;
	int cantTotalPieces;
	int pieceType;
	int posyBlock, posxBlock;



	time_t timeNow;
	struct tm timeNowLocal;
	int beginTime, diferenceTime;
	int timeCountSec;
	int totalTime;

	bool repeatEnemy;
	bool repeatAlly;
	bool drawVitamin;
	bool repeatArtif;

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

	void textoLento(char* texto) {
		while (*texto) {
			cout << *texto++;
			_sleep(15);
		}
	}

	void definir_consola_inicio();
	void definir_consola_juego();

	int getNivel();
	void setNivel(int nivel);

	void screenLoser();
	void screenWiner();
	void screenYouPass();
	void screenLateral();

	void screenProyectOne();
	void screenProyectTwo();
	void screenProyectThree();

	void eraseEntity();
	void eraserAll();
	void positionAll();
	void drawAll();
	void drawBlocks();
	bool collision(Entity* obj1, Entity* obj2);
	bool collisionWithBlock(Entity* obj1, Entity* obj2, char dir);

	void playLevel();
	void funcionamientoJuego();
};

