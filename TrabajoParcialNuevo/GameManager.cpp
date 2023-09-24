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
	//pieceType = 0;
	cantTotalPieces = 0;
	screenArtifact = new Artifact();
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



	colorGame(226, 196, 24); cursorGame(45, 1); cout << "                 %+                 ";
	colorGame(226, 196, 24); cursorGame(45, 2); cout << "                ::::                ";
	colorGame(226, 196, 24); cursorGame(45, 3); cout << "              :::= #:%              ";
	colorGame(226, 196, 24); cursorGame(45, 4); cout << "          -* ::::==#:#*:..%       ##";
	colorGame(226, 196, 24); cursorGame(45, 5); cout << "#%       *::-%:::+==:=.   +#    #-: ";
	colorGame(226, 196, 24); cursorGame(45, 6); cout << " -+-     =#::::::+#:::  *:     %::+ ";
	colorGame(226, 196, 24); cursorGame(45, 7); cout << "  %:::=#     #::::::: -    .- :::   ";
	colorGame(226, 196, 24); cursorGame(45, 8); cout << "  -:::=#     *::::=:: %     # ::%   ";
	colorGame(226, 196, 24); cursorGame(45, 9); cout << "   *:::=%   :*::::::   #    *::#    ";
	colorGame(226, 196, 24); cursorGame(45, 10); cout << "   .:::"; colorGame(159, 93, 22); cout << "==#"; colorGame(226, 196, 24); cout << " % %= ::::::: % : +*::.    ";
	colorGame(226, 196, 24); cursorGame(45, 11); cout << "    #:::"; colorGame(159, 93, 22); cout << "===#"; colorGame(226, 196, 24); cout << "#%%%%%%%%** ::  ::#     ";
	colorGame(226, 196, 24); cursorGame(45, 12); cout << "    #:::%+"; colorGame(159, 93, 22); cout << "========="; colorGame(226, 196, 24); cout << "   + % *:: + ";
	colorGame(226, 196, 24); cursorGame(45, 13); cout << "    -=*====*"; colorGame(152, 114, 0); cout << "%%%%#%%%%#"; colorGame(226, 196, 24); cout << "=.=-  #+-     ";
	colorGame(152, 114, 0); cursorGame(45, 14); cout << "      %%%%%%%%%%%%%%%%%%%%%%#       ";
	colorGame(152, 114, 0); cursorGame(45, 15); cout << "       .%%%%%%%%%%%%%%%%%-          ";



	colorGame(177, 83, 235);

	cursorGame(14, 16); cout << "                                                                                ,----,           ";
	cursorGame(14, 17); cout << "                                      ,--.                                    ,/###.`| 		  ";
	cursorGame(14, 18); cout << "  ,----..       ,---,               ,--.'|    ,---,          .--.--.        ,`###.'  :     ,---,.";
	cursorGame(14, 19); cout << " /ggg/   \\     '##.' \\          ,--,:##: |   '##.' \\        /##/    '.    ;####;     /   ,'##.' |";
	cursorGame(14, 20); cout << "|ggg:     :   /##;    '.     ,`--.'`|##' :  /##;    '.     |##:  /`. /  .'___,/    ,'  ,---.'   |";
	cursorGame(14, 21); cout << ".ggg|  ;. /  :##:       \\    |###:  :##| | :##:       \\    ;##|  |--`   |####:     |   |###|   .'";
	cursorGame(14, 22); cout << ".ggg; /--`   :##|   /\\   \\   :###|   \\#| : :##|   /\\   \\   |##:  ;_     ;####|.';  ;   :###:  |-,";
	cursorGame(14, 23); cout << ";ggg| ;  __  |##:  ' ;.   :  |###: '  '; | |##:  ' ;.   :   \\##\\    `.  `----'##|  |   :###|  ;/|";
	cursorGame(14, 24); cout << "|ggg: |.' .' |##|  ;/  \\   \\ '###' ;.    ; |##|  ;/  \\   \\   `----.   \\     '###:  ;   |###:   .'";
	cursorGame(14, 25); cout << ".ggg| '_.' : '##:  | \\  \\ ,' |###| | \\   | '##:  | \\  \\ ,'   __ \\##\\  |     |###|  '   |###|  |-,";
	cursorGame(14, 26); cout << "'ggg; : \\  | |##|  '  '--'   '###: |  ; .' |##|  '  '--'    /##/`--'  /     '###:  |   '###:  ;/|";
	cursorGame(14, 27); cout << "|ggg:    /   |##| ,'         '###: |       |##| ,'           `--'---'       '---'      |###:   .'";
	cursorGame(14, 28); cout << " \\ggg\\ .'    `--''           ;###|.'       `--''                                       |###| ,'  ";
	cursorGame(14, 29); cout << "  `---`                      '---'                                                     `----'	  ";


}

void GameManager::screenYouPass()
{
	//cursorGame(1, 1); cout << "PASASTE NIVEL";
	colorGame(37, 158, 193);

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

	colorGame(67, 213, 49);

	cursorGame(24, 13); cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ ";
	cursorGame(24, 14); cout << "|  $$   /$$//$$__  $$| $$  | $$      | $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$";
	cursorGame(24, 15); cout << " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$  \\ $$| $$  \\ $$| $$  \\__/| $$  \\__/";
	cursorGame(24, 16); cout << "  \\  $$$$/ | $$  | $$| $$  | $$      | $$$$$$$/| $$$$$$$$|  $$$$$$ |  $$$$$$ ";
	cursorGame(24, 17); cout << "   \\  $$/  | $$  | $$| $$  | $$      | $$____/ | $$__  $$ \\____  $$ \\____  $$";
	cursorGame(24, 18); cout << "    | $$   | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  \\ $$ /$$  \\ $$ ";
	cursorGame(24, 19); cout << "    | $$   |  $$$$$$/|  $$$$$$/      | $$      | $$  | $$|  $$$$$$/|  $$$$$$/ ";
	cursorGame(24, 20); cout << "    |__/    \\______/  \\______/       |__/      |__/  |__/ \\______/  \\______/  ";


	colorGame(246, 29, 15);
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
	cout << "Compa" << char(164) << "ero: " << allies.size(); //numero de aliados

	cursorGame(WITDH_GAME_LATERAL + 1, 19);
	if (vitamins.size() > 0)colorGame(15, 78, 246);
	cout << "Agua o comida: ";
	if (vitamins.size() <= 0) cout << "No aparecio"; //artefactos().size <= 0 
	else cout << "Aparecio   ";

	colorGame(254, 254, 254);
	if (hero[cantHero]->getCargado()) colorGame(73, 237, 21);
	cursorGame(WITDH_GAME_LATERAL + 1, 21);
	cout << "Cantidad de folletos: "; //numero de piezas recolectadas
	if (hero[cantHero]->getCargado()) cout << cantFlyers;
	else cout << "0";

	colorGame(254, 254, 254);
	cursorGame(WITDH_GAME_LATERAL + 1, 23);
	cout << "Piezas recolectadas: " << cantTotalPieces; //numero de piezas recolectadas

	if (cantTotalPieces > 0)
	{
		screenArtifact->setType(pieceType);

		switch (nivel)
		{
		case 1:
			screenArtifact->setX(WITDH_GAME_LATERAL + ((pieceType * 5) - 1 + 3 * (pieceType - 1)));
			break;
		case 2:
			screenArtifact->setX(WITDH_GAME_LATERAL + (((pieceType - 3) * 4) - 1 + 3 * (pieceType - 4)));
			break;
		case 3:
			screenArtifact->setX(WITDH_GAME_LATERAL + (((pieceType - 7) * 2) - 1 + 3 * (pieceType - 8)));
			break;
		}
		screenArtifact->setY(25);
		screenArtifact->draw();

	}
}

void GameManager::screenProyectOne() {
	//"; colorGame(225, 0, 0); cout << "
	char* titulo = "Peru: Parque eolico Wayra I y proyecto Wayra Extension";
	char* descripcion = "\t\t     Fortalecemos nuestra presencia en el sector de las energias renovables en Peru y  \n\t\t    ayudamos a diversificar la matriz energetica del pais, a fortalecer la confiabilidad\n\t\t            del sistema y a reducir las emisiones de gases de efecto invernadero.       ";

	colorGame(225, 0, 0); cursorGame(WITDH_GAME / 2 - 3, 1); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(225, 0, 0); cout << char(219) << char(219);
	colorGame(225, 0, 0); cursorGame(WITDH_GAME / 2 - 3, 2); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(225, 0, 0); cout << char(219) << char(219);

	colorGame(243, 243, 243);
	cursorGame(WITDH_GAME / 2 - 27, 4); textoLento(titulo);
	cursorGame(1, 6); textoLento(descripcion);

	cursorGame(0, 10);
	colorGame(156, 228, 247);
	cout << "================------------=--====-----=%@@+======+++============++++++****#*##%@%########%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "============------------------=--=====----:-%@@+=====++++++==+++*@@@%#++++++*******%@@%#############%##%%%%%%%%%%%%@@%%%%%%%%%%%%%" << endl;
	cout << "=============---------------------====----::-%@@*+##++++++###%@@%##+==++++++++******%@@%####################%%%%@@%%%%%%%%%%%%%%%%" << endl;
	cout << "===========-------------------------==-----::-+@@%@@++#%%%@@@@**+======+++++++++*****%@@%################%@@@@@%%#%%%%%%%%%%%%%%%%" << endl;
	cout << "----=-======-----:::------------------------::--@@@@@@@@@@@*+===========++++++++++****%@@@############@@@@@@############%%%%%%%%%%" << endl;
	cout << "----------------:--::::--:--:::---------==------=@@@@@@@#+===============+++++++++++***#@@@#@@#####@@@@@@%###############%%%%%%%%%" << endl;
	cout << "------------------::::::::::::---------====-----=@@++++++++=================+++++++++****%@@@@%%@@@@@%%#####################%%%%%%" << endl;
	cout << "--------------------::::::::::--------=======---=@@+=+++++====================+++++++++***#@@@@@@@%%%########################%%%%#" << endl;
	cout << "----------------------:::::::::--------====-==-+@@@+==========================+++++++++++**@@%****################################" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::----*@==*@+==========##+===============---=====*@++@#++++***************################" << endl;
	cout << "...........:::::::::::::::::::::::::::::::::::#:..@@@::::------====####=*@%%###+=--------@#==+@#===*@*+*++*#%#%%#********#########" << endl;
	cout << "....................:::::::::::::::::::::::::#::.:@@:.:::::---------===+@+-----++-------@+==+@#====*@%@%%%@%#%***********#########" << endl;
	cout << ".......................:.::::::::::::::::::::+:::-@@:.....::::-------=-+@+--:---++------%===+@#====++@%******#%*********##########" << endl;
	cout << "...............................:::::::::::::+::::-@@:.......:::::::::-:@@+-::::--#=-----%-===@%+===++@%++*****#%********##########" << endl;
	cout << "................................::::::::::::@::::-@@:...........:::--:=@@=:::::::-#+---++--==@%=++==*@%++******#%#******##########" << endl;
	cout << ".........................................:.+::::.-@@:...........:::---%%#=::::-:::-#*=-@--==+@@+++==@%%++*******#@#***#####%##%###" << endl;
	cout << "...........................................:.....-@@:...........::----@#*=::::-:::--*##@-+%%%@@+====@*%+*********#@@@##%@@########" << endl;
	cout << ".................................................-@@:..........::::-:-@#*=::::-::----*@@@@*=+@@+===+@*%***********#@@@@@########**" << endl;
	cout << ".................................................-@@:.........::::::::@-*=:::.:::----=%=====+@@++++%@*%************%%#############" << endl;
	cout << ".................................................-@@:...  ...:::::-::=@:*=--:.::-----*@===+++@@*++*@*#%***********#@%#############";


}
void GameManager::screenProyectTwo() {
	char* titulo = "Mexico, Luces de esperanza";
	char* descripcion = "\t\t  Iluminando comunidades rurales sin electricidad con energia solar  \n\t\t\t\t transformando vidas, mediante la implementacion de sistemas solares\n\t\t\t\t         brindando un futuro mas brillante y sostenible.       ";

	colorGame(0, 104, 69); cursorGame(WITDH_GAME / 2 - 3, 1); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(225, 0, 0); cout << char(219) << char(219);
	colorGame(0, 104, 69); cursorGame(WITDH_GAME / 2 - 3, 2); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(225, 0, 0); cout << char(219) << char(219);

	colorGame(243, 243, 243);
	cursorGame(WITDH_GAME / 2 - 13, 4); textoLento(titulo);
	cursorGame(18, 6); textoLento(descripcion);

	cursorGame(0, 9);
	colorGame(240, 225, 41);
	cout << "::::::::.............:::::::::::::::::::::::::::::::::::::::::::::::::::#*.-%@@@@@@@%%**%%@@@@%%%%%%%%%%%%%%%%%%####***##*#*##=+:" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::-%.:%@@@@@@@%%*-%%@@@@@@%%*%###%%%%#%%%%#%#########*####=" << endl;
	cout << "...........    ....::::::::::::::::::::::..::::::::::::::::::::::::::::::%. *@@@@@@@@@@%#@@@@@%%%%%%%%%%%%%%#%##%%#+-=###########" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::......:=+#%@@@@@%:+@@%*.*@@@@@@@@%%@%@%%@@@%%%%%%%#%%%%%%%%%%%%#%#=#####*####" << endl;
	cout << ":::::::::::::::::::::::::::...............:@@@%@%@#%%@%+#@*@@@@@@@@@@**@#%+-:...--+#%%%##*##*########*%#%%%%#%##%####*#########*#" << endl;
	cout << ":::::::::................................ %@%%%@%@@@%@#.*@%@@@@@%#%%%#*%%#:.    .:=+**+-.    ... .:--.=++============++++*+*####*" << endl;
	cout << ":........................................=%%@@@@@@@@%@#:#@@@@@%%*+%*%*:*%*+  +****####*+-:    .....  ...               ... ::::::" << endl;
	cout << ":.................                .......*@@@@@%@@@@@@#+@@@@%%%%##%+@#.*%%*  %@@@@@@@@@#%%*##%%%%%%#######+#######+-#**+===:. ..." << endl;
	cout << "::::...........:::::::::::::::::::::::::+@@@%%@@@@@@@@**@@%%%%%%%%%#@%+#@%*. %@@@@@@@@@@@@@=%@@%@@@@@%%@@%%%%%%%%*%%%%#%######*##" << endl;
	cout << ":::.......::....:::::::::::::..::......:#@@@@@%@@%@%@%-+@@%%%%%%%%%%%@*+%%#=  @@@@@@@@@@@@@@@@@%%@@@@%%%%%%%%%%%%%%%%%###%#######" << endl;
	cout << ":::::::::::::::::::::::::::::..........+@@@@@@%@@%@%@%:=@@@@@%%%%%%%%%*.#%%+. @@@@@@@@@@@%@@@*@@@@@@@@@%%%@%%%%%%%%%#%*%%%####*##" << endl;
	cout << "::::::::::::::::::::::................:%@@@@@@@@@@@@@%.=@@%@@@@@@@@@@@*.%@#*: -=*###%%@@@@@@@-=%@@@@@@%%%%%%=%%#%%%%##%%+*#######" << endl;
	cout << "::::::::..............................=%*#%*@%%@*@@%@@+#@#@@@@@@@@@%%@#+%@%*- .%@@@@@@@@@@#%@%%@@@%@@@@%%%%%#*%%+%%%%%%%#*###*###" << endl;
	cout << ":::::::::::::::::----:----::::::......@@@%*+-:::::::::-::::..::-====:*+-:*##* .%@@@#@@@@@@@@@@@%%@%%@@@%%%%%%#+%%*%%%%%%###%#%###" << endl;
	cout << "----------------------::::::::..:---:%@@@@#@@%@%@@@@@:-@@@@%#@@@@@@@*@@= %@%=. -@@@@@@@@@@@@@@@*#@@%%@@%@%%@%%*+%%%%%%%%##%#+####" << endl;
	cout << ":::::::::::::.:::::.:-+*+*+*-*++*%%@*%%%@*%%%%%*%%#@@:-@@@@%%@@@@@@@%@@+ @@@%. -@@@@%@@@@@@@@@@@@@@@@@@%@@@%@%%*+%%%%%%%%%%%%####" << endl;
	cout << "::::::::.:==#*+##**-##%%%%%-#@@@#@%*#@@@@%%%#@@@@%%@%#*@%%%##%#%%*#%%%%=-%%@@.  *@@@@@@@@@@@@#@@@*@@@@@@%@%%%%%%#+%%%%%%%%%#*%#=#" << endl;
	cout << "#@@:@%%%%#*%%%#@%%=@@@*%%@#=@@@@@@%#@@@@%%@@@@*@@@@@:+@@@@@@@@@@@%@@@@@+=%@@@.  =@@@@@@@@@@@@@@@@%-@@@#%%%%%%%%%%%*%%%+%%%%%%###*" << endl;
	cout << "@=%%%%%#%+@%@%#%%*@%%#@%%%+%#@@%%%**%#%%%%@#@@@@@%@@-.@@*%@@@@@@%#%@@@@@-:%@@@  -#%%%%%%%%%@@@@%@@%=%%@#%%%%%@%%%#-.---==*#%%%%##" << endl;
	cout << "#%%@%%#+%%%%%%%+**++*#%%%+%@@@@%#*+@@@@@@@@@@%@@%%@@:.@@*%%%%%#%#+*%%%%%..%%@@   :+++****##%%%%#@@#:=%%%%%%%%%%%%%%%%%%##%%%%%%*#" << endl;


}
void GameManager::screenProyectThree() {
	char* titulo = "Nigeria: Programa de Electrificacion de Nigeria";
	char* descripcion = "\t\t   Pretende instalar redes cerradas para suministrar electricidad a comunidades aisladas, destinado\n\t\t    especificamente al 43% de los nigerianos que se encuentran fuera del alcance de la red electrica";

	colorGame(68, 122, 57); cursorGame(WITDH_GAME / 2 - 3, 1); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(68, 122, 57); cout << char(219) << char(219);
	colorGame(68, 122, 57); cursorGame(WITDH_GAME / 2 - 3, 2); cout << char(219) << char(219); colorGame(242, 242, 242); cout << char(219) << char(219); colorGame(68, 122, 57); cout << char(219) << char(219);

	colorGame(243, 243, 243);
	cursorGame(WITDH_GAME / 2 - 23, 4); textoLento(titulo);
	cursorGame(1, 6); textoLento(descripcion);

	cursorGame(0, 9);

	colorGame(190, 195, 196);
	cout << "     ...:::   ..:...                      .:.:.   =.-       .:..          ..          .-+*:..     -..              .:.   " << endl;
	cout << "      ...:.::.  ..::.                       ::::  =:-         ::.          ..      .-:..=-.:-:---.::              ...    " << endl;
	cout << "        ...::::::::-+=+:                     .-=:.=:=          -.           :   .:==-+=-=*+====-:-::              ..     " << endl;
	cout << "          .::-==++=-:  ....                    :=-+-=.:::.      :..         .:  :......:==.      :.:             .:      " << endl;
	cout << " ...           .+=-:.    .::..               .---=*=+:::-==:     :..         .. :      :-=.      ::.             .       " << endl;
	cout << ".:::-:.       ..--:..=-.     ..:.          .--::.:==+-..   .   .  :.          ..:      .--.    . -:             ..       " << endl;
	cout << ". ...:::::-:.. :--=     :. .     ..:.....:--:--=--+-++---==-=-=+--.:.       :.    :    --==     :-     . .:              " << endl;
	cout << ".:.:..    .:...-=-=..    ..          .-===-::=:::-====.. ..    . :  ...    .  :.  :    -:.-.   .::    .-..               " << endl;
	cout << "......:.....:..:--=..:::....          .  ..::-   .=:-=:: ..     .:    ::.. ..  ...-.   -. -:   .=.    .-.                " << endl;
	cout << "           ..:-=+=*::.   ...::.::..   .   .  :...:==-=.  :-..... =      ..:-:    :-:   ---:-   ...    .:                 " << endl;
	cout << "           ::-:=+==.:=+=-::. ....:::..-......:   .-:=+::.:- ...::-     .   ..     ::   =:-:=   ..:    ..                 " << endl;
	cout << "       .::::-.:=-++:--+=+==== .:..... :  ....:   .---=.   .  .   ..    .    .     .:.  =. :=   ...    ..                 " << endl;
	cout << "     :==--==-==*#*#-::-.    ..  .   .. :.     .. :=.:=.    ..     :.        ..     :   =-::-    .:    .              ... " << endl;
	cout << "     -......   -=++ ..:     ..    .   ....     :.:= .=.     .      :.        :     ..  =:=--    .:    :             ...  " << endl;
	cout << ".... : .....   ===+   -     ..     ..   ..      :-=..= ..   .      ..        ..     .  +-:-=    ..    .              .   " << endl;
	cout << ".-:::=:::::-::.+***:::=.:...::      ..    ..     =+=-+. ..          :.        .     .  +-::=.   ..    .             .   ." << endl;
	cout << "              -+--=: ..        ..... ..     ..  ---..-=..     ..  .    .:.      ..   .-=:  -+   :.   ..    .+.... .      " << endl;
	cout << "              -::=:-   .         .  ...:.     ..-::. .::..     ..  :    ...     ..    -+. ..=.  ::   .    ..=..      ... " << endl;
	cout << "              -::--=.    ..        . .....     .--. .:.: .:.    .. ..    ..... ...... =-.   -=. ::   .    .:+=.       .  " << endl;
	cout << "             .-====- ..   .:..      :. ....    .-=-..:--   ..     :....   ...  ...-.  =+----=+. ::   .    ..-:.      .   " << endl;
	cout << "             .--:=--    ..  ..:      ...  ...  .---:=:=-.   .      ...:-   ...  ..-.  =-::-::+:.:.   ..    .-:          ." << endl;
	cout << "             ::-:---.     :..  ..      ..   .:..-=...:=::.   ..     ..:=   .....::=:. =-=. =:=. :.  . :   ..==.       .  ";


}

int GameManager::getNivel() { return nivel; }
void GameManager::setNivel(int nivel) { this->nivel = nivel; }

void GameManager::eraseEntity()
{

	for (int i = vitamins.size(); i > 0; i--)
	{
		vitamins[i - 1]->erase();
		vitamins.erase(vitamins.end() - 1);
	}

	for (int i = enemyOne.size(); i > 0; i--)
	{
		enemyOne[i - 1]->erase();
		enemyOne.erase(enemyOne.end() - 1);
	}

	for (int i = allies.size(); i > 0; i--)
	{
		allies[i - 1]->erase();
		allies.erase(allies.end() - 1);
	}

	for (int i = flyers.size(); i > 0; i--)
	{
		flyers[i - 1]->erase();
		flyers.erase(flyers.end() - 1);
	}

	for (int i = artifacts.size(); i > 0; i--)
	{
		artifacts[i - 1]->erase();
		artifacts.erase(artifacts.end() - 1);
	}

	cantTotalPieces = 0;
	screenArtifact->setType(0);

	cantFlyers = 5;
	hero[cantHero]->erase();
	hero[cantHero]->setCargado(false);

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
				blocks[j]->draw(nivel);
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
				blocks[j]->draw(nivel);
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
				blocks[j]->draw(nivel);
			}
		}
		allies[i]->move();
	}

	/*for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i]->move();
	}*/
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

			do
			{

				for (int k = 0; k < blocks.size(); k++)
				{
					if (collision(auxEnemy[i], blocks[k]))
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
				}

			} while (collision(auxEnemy[i], hero[cantHero]));
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

	//VITAMINS
	cantVitamin = (nivel == 1) ? 1 : 2;
	if (drawVitamin && timeCountSec % 30 == 0 && timeCountSec != 0 && timeCountSec < totalTime && vitamins.size() < cantVitamin)
	{

		rdmX = rand() % WITDH_GAME_LATERAL;
		rdmY = rand() % HEIGHT_GAME;
		vitamins.push_back(new Vitamin(rdmX, rdmY));
		for (int k = 0; k < blocks.size(); k++)
		{
			if (collision(vitamins[vitamins.size() - 1], blocks[k]) || (rdmX == WITDH_GAME_LATERAL / 2 && rdmY == HEIGHT_GAME / 2))
			{
				vitamins.erase(vitamins.begin() + vitamins.size() - 1);
				rdmX = rand() % WITDH_GAME_LATERAL;
				rdmY = rand() % HEIGHT_GAME;
				vitamins.push_back(new Vitamin(rdmX, rdmY));
				k = -1;
			}
		}
	}

	for (int i = 0; i < vitamins.size(); i++)
	{
		if (collision(vitamins[i], hero[cantHero])) {
			hero[cantHero]->setLives(hero[cantHero]->getLives() + 1);
			vitamins[i]->erase();
			vitamins.erase(vitamins.begin() + i);
			i--;
		}
		else vitamins[i]->draw();
	}

	//ARTIFACTS
	cantArtif = (nivel == 1) ? 3 : (nivel == 2) ? 4 : 5;
	if (timeCountSec == 2 && repeatArtif) {

		repeatArtif = false;

		for (int i = 0; i < cantArtif; i++)
		{
			rdmX = rand() % WITDH_GAME_LATERAL;
			rdmY = rand() % HEIGHT_GAME;
			if (nivel == 1)
			{
				artifacts.push_back(new Artifact(rdmX, rdmY, i + 1));
			}
			else if (nivel == 2)
			{
				artifacts.push_back(new Artifact(rdmX, rdmY, i + 4));
			}
			else if (nivel == 3)
			{
				artifacts.push_back(new Artifact(rdmX, rdmY, i + 8));
			}

			for (int k = 0; k < blocks.size(); k++)
			{
				if (collision(artifacts[i], blocks[k]) || collision(hero[cantHero], artifacts[i]))
				{
					artifacts.erase(artifacts.begin() + i);
					rdmX = rand() % WITDH_GAME_LATERAL;
					rdmY = rand() % HEIGHT_GAME;
					if (nivel == 1)
					{
						artifacts.push_back(new Artifact(rdmX, rdmY, i + 1));
					}
					else if (nivel == 2)
					{
						artifacts.push_back(new Artifact(rdmX, rdmY, i + 4));

					}
					else if (nivel == 3)
					{
						artifacts.push_back(new Artifact(rdmX, rdmY, i + 8));
					}
					k = -1;
				}
			}

		}
	}

	for (int i = 0; i < artifacts.size(); i++)
	{
		if (collision(artifacts[i], hero[cantHero]))
		{
			cantTotalPieces++;
			pieceType = artifacts[i]->getType();
			artifacts[i]->erase();
			artifacts.erase(artifacts.begin() + i);
			i--;
		}
		else artifacts[i]->draw();
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
			if (f == 0 || f == posyBlock - 1 || c == 0 || c == posxBlock - 1)
			{
				blocks.push_back(new Block(c * 4, f * 2, 1));

			}
		}
	}

	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->draw(nivel);
	}
}

void GameManager::playLevel() {

	passLevel = true;
	enemyVelocidadAumentada = false;
	beginTime = timeNowLocal.tm_hour * 3600 + timeNowLocal.tm_min * 60 + timeNowLocal.tm_sec;
	diferenceTime = beginTime - clock() / 1000;
	repeatEnemy = true;
	repeatAlly = true;
	repeatArtif = true;
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

		_sleep(50);
	}

	//if (hero[cantHero]->getLives() <= 0) passLevel = false;
	if (hero[cantHero]->getLives() <= 0 || cantTotalPieces < cantArtif || enemyOne.size() > 0) passLevel = false;

	eraseEntity();
	//passLevel = false;
	Console::Clear();
}
//void GameManager::nivelDos() {}
//void GameManager::nivelTres() {}

void GameManager::funcionamientoJuego()
{
	//Variables para el jugador

	if (nivel == 1)
	{
		screenProyectOne();
		_sleep(3000);
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
		//cursorGame(1, 2); cout << "ENROO";
		//_sleep(1500);
		definir_consola_juego();

		Console::Clear();
		screenProyectTwo();
		_sleep(3000);
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
		screenProyectThree();
		_sleep(3000);
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
		system("cls");
		definir_consola_inicio();
		screenLoser();
		//screenYouPass();
		_sleep(5000);
	}
}