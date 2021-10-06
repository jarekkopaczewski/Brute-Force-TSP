#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <string>
#include "Menu.h"
#include "DataReader.h"
using namespace std;

Menu::Menu()
{
    mode = 0;
    opcja = 0;
    strct = 0;
    graph = new Graph();
    logs = new string * [2];
    logs[0] = new string[2]{ "Brute force", "Zakoncz dzialanie programu" };
    logs[1] = new string[3]{ "Wczytaj graf z pliku", "Wyswietl macierz","Wyjdz" };
    menuMax = new int[2]{ 2, 3 };
}

Menu::~Menu()
{
    delete[] menuMax;
    for (int i = 0; i < 2; i++)
    {
        delete[] logs[i];
    }
    delete[] logs;
}

void Menu::start()
{
    while (Menu::menu());
    cout << "\t\t\t\t   Zakonczono pomyslnie" << endl;
}

bool Menu::menu()
{
    int znak = 0;
    system("cls");

    showText();
    znak = readKey();

    switch (mode)
    {
        case 0:
            mainMenu(znak);
            break;
        case 1:
            bruteMenu(znak);
            break;
    }

    if (mode == 0 && opcja == 2 && znak == 13)
        return false;

    if (opcja == menuMax[mode] - 1 && znak == 13)
    {
        opcja = 0;
    }

    if (opcja < 0)
    {
        opcja = menuMax[mode] - 1;
    }

    if (opcja > menuMax[mode] - 1)
    {
        opcja = 0;
    }

    return true;
}

void Menu::showText()
{
    cout << "\t\t\t\t\t    Dostepne opercaje:\n" << endl;
    for (int i = 0; i < menuMax[mode]; i++)
    {
        if (opcja == i)
        {
            cout << "\t\t\t\t\t=> " + logs[mode][i] << endl;
        }
        else
        {
            cout << "\t\t\t\t\t" + logs[mode][i] << endl;
        }
    }
}

int Menu::readKey()
{
    int znak = _getch();
    if (znak == 0xE0)
    {
        znak = _getch();
        if (znak == 72)
            opcja--;
        else if (znak == 80)
            opcja++;
    }
    return znak;
}

void Menu::bruteMenu(int znak)
{
    if (opcja == 0 && znak == 13)
    {
        graph = DataReader::readFile(1);
    }
    else if (opcja == 1 && znak == 13)
    {
        graph->showMatrix();
    }
    else if (opcja == 2 && znak == 13)
    {
        mode = 0;
        opcja = 0;
    }
}

void Menu::mainMenu(int znak)
{
    if (opcja == 0 && znak == 13)
    {
        mode = 1;
        opcja = 0;
    }
    else if (opcja == 1 && znak == 13)
    {
        opcja = 2;
    }
}
