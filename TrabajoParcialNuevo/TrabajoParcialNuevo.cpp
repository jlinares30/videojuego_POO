#include "pch.h"
#include "Menu.h"

int main()
{
    srand(time(nullptr));
    Menu* menu = new Menu();

    menu->mainMenu();

    system("pause>0");
    return 0;
}
