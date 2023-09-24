#include "pch.h"
#include "Menu.h"


Menu::Menu() {
    gameManager = new GameManager();
}
Menu::~Menu() {}

void Menu::cursor(int x, int y)
{
    Console::SetCursorPosition(x, y);
}

void Menu::color(int R, int G, int B)
{
    cout << "\x1B[38;2;" << R << ";" << G << ";" << B << "m";
}


void Menu::showMenu()
{
    system("cls");

    color(244, 196, 28);
    cout << "\t\t\t\t\t\t\t ..-- - .. " << endl;
    cout << "\t\t\t\t\t\t\t /       \\ " << endl;
    cout << "\t\t\t\t\t\t\t|         | " << endl;
    cout << "\t\t\t\t\t\t\t:         ; " << endl;
    cout << "\t\t\t\t\t\t\t \\  \\~/  / " << endl;
    cout << "\t\t\t\t\t\t\t  `, Y ,' " << endl;
    color(153, 151, 147);
    cout << "\t\t\t\t\t\t\t   |_|_| " << endl;
    cout << "\t\t\t\t\t\t\t   |===| " << endl;
    cout << "\t\t\t\t\t\t\t   |===| " << endl;
    cout << "\t\t\t\t\t\t\t    \\_/ " << endl;



    color(37, 130, 118);

    cout << "\n\n\t\t\t\t\t\t"; cout << char(201) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(186); color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); color(224, 224, 13); cout << " P O W E R ";
    color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178); color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(186); color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178); color(224, 224, 13); cout << "  S A V E R  ";
    color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178); color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << " 1.";
    color(170, 225, 208); cout << " Jugar             "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "   2.";
    color(170, 225, 208); cout << " Historia        "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "    3.";
    color(170, 225, 208); cout << " Creditos       "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "     4.";
    color(170, 225, 208); cout << " Salir         "; color(37, 130, 118); cout << char(186) << endl;
    color(37, 130, 118);
    cout << "\t\t\t\t\t\t"; cout << char(200) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

    color(239, 239, 239);
}

void Menu::showInstructions() {
    char* textoUno = "Bienvenido a Energia Elemental : La Busqueda Sostenible. Actualmente, el mundo se \n\t\t enfrente a un desafio mundial : brindar energia sostenible a paises en desarrollo.Frente\n\t\t  a ello, se van creando proyectos de desarrollo de energia renovable en paises en\n\t\t   situacion de precariedad. Participa como voluntario en tres proyectos de energias\n\t\t    renovables e infraestructura ayudando a la construccion de fuentes de energia.";
    //Participa como voluntario en tres proyectos de ayuda desarrollando nergías sostenibles, \n\t\t vive esta experiencia unica y divertida construyendo energias \n\t renovables y entregando afiches informativos a los manifestantes para alcanzar un futuro energetico viable";
    cout << "\n\n\n";
    cout << "\t    -------------------------------------------------------------------------------" << endl;
    cout << "\t      -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t"; gameManager->textoLento(textoUno);
    cout << "\n\t\t  -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;


    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";

    _getch();
    system("cls");

    char* textoDos = "Los ciudadanos locales desconocen la importancia de los proyectos a favor de la \n\t\t energia renovable y el bien mayor que pretenden realizar.Han empezado protestas en\n\t\t  contra de su construccion y fueron al lugar para impedirlo.RECOLECTA TODAS LAS\n\t\t   PIEZAS DE LAS FUENTES DE ENERGIA y REPARTE AFICHES INFORMATIVOS A LOS MANIFESTANTES\n\n\t\t    * Para adquirir los afiches ve al centro de la consola para recogerlos de la caja *";
    char* cuidado = "CUIDADO!!!";

    cursor(WITDH_GAME / 2 - 7, 1); gameManager->textoLento(cuidado);
    cout << "\n";
    cout << "\t    -------------------------------------------------------------------------------" << endl;
    cout << "\t      -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t"; gameManager->textoLento(textoDos);
    cout << "\n\t\t  -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;



    cout << "                                   ............-.          " << endl;
    cout << "                                   ............-.          " << endl;
    cout << "                                   ............--:         " << endl;
    cout << "                                   ............##%#        " << endl;
    cout << "                                   ...........-#*#%%-      " << endl;
    cout << "                                   ........... %*#*%@.     " << endl;
    cout << "                                    +***:     ++++#*@:     " << endl;
    cout << "                                         .*=+**+==:+@@     " << endl;
    cout << "                                         :    -+#:=#@.     " << endl;
    cout << "                                        .*: .. %=-#%.      " << endl;
    cout << "                                         **********##**#%  " << endl;
    cout << "                                        .=-#+*****###***#%." << endl;
    cout << "                                        .=  --=**#*##-+#%%." << endl;
    cout << "                                        .=    -**###%.  +#." << endl;
    cout << "                                        .-    :***##%.     " << endl;
    cout << "                                        .=*   :+*###%.     " << endl;
    cout << "                                        .-*   =*##*#%.     " << endl;





    cout << "\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";

    _getch();
    system("cls");

    gameManager->screenProyectOne();
    cursor(WITDH_GAME - 37, HEIGHT_GAME - 1);
    cout << "   Pulsa una tecla para continuar... ";

    _getch();
    system("cls");

    gameManager->screenProyectTwo();
    cursor(WITDH_GAME - 37, HEIGHT_GAME - 1);
    cout << "   Pulsa una tecla para continuar... ";

    _getch();
    system("cls");

    gameManager->screenProyectThree();
    cursor(WITDH_GAME - 37, HEIGHT_GAME - 1);
    cout << "   Pulsa una tecla para continuar... ";



    _getch();
    system("cls");
}

void Menu::showCredits() {
    char* texto = "\n\n\n\n\t1. Camila Ibarra \n\n\t2. Jorge Linares";
    color(223, 23, 14);
    cout << "\n\n\t\t\t\t           #";
    cout << "\n\t\t\t\t          ##.";
    cout << "\n\t\t\t\t     #    ####.        #";
    cout << "\n\t\t\t\t   .#     .######       #.";
    cout << "\n\t\t\t\t   ##      #######      ##";
    cout << "\n\t\t\t\t   ###       #####.    ###";
    cout << "\n\t\t\t\t   ####        ###    ####";
    cout << "\n\t\t\t\t    ######     #   ######";
    cout << "\n\t\t\t\t      #################";
    cout << "\n\t\t\t\t         ###########\n";
    color(254, 254, 254);
    gameManager->textoLento(texto);
    cursor(75, 25);
    cout << "Profesor: Henry Antonio Mendoza Puerta";
    cursor(78, 29);
    color(0, 135, 81);
    cout << "Pulsa una tecla para continuar...";

}

void Menu::mainMenu()
{
    int opcion;
    //GameManager* gameManager;
    gameManager->definir_consola_inicio();
    showMenu();

    do
    {
        showMenu();

        cout << "\n\n\n";
        color(210, 55, 249);
        cout << "\t\t\t\t\t\t\t\t\t\t\t############" << endl;
        color(202, 101, 247);
        cout << "\t\t\t\t\t\t\t\t\t\t\tIngrese una opcion: "; cin >> opcion;
        system("cls");

        color(255, 255, 255);
        //Console::Clear();

        switch (opcion)
        {
        case 1: //JUGAR
            gameManager = new GameManager();
            gameManager->definir_consola_juego();
            gameManager->setNivel(1);
            gameManager->funcionamientoJuego();
            break;

        case 2: //HISTORIA - INSTRUCCIONES
            gameManager->definir_consola_inicio();
            showInstructions();

            break;

        case 3: //CREDITOS
            gameManager->definir_consola_inicio();
            showCredits();
            _getch();
            system("cls");
            break;

        case 4: //SALIR
            gameManager->definir_consola_inicio();
            color(243, 64, 56);
            cout << "\aSaliendo del juego..." << endl;
            break;

        default:
            color(255, 37, 0);
            cout << "\a\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
            cout << "\t\t\t\tOpcion invalida. Por favor, ingrese un numero valido." << endl;
            cout << "\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
            color(223, 223, 223);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";
            color(255, 255, 255);
            _getch();
            system("cls");
            break;
        }

        cout << endl;


    } while (opcion != 4);

}