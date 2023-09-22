#include "pch.h"
#include "Menu.h"


Menu::Menu(){
    gameManager = new GameManager();
}
Menu::~Menu(){}

void Menu::cursor(int x, int y)
{
    Console::SetCursorPosition(x, y);
}

void Menu::color(int R, int G, int B)
{
    cout << "\x1B[38;2;" << R << ";" << G << ";" << B << "m";
}

void Menu::textoLento(char* texto) {
    while (*texto) {
        cout << *texto++;
        _sleep(15);
    }
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
    cout << "\t\t\t\t\t\t"; cout << char(186);color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); color(224, 224, 13); cout << " P O W E R ";
   color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178); color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(186);color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178) << char(178); color(224, 224, 13); cout << "  S A V E R  ";
   color(170, 225, 208); cout << char(178) << char(178) << char(178) << char(178); color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << " 1.";
   color(170, 225, 208); cout << " Jugar             "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "  2.";
   color(170, 225, 208); cout << " Tutorial         "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "   3.";
   color(170, 225, 208); cout << " Historia        "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "    4.";
   color(170, 225, 208); cout << " Creditos       "; color(37, 130, 118); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; color(37, 130, 118); cout << char(186); color(224, 224, 13); cout << "     5.";
   color(170, 225, 208); cout << " Salir         "; color(37, 130, 118); cout << char(186) << endl;
    color(37, 130, 118);
    cout << "\t\t\t\t\t\t"; cout << char(200) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

    color(239, 239, 239);
}

void Menu::showInstructions() {
    char* texto = "Bienvenido a Energía Elemental : La Búsqueda Sostenible. En 2030, el mundo se \n\t\tenfrenta a un desafío crucial: brindar energía sostenible a los países en desarrollo. \n\t\tTres personajes con habilidades únicas están listos para la aventura. Explora,  \n\t\t mas desafiante, haciendo que la experiencia sea aun mas emocionante.\n\t\tresuelve desafíos y ayuda a estos países a alcanzar un futuro energético limpio y billante";

        cout << "\n\n\n";
    cout << "\t    -------------------------------------------------------------------------------" << endl;
    cout << "\t      -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t"; textoLento(texto);
    cout << "\n\t\t  -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;


    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";
}

void Menu::showCredits() {
    char* texto = "\n\n\n\n\t1. Leandro Arevalo \n\n\t2. Camila Ibarra\n\n\t3. Jorge Linares";
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
    textoLento(texto);
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";

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

        case 2: //TUTORIAL
            break;

        case 3: //HISTORIA - INSTRUCCIONES
            gameManager->definir_consola_inicio();
            showInstructions();
            _getch();
            system("cls");
            break;

        case 4: //CREDITOS
            gameManager->definir_consola_inicio();
            showCredits();
            _getch();
            system("cls");
            break;

        case 5: //SALIR
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


    } while (opcion != 5);

}