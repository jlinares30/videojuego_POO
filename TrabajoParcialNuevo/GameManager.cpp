#include "pch.h"
#include "GameManager.h"


GameManager::GameManager() {
	timeNow = time(NULL);
	timeNowLocal = *localtime(&timeNow);
	passLevel = false;
	enemyVelocidadAumentada = false;
	int nivel = 0;
	hero.push_back(new Hero());
	flyerBase.push_back(new FlyerBase());
	cantFlyers = 5;
	posyBlock = HEIGHT_GAME / 2;
	posxBlock = WITDH_GAME_LATERAL / 4;
}
GameManager::~GameManager() {}

void GameManager::definir_consola_inicio()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Obtener informacion actual de la consola
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	// Cambiar el tamaño de la fuente
	fontInfo.dwFontSize.X = 18; // Ancho de la fuente
	fontInfo.dwFontSize.Y = 18; // Alto de la fuente

	// Establecer la nueva fuente
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	Console::SetWindowSize(WITDH, HEIGHT);
	Console::CursorVisible = false;
}

void GameManager::definir_consola_juego()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Obtener informacion actual de la consola
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	// Cambiar el tamaño de la fuente
	fontInfo.dwFontSize.X = 18; // Ancho de la fuente
	fontInfo.dwFontSize.Y = 18; // Alto de la fuente

	// Establecer la nueva fuente
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	Console::SetWindowSize(WITDH_GAME, HEIGHT_GAME);
	Console::CursorVisible = false;
}

void GameManager::screenLoser()
{
	//cursorGame(1, 1); cout << "PERDISTE";

	colorGame(226, 233, 231);

	cursorGame(17, 1); cout << " ____                                                 _____                              ";
	cursorGame(17, 2); cout << "/\\  _`\\                                              /\\  __`\\                            ";
	cursorGame(17, 3); cout << "\\ \\ \\ \\_\\     __       ___ ___       __              \\ \\ \\/\\ \\    __  __     __    _ __  ";
	cursorGame(17, 4); cout << " \\ \\ \\_ _   /'__`\\   /' __` __`\\   /'__`\\             \\ \\ \\ \\ \\  /\\ \\/\\ \\  /'__`\\ /\\`'__\\";
	cursorGame(17, 5); cout << "  \\ \\ \\_, \\/\\ \\L\\.\\_ /\\ \\/\\ \\/\\ \\ /\\  __/              \\ \\ \\_\\ \\ \\ \\ \\_/ |/\\  __/ \\ \\ \\/ ";
	cursorGame(17, 6); cout << "   \\ \\____/\\ \\__/.\\_\\\\ \\_\\ \\_\\ \\_\\\\ \\____\\              \\ \\_____\\ \\ \\___/ \\ \\____\\ \\ \\_\\ ";
	cursorGame(17, 7); cout << "    \\/___/  \\/__/\\/_/ \\/_/\\/_/\\/_/ \\/____/               \\/_____/  \\/__/   \\/____/  \\/_/ ";


	cursorGame(48, 9); cout << "          @ @ @     @ @ @          ";
	cursorGame(48, 10); cout << "      + @                 @ +      ";
	cursorGame(48, 11); cout << "    @ =                     * @    ";
	cursorGame(48, 12); cout << "    @                         @    ";
	cursorGame(48, 13); cout << "   @                            @  ";
	cursorGame(48, 14); cout << "   @                            @  ";
	cursorGame(48, 15); cout << " +                                +";
	cursorGame(48, 16); cout << " @                                @";
	cursorGame(48, 17); cout << " %    @ @                 @ @     *";
	cursorGame(48, 18); cout << "   .  @ @ @ @         @ @ @ @   .  ";
	cursorGame(48, 19); cout << "   @    @ @ @ @     @ @ @ @     @  ";
	cursorGame(48, 20); cout << "   @      @             @       @  ";
	cursorGame(48, 21); cout << " @              @ @               @";
	cursorGame(48, 22); cout << " =              @ @               -";
	cursorGame(48, 23); cout << "   @                            @  ";
	cursorGame(48, 24); cout << "    : @     @   - -   @     @ :    ";
	cursorGame(48, 25); cout << " 	 @     @         @     @       ";
	cursorGame(48, 26); cout << "      % @ @ @   @ @   @ @ @ %      ";
}

void GameManager::screenWiner()
{

	colorGame(177, 83, 235);

	cursorGame(10, 1); cout << "                                                                                ,----,           ";
	cursorGame(10, 2); cout << "                                      ,--.                                    ,/###.`| 		  ";
	cursorGame(10, 3); cout << "  ,----..       ,---,               ,--.'|    ,---,          .--.--.        ,`###.'  :     ,---,.";
	cursorGame(10, 4); cout << " /ggg/   \\     '##.' \\          ,--,:##: |   '##.' \\        /##/    '.    ;####;     /   ,'##.' |";
	cursorGame(10, 5); cout << "|ggg:     :   /##;    '.     ,`--.'`|##' :  /##;    '.     |##:  /`. /  .'___,/    ,'  ,---.'   |";
	cursorGame(10, 6); cout << ".ggg|  ;. /  :##:       \\    |###:  :##| | :##:       \\    ;##|  |--`   |####:     |   |###|   .'";
	cursorGame(10, 7); cout << ".ggg; /--`   :##|   /\\   \\   :###|   \\#| : :##|   /\\   \\   |##:  ;_     ;####|.';  ;   :###:  |-,";
	cursorGame(10, 8); cout << ";ggg| ;  __  |##:  ' ;.   :  |###: '  '; | |##:  ' ;.   :   \\##\\    `.  `----'##|  |   :###|  ;/|";
	cursorGame(10, 9); cout << "|ggg: |.' .' |##|  ;/  \\   \\ '###' ;.    ; |##|  ;/  \\   \\   `----.   \\     '###:  ;   |###:   .'";
	cursorGame(10, 10); cout << ".ggg| '_.' : '##:  | \\  \\ ,' |###| | \\   | '##:  | \\  \\ ,'   __ \\##\\  |     |###|  '   |###|  |-,";
	cursorGame(10, 11); cout << "'ggg; : \\  | |##|  '  '--'   '###: |  ; .' |##|  '  '--'    /##/`--'  /     '###:  |   '###:  ;/|";
	cursorGame(10, 12); cout << "|ggg:    /   |##| ,'         '###: |       |##| ,'           `--'---'       '---'      |###:   .'";
	cursorGame(10, 13); cout << " \\ggg\\ .'    `--''           ;###|.'       `--''                                       |###| ,'  ";
	cursorGame(10, 14); cout << "  `---`                      '---'                                                     `----'	  ";


}

void GameManager::screenYouPass()
{
	//cursorGame(1, 1); cout << "PASASTE NIVEL";

                       
    cursorGame(WITDH_GAME / 2 - 7, 1); cout << "       ::      ";                              
    cursorGame(WITDH_GAME / 2 - 7, 2); cout << "       +*:     ";                              
    cursorGame(WITDH_GAME / 2 - 7, 3); cout << "      =##:     ";                              
    cursorGame(WITDH_GAME / 2 - 7, 4); cout << "     -##*.     ";                              
    cursorGame(WITDH_GAME / 2 - 7, 5); cout << "     +##*====- ";                              
    cursorGame(WITDH_GAME / 2 - 7, 6); cout << "    .*######## ";                              
    cursorGame(WITDH_GAME / 2 - 7, 7); cout << "    =########+ ";                              
    cursorGame(WITDH_GAME / 2 - 7, 8); cout << "##*+########## ";                              
    cursorGame(WITDH_GAME / 2 - 7, 9); cout << "##**#########* ";                              
    cursorGame(WITDH_GAME / 2 - 7, 10); cout << "###*#########. ";                                                       
    cursorGame(WITDH_GAME / 2 - 7, 11); cout << "###+########*. ";                                                       

	cursorGame(24, 13); cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ ";
	cursorGame(24, 14); cout << "|  $$   /$$//$$__  $$| $$  | $$      | $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$";
	cursorGame(24, 15); cout << " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$  \\ $$| $$  \\ $$| $$  \\__/| $$  \\__/";
	cursorGame(24, 16); cout << "  \\  $$$$/ | $$  | $$| $$  | $$      | $$$$$$$/| $$$$$$$$|  $$$$$$ |  $$$$$$ ";
	cursorGame(24, 17); cout << "   \\  $$/  | $$  | $$| $$  | $$      | $$____/ | $$__  $$ \\____  $$ \\____  $$";
	cursorGame(24, 18); cout << "    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \\ $$ /$$  \\ $$ ";
	cursorGame(24, 19); cout << "    | $$   |  $$$$$$/|  $$$$$$/      | $$      | $$  | $$|  $$$$$$/|  $$$$$$/ ";
	cursorGame(24, 20); cout << "    |__/    \\______/  \\______/       |__/      |__/  |__/ \\______/  \\______/  ";

	cursorGame(5, 22); cout << " -%#: .%%=  +%*   *%*  -%%.  +%=  -%%:  +%+  :%#:  -%#:  #%+  =%#.  *%+  -%%: .#%-  -%%: .#%+  -%#.  *%*  -%%: .*%=     ";
	cursorGame(5, 23); cout << "  %%%#:+%%%=:%%%* -%%%*.#%%%.+%%%+.*%%%-=%%%+:%%%#::%%%#-+%%%+:%%%#.+%%%+.#%%%:=%%%-:#%%%-=%%%+.%%%#.=%%%*.#%%%:=%%%=   ";
	cursorGame(5, 24); cout << "   :%%%#-+%%%+:%%%* -%%%*.#%%%:+%%%+.*%%%--%%%+:%%%#::#%%#-=%%%+.%%%#.=%%%*.#%%%:=%%%=.#%%%-=%%%+.%%%#.=%%%*.*%%%:=%%%+ ";
	cursorGame(5, 25); cout << "     %%%# +%%%=.%%%% -%%%* %%%% *%%%+ %%%% =%%%= %%%%:.%%%%.+%%%+.%%%% *%%%*.%%%% +%%%:.%%%%.=%%%+ %%%%.+%%%#.%%%% *%%%=";
	cursorGame(5, 26); cout << "    *%%%:+%%%+:#%%%:-%%%*.#%%%--%%%# *%%%--%%%#:*%%%-.*%%%-=%%%+:#%%%::%%%* #%%%:+%%%*.*%%%:=%%%+:#%%%-:%%%*.#%%%-=%%%#.";
	cursorGame(5, 27); cout << "  %%%%.-%%%+ %%%%: %%%#.#%%%=-%%%# *%%%--%%%# *%%%- *%%%::%%%+ %%%%: %%%# %%%%.=%%%* *%%%::%%%* #%%%- %%%# %%%%-=%%%*   ";
	cursorGame(5, 28); cout << " +%%: :%%+  +%%:  *%*  -%%- .%%#  :%%- .%%#. =%%:  =%%: .#%=  =%#: .*%*  -%%: .%%*  -%%: .#%+  =%%:  *%*  -%%: .%%*     ";
                                                                                                                        

	}

void GameManager::screenLateral() {
	
	colorGame(248, 221, 26);
	if (nivel == 1)
	{
		cursorGame(WITDH_GAME_LATERAL, 0); cout << "______________________________";
		cursorGame(WITDH_GAME_LATERAL, 1); cout << "   _     _                   _";
		cursorGame(WITDH_GAME_LATERAL, 2); cout << "   /|   /   ,           /   //";
		cursorGame(WITDH_GAME_LATERAL, 3); cout << "--/-| -/-----------_---/---/--";
		cursorGame(WITDH_GAME_LATERAL, 4); cout << " /  | /    / | / /__) /   /	  ";
		cursorGame(WITDH_GAME_LATERAL, 5); cout << "/___|/____/__|/_(____/___/____";
	}
	else if (nivel == 2)
	{
		cursorGame(WITDH_GAME_LATERAL, 0); cout << "______________________________";
		cursorGame(WITDH_GAME_LATERAL, 1); cout << "   _     _                  _ ";
		cursorGame(WITDH_GAME_LATERAL, 2); cout << "   /|   /   ,           /  / )";
		cursorGame(WITDH_GAME_LATERAL, 3); cout << "--/-| -/----------__---/---_/-";
		cursorGame(WITDH_GAME_LATERAL, 4); cout << " /  | /    / | / /__) /   /  ";
		cursorGame(WITDH_GAME_LATERAL, 5); cout << "/___|/____/__|/_(____/___/__/_";
	}
	else if (nivel == 3)
	{
		cursorGame(WITDH_GAME_LATERAL, 0); cout << "______________________________";
		cursorGame(WITDH_GAME_LATERAL, 1); cout << "   _     _                  _ ";
		cursorGame(WITDH_GAME_LATERAL, 2); cout << "   /|   /   ,           /  / )";
		cursorGame(WITDH_GAME_LATERAL, 3); cout << "--/-| -/-----------_---/----/-";
		cursorGame(WITDH_GAME_LATERAL, 4); cout << " /  | /    / | / /__) /      )";
		cursorGame(WITDH_GAME_LATERAL, 5); cout << "/___|/____/__|/_(____/___(__/_";
	}

	colorGame(254, 254, 254);
	cursorGame(WITDH_GAME_LATERAL + 1, 7); //cout << "ENTROOOO";
	cout << "Tiempo: " << timeCountSec << " / " << totalTime << "  ";
	cursorGame(WITDH_GAME_LATERAL + 1, 11);
	cout << "Heroe: ";
	colorGame(199, 31, 31);
	for (int i = 0; i < 3; i++)
	{
		cursorGame(WITDH_GAME_LATERAL + 7 + i * 7, 9);  cout << "       ";
		cursorGame(WITDH_GAME_LATERAL + 7 + i * 7, 10); cout << "       ";
		cursorGame(WITDH_GAME_LATERAL + 7 + i * 7, 11); cout << "       ";
		cursorGame(WITDH_GAME_LATERAL + 7 + i * 7, 12); cout << "       ";
		cursorGame(WITDH_GAME_LATERAL + 7 + i * 7, 13); cout << "       ";

	}
	if (hero[cantHero]->getLives() <= 3)
	{
		for (int i = 0; i < hero[cantHero]->getLives(); i++)
		{
			cursorGame(WITDH_GAME_LATERAL + 8 + i * 7, 9);  cout << " ^  ^ ";
			cursorGame(WITDH_GAME_LATERAL + 8 + i * 7, 10); cout << "*#**#*";
			cursorGame(WITDH_GAME_LATERAL + 8 + i * 7, 11); cout << "*#**#*";
			cursorGame(WITDH_GAME_LATERAL + 8 + i * 7, 12); cout << " *##* ";
			cursorGame(WITDH_GAME_LATERAL + 8 + i * 7, 13); cout << "  **  ";

		}
	}
	else
	{
		cursorGame(WITDH_GAME_LATERAL + 9, 9);  cout << "   *       *   ^  ^ ";
		cursorGame(WITDH_GAME_LATERAL + 9, 10); cout << "     *   *    *#**#*";
		cursorGame(WITDH_GAME_LATERAL + 9, 11); cout << hero[cantHero]->getLives() << "      *      *#**#*";
		cursorGame(WITDH_GAME_LATERAL + 9, 12); cout << "     *   *     *##* ";
		cursorGame(WITDH_GAME_LATERAL + 9, 13); cout << "   *       *    **  ";
	}

	colorGame(254, 254, 254);

	cursorGame(WITDH_GAME_LATERAL + 1, 15);
	cout << "Manifestantes: " << enemyOne.size();

	cursorGame(WITDH_GAME_LATERAL + 1, 17);
	cout << "Compa" << char(164) << "ero: " << 4; //numero de aliados

	cursorGame(WITDH_GAME_LATERAL + 1, 19);
	cout << "Agua o comida: ";
	if (true) cout << "No aparecio"; //artefactos().size <= 0 
	else cout << "Aparecio";

	if (hero[cantHero]->getCargado()) colorGame(73, 237, 21);
	cursorGame(WITDH_GAME_LATERAL + 1, 21);
	cout << "Cantidad de folletos: "; //numero de piezas recolectadas
	if (hero[cantHero]->getCargado()) cout << cantFlyers;
	else cout << "0";

	colorGame(254, 254, 254);
	cursorGame(WITDH_GAME_LATERAL + 1, 23);
	cout << "Piezas recolectadas: " << 4; //numero de piezas recolectadas
	//dibujo de las piezas
}


int GameManager::getNivel() { return nivel; }
void GameManager::setNivel(int nivel) { this->nivel = nivel; }

void GameManager::eraseEntity()
{
	for (int i = enemyOne.size(); i > 0; i--)
	{
		enemyOne.erase(enemyOne.end() - 1);
	}

	for (int i = allies.size(); i > 0; i--)
	{
		allies.erase(allies.end() - 1);
	}

	for (int i = flyers.size(); i > 0; i--)
	{
		flyers.erase(flyers.end() - 1);
	}

	hero[cantHero]->erase();
}


void GameManager::eraserAll() {
	
	for (int i = 0; i < enemyOne.size(); i++)
	{
		enemyOne[i]->erase();
	}

	
	for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i]->erase();
	}

	for (int i = 0; i < allies.size(); i++)
	{
		allies[i]->erase();
	}
}

void GameManager::positionAll() {
	Random r;
	bool eliminado;

	//FLYERS
	for (int i = 0; i < flyers.size(); i++)
	{
		//Collision con BLOQUES
		for (int j = 0; j < blocks.size(); j++)
		{
			if (collision(blocks[j], flyers[i]))
			{
				flyers[i]->setLives(flyers[i]->getLives() - 1);
				flyers[i]->erase();
				blocks[j]->draw();
			}
		}

		for (int j = 0; j < enemyOne.size(); j++)
		{
			if (collision(enemyOne[j], flyers[i]))
			{
				flyers[i]->setLives(flyers[i]->getLives() - 1);
				flyers[i]->erase();
				enemyOne[j]->erase();
				enemyOne.erase(enemyOne.begin() + j);
			}
		}

		if (flyers[i]->getLives() <= 0)
		{
			flyers.erase(flyers.begin() + i);
			i -= 1;
		}
		else flyers[i]->move();
	}

	//ENEMY 1
	for (int i = 0; i < enemyOne.size(); i++)
	{
		for (int j = 0; j < blocks.size(); j++)
		{
			if (collision(enemyOne[i], blocks[j]))
			{
				if (enemyOne[i]->getDir() == 'W' || enemyOne[i]->getDir() == 'S')
				{
					enemyOne[i]->setY(enemyOne[i]->getDir() == 'W' ? enemyOne[i]->getY() + 1 : enemyOne[i]->getY() - 1);
					enemyOne[i]->setDir(r.Next(0, 2) ? 'A' : 'D');
				}
				else if (enemyOne[i]->getDir() == 'A' || enemyOne[i]->getDir() == 'D')
				{
					enemyOne[i]->setX(enemyOne[i]->getDir() == 'A' ? enemyOne[i]->getX() + 1 : enemyOne[i]->getX() - 1);
					enemyOne[i]->setDir(r.Next(0, 2) ? 'W' : 'S');
				}
				blocks[j]->draw();
			}
		}

		if (collision(enemyOne[i], hero[cantHero]))
		{
			hero[cantHero]->setLives(hero[cantHero]->getLives() - 1);
			hero[cantHero]->erase();
			hero[cantHero]->setX(4);
			hero[cantHero]->setY(4);
		}
		enemyOne[i]->setSpeed((timeCountSec >= 70 && nivel == 2) || (timeCountSec >= 100 && nivel == 3) ? 1.0 : 0.5);
		enemyOne[i]->move();
	}

	//ALLY
	for (int i = 0; i < allies.size(); i++)
	{
		for (int j = 0; j < blocks.size(); j++)
		{
			if (collision(allies[i], blocks[j]))
			{
				if (allies[i]->getDir() == 'W' || allies[i]->getDir() == 'S')
				{
					allies[i]->setY(allies[i]->getDir() == 'W' ? allies[i]->getY() + 1 : allies[i]->getY() - 1);
					allies[i]->setDir(r.Next(0, 2) ? 'A' : 'D');
				}
				else if (allies[i]->getDir() == 'A' || allies[i]->getDir() == 'D')
				{
					allies[i]->setX(allies[i]->getDir() == 'A' ? allies[i]->getX() + 1 : allies[i]->getX() - 1);
					allies[i]->setDir(r.Next(0, 2) ? 'W' : 'S');
				}
				blocks[j]->draw();
			}
		}
		allies[i]->move();
	}

	/*for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i]->move();
	}*/
}
void GameManager::drawArtifact() {
	int rdmXArtfc1, rdmYArtfc1;
	cantArt= nivel == 1 ? 3 : nivel == 2 ? 4 : 5;
	if (timeCountSec == 2 && repeat) {

		for (int i = 0; i < cantArt; i++)
		{
			rdmXArtfc1 = rand() % WITDH_GAME_LATERAL;
			rdmYArtfc1 = rand() % HEIGHT_GAME;
			if (nivel == 1)
			{
				artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 1));
			}
			else if (nivel == 2)
			{
				artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 4));
			}
			else if (nivel == 3)
			{
				artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 8));
			}
		}
		for (size_t i = 0; i < artifacts1.size(); i++)
		{
			for (int k = 0; k < blocks.size(); k++)
			{
				if (collision(artifacts1[i], blocks[k]))
				{
					artifacts1.erase(artifacts1.begin() + i);
					rdmXArtfc1 = rand() % WITDH_GAME_LATERAL;
					rdmYArtfc1 = rand() % HEIGHT_GAME;
					if (nivel == 1)
					{
						artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 1));
					}
					else if (nivel == 2)
					{
						artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 3));

					}
					else if (nivel == 3)
					{
						artifacts1.push_back(new Artifact(rdmXArtfc1, rdmYArtfc1, i + 6));
					}
					k = -1;
				}
			}
		}

		cursorGame(WITDH_GAME_LATERAL + 1, 17);
		cout << artifacts1.size();
		repeat = false;
	}
	for (int i = 0; i < artifacts1.size(); i++)
	{
		artifacts1[i]->draw();
	}
}

void GameManager::drawAll() {

	screenLateral();

	float rdmX, rdmY;
	char dir;

	cantEnemy1 = (timeCountSec >= 70 && nivel == 3) ? 4 : 2;
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)

	//ENEMY 1
	if (timeCountSec % 15 == 1) repeatEnemy = true;
	if (timeCountSec % 15 == 0 && timeCountSec < totalTime && repeatEnemy)
	{
		repeatEnemy = false;
		vector<EnemyOne*> auxEnemy;
		for (int i = 0; i < cantEnemy1; i++)
		{
			rdmX = rand() % WITDH_GAME_LATERAL;
			rdmY = rand() % HEIGHT_GAME;
			switch (1 + rand() % 4)
			{
			case 1: dir = 'A'; break;
			case 2: dir = 'D'; break;
			case 3: dir = 'S'; break;
			case 4: dir = 'W'; break;
			}
			auxEnemy.push_back(new EnemyOne(rdmX, rdmY, dir));

			for (int k = 0; k < blocks.size(); k++)
			{
				if (collision(auxEnemy[i], blocks[k]) || collision(auxEnemy[i], hero[cantHero]))
				{
					auxEnemy.erase(auxEnemy.begin() + i);
					rdmX = rand() % WITDH_GAME_LATERAL;
					rdmY = rand() % HEIGHT_GAME;
					switch (1 + rand() % 4)
					{
					case 1: dir = 'A'; break;
					case 2: dir = 'D'; break;
					case 3: dir = 'S'; break;
					case 4: dir = 'W'; break;
					}
					auxEnemy.push_back(new EnemyOne(rdmX, rdmY, dir));
					k = -1;
				}

				/*do
				{
					if (k != 0) enemyOne.erase(enemyOne.begin() + i);
					rdmX = rand() % WITDH_GAME_LATERAL;
					rdmY = rand() % HEIGHT_GAME;
					switch (1 + rand() % 4)
					{
					case 1: dir = 'A'; break;
					case 2: dir = 'D'; break;
					case 3: dir = 'S'; break;
					case 4: dir = 'W'; break;
					}
					enemyOne.push_back(new EnemyOne(rdmX, rdmY, dir));


					for (int j = 0; j < enemyOne.size() - 1; j++)
					{

						if (collision(enemyOne[j], enemyOne[i])) {
							enemyOne.erase(enemyOne.begin() + i);
							rdmX = rand() % WITDH_GAME_LATERAL;
							rdmY = rand() % HEIGHT_GAME;
							switch (1 + rand() % 4)
							{
							case 1: dir = 'A'; break;
							case 2: dir = 'D'; break;
							case 3: dir = 'S'; break;
							case 4: dir = 'W'; break;
							}
							enemyOne.push_back(new EnemyOne(rdmX, rdmY, dir));
							j = -1;
						}
					}

				} while (collision(enemyOne[i], blocks[k]));*/
			}
			enemyOne.push_back(auxEnemy[i]);
		}

		for (int i = 0; i < auxEnemy.size(); i++)
		{
			auxEnemy.erase(auxEnemy.begin() + i);
		}
	}

	for (int i = 0; i < enemyOne.size(); i++)
	{
		enemyOne[i]->draw();
	}

	//ALLY 
	cantAlly = 1;
	//repeat = true;
	if (timeCountSec == 31) repeatAlly = true;
	if (timeCountSec == 30 && repeatAlly)
	{
		repeatAlly = false;
		vector<Ally*> auxAlly;
		for (int i = 0; i < cantAlly; i++)
		{
			rdmX = rand() % WITDH_GAME_LATERAL;
			rdmY = rand() % HEIGHT_GAME;
			switch (1 + rand() % 4)
			{
			case 1: dir = 'A'; break;
			case 2: dir = 'D'; break;
			case 3: dir = 'S'; break;
			case 4: dir = 'W'; break;
			}
			auxAlly.push_back(new Ally(rdmX, rdmY, dir));

			for (int k = 0; k < blocks.size(); k++)
			{
				if (collision(auxAlly[i], blocks[k]))
				{
					auxAlly.erase(auxAlly.begin() + i);
					rdmX = rand() % WITDH_GAME_LATERAL;
					rdmY = rand() % HEIGHT_GAME;
					switch (1 + rand() % 4)
					{
					case 1: dir = 'A'; break;
					case 2: dir = 'D'; break;
					case 3: dir = 'S'; break;
					case 4: dir = 'W'; break;
					}
					auxAlly.push_back(new Ally(rdmX, rdmY, dir));
					k = -1;
				}

			}

			allies.push_back(auxAlly[i]);

			for (int i = auxAlly.size(); i > 0; i--)
			{
				auxAlly.erase(auxAlly.end() - 1);
			}
		}
	}
	for (int i = 0; i < allies.size(); i++)
	{
		for (int y = 0; y < enemyOne.size(); y++)
		{
			if (collision(allies[i], enemyOne[y]))
			{
				enemyOne[y]->erase();
				enemyOne.erase(enemyOne.begin() + y);
			}
		}
		allies[i]->draw();
	}


	//FLYERS
	for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i]->draw();

	}
}

bool GameManager::collision(Entity* obj1, Entity* obj2) {
	int x1 = obj1->getX();
	int y1 = obj1->getY();
	int height1 = obj1->getHeight();
	int witdh1 = obj1->getWitdh();

	int x2 = obj2->getX();
	int y2 = obj2->getY();
	int height2 = obj2->getHeight();
	int witdh2 = obj2->getWitdh();

	int lim_x1 = x1 + witdh1;
	int lim_y1 = y1 + height1;
	int lim_x2 = x2 + witdh2;
	int lim_y2 = y2 + height2;

	bool colisionX = (x1 < lim_x2) && (lim_x1 > x2);
	bool colisionY = (y1 < lim_y2) && (lim_y1 > y2);

	return colisionX && colisionY;
}


bool GameManager::collisionWithBlock(Entity* obj1, Entity* obj2, char dir) {
	int x1 = obj1->getX();
	int y1 = obj1->getY();
	int height1 = obj1->getHeight();
	int witdh1 = obj1->getWitdh();

	int x2 = obj2->getX();
	int y2 = obj2->getY();
	int height2 = obj2->getHeight();
	int witdh2 = obj2->getWitdh();

	int lim_x1 = x1 + witdh1;
	int lim_y1 = y1 + height1;
	int lim_x2 = x2 + witdh2;
	int lim_y2 = y2 + height2;

	bool colisionX; // = (x1 < lim_x2) && (lim_x1 > x2);
	bool colisionY; // = (y1 < lim_y2) && (lim_y1 > y2);

	switch (dir)
	{
	case 'W':
		colisionX = (x1 < lim_x2) && (lim_x1 > x2);
		colisionY = (y1 < lim_y2) && (lim_y1 > y2 - 1);
		break;

	case 'S':
		colisionX = (x1 < lim_x2) && (lim_x1 > x2);
		colisionY = (y1 - 1 < lim_y2) && (lim_y1 > y2);
		break;

	case 'A':
		colisionX = (x1 < lim_x2) && (lim_x1 > x2 - 1);
		colisionY = (y1 < lim_y2) && (lim_y1 > y2);
		break;

	case 'D':
		colisionX = (x1 - 1 < lim_x2) && (lim_x1 > x2);
		colisionY = (y1 < lim_y2) && (lim_y1 > y2);
		break;
	}

	return colisionX && colisionY;
}

void GameManager::drawBlocks() {
	
	for (int i = blocks.size(); i > 0; i--)
	{
		blocks.erase(blocks.end() - 1);
	}
	
	if (nivel == 1) cantBlock = 15;
	if (nivel == 2)	cantBlock = 25;
	if (nivel == 3) cantBlock = 38;

	int rdmX, rdmY;

	for (int i = 0; i < cantBlock; i++)
	{
		//NUMERO ALEATORIO
		//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)
		//                 1         + rand() % (  (posY/posX - 2)     +1  -    1   )
		do
		{
			rdmX = 1 + rand() % (posxBlock - 2);
			rdmY = 1 + rand() % (posyBlock - 2);
			blocks.push_back(new Block(rdmX * 4, rdmY * 2, 1));
		} while (collision(blocks[i], hero[cantHero]));
		for (int j = 0; j < blocks.size() - 1; j++)
		{
			if (collision(blocks[j], blocks[i]) || (rdmX == (posxBlock - 1) / 2 && rdmY == (posyBlock - 1) / 2)) {
				blocks.erase(blocks.begin() + i);
				rdmX = 1 + rand() % (posxBlock - 2);
				rdmY = 1 + rand() % (posyBlock - 2);
				blocks.push_back(new Block(rdmX * 4, rdmY * 2, 1));
				j = -1;
			}
		}
	}

	
	for (int f = 0; f < posyBlock; f++)
	{
		for (int c = 0; c < posxBlock; c++)
		{
			if (f == 0 || f == posyBlock - 1|| c == 0 || c == posxBlock - 1)
			{
				blocks.push_back(new Block(c * 4, f * 2, 1));

			}
		}
	}

	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->draw();	
	}
}

void GameManager::playLevel() {

	passLevel = true;
	enemyVelocidadAumentada = false;
	beginTime = timeNowLocal.tm_hour * 3600 + timeNowLocal.tm_min * 60 + timeNowLocal.tm_sec;
	diferenceTime = beginTime - clock() / 1000;
	repeatEnemy = true;
	repeatAlly = true;
	while (timeCountSec < totalTime && hero[cantHero]->getLives())
	{
		flyerBase[0]->draw();
		timeCountSec = diferenceTime - (beginTime - clock() / 1000);

		eraserAll();

		//hero[cantHero]->erase();
		if (_kbhit())
		{
			char tecla = _getch();

			
			hero[cantHero]->erase();

			if (tecla == char(32))
			{
				if (hero[cantHero]->getCargado())
				{
					cantFlyers--;
					flyers.push_back(new Flyer(hero[cantHero]->getX(), hero[cantHero]->getY(), hero[cantHero]->getDireccion()));
					if (cantFlyers <= 0)
					{
						cantFlyers = 5;
						hero[cantHero]->setCargado(false);
					}
				}
			}
			else if (toupper(tecla) == 'W' || toupper(tecla) == 'S' || toupper(tecla) == 'A' || toupper(tecla) == 'D')
			{
				hero[cantHero]->setDireccion(toupper(tecla));

				//HERO
				bool mover = true;

				for (int i = 0; i < blocks.size(); i++)
				{
					if (collisionWithBlock(blocks[i], hero[cantHero], hero[cantHero]->getDireccion())) mover = false;
				}
				hero[cantHero]->move(mover);
			}

			

		}
		hero[cantHero]->draw();

		if (collision(flyerBase[0], hero[cantHero])) hero[cantHero]->setCargado(true);

		positionAll();
		drawAll();
		drawArtifact();

		_sleep(50);
	}

	if (enemyOne.size() > 0 || hero[cantHero]->getLives() <= 0) passLevel = false;
	//if (hero[cantHero]->getLives() <= 0) passLevel = false;

	eraseEntity();
	//passLevel = false;
	Console::Clear();
}
//void GameManager::nivelDos() {}
//void GameManager::nivelTres() {}

void GameManager::funcionamientoJuego() {
	//Variables para el jugador

	if (nivel == 1)
	{
		Console::Clear();
		//Muestra el funcionamiento del GameManager

		totalTime = 60;
		//division_pantalla();
		drawBlocks();
		hero[cantHero]->draw();
		playLevel();
		//timeCountSec < totalTime&& hero[cantHero]->getLives() > 0 && enemyOne.size() == 0
		if (!passLevel) nivel = 0;
		else
		{
			definir_consola_inicio();
			screenYouPass();
			_sleep(5000);
			nivel++;
		}
	}

	if (nivel == 2)
	{
		cursorGame(1, 1); cout << "ENROO";
		definir_consola_juego();
		
		Console::Clear();
		totalTime = 90;

		hero[cantHero]->setX(4);
		hero[cantHero]->setY(4);
		drawBlocks();
		

		hero[cantHero]->draw();
		playLevel();

		
		if (!passLevel) nivel = 0;
		else
		{
			definir_consola_inicio();
			screenYouPass();
			_sleep(5000);
			nivel++;
		}
	}

	if (nivel == 3)
	{

		Console::Clear();
		totalTime = 120;

		definir_consola_juego();

		hero[cantHero]->setX(4);
		hero[cantHero]->setY(4);
		drawBlocks();

		hero[cantHero]->draw();
		playLevel();

		if (!passLevel) nivel = 0;
		else
		{
			definir_consola_inicio();
			screenWiner();
			_sleep(5000);
			//nivel++;
		}
	}

	/*if (nivel == 4) //funcionalidad adicioal
	{

		Console::CursorVisible = false;
		system("cls");
		transicion_adicional();
		Console::Clear();
		definir_consola_inicio();
		adicional();

	}*/

	if (nivel == 0)
	{
		definir_consola_inicio();
		screenLoser();
		//screenYouPass();
		_sleep(5000);
	}
}