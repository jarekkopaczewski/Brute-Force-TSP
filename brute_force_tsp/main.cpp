#include "Menu.h"
#include <windows.h>

int main(int argc, char** argv)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    Menu menu;
    menu.start();
    return 0;
}