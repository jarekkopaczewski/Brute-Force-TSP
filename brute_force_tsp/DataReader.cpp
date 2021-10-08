#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DataReader.h"
#include <conio.h>
using namespace std;

DataReader::DataReader()
{
}

DataReader::~DataReader()
{
}

Graph* DataReader::readFile()                                                               // typ definiuje rodzaj grafu (nie)skierowany
{
    Graph* graph = new Graph();
    int initialTab[4];                                                                      // tablica reprezentuje 4 parametry pliku
    int z = 0;
    int p,k,w;                                                                              // kolejne informacje o wczytywanej krawêdzi
    string fileName = readName();
    fileName = fileName + ".txt";

    fstream fileData;
    fileData.open(fileName, fstream::in);

    if (fileData.good())
    {
        fileData >> initialTab[0] >> initialTab[1] >> initialTab[2] >> initialTab[3];       // wczytywanie 4 pierwszych liczb które s¹ parametrami
        graph = new Graph(initialTab);                                                      // tworzenie grafu o zadanych parametrach

        int** tab = new int*[initialTab[1]];
        for (int i = 0; i < initialTab[1]; i++)                                             // utworzenie tablicy reprezentuj¹cej macierz
        {
            tab[i] = new int[initialTab[1]]{ NULL };
            fill_n(tab[i], initialTab[1], numeric_limits<int>::max());                      // maksymalna wartoœæ int reprezentuje nieskonczonoœæ
        }

        while (z < initialTab[0])                                                           // wczytywanie iloœæ wierzcho³ków zadan¹ w pliku
        {
            fileData >> p >> k >> w;
            tab[p][k] = w;
            tab[k][p] = w;
            z++;
        }

        graph->setMatrix(tab);                                                              // ustawienie wczytanej macierzy w grafie
        cout << "Plik zostal wczytany." << endl;
        cout << "\nWcisnij dowolny klawisz..." << endl;
        int znak = _getch();
    }
    else
    {
        cout << "Blad pliku!" << endl;
        cout << "Plik nie zostal wczytany." << endl;
        cout << "\nWcisnij dowolny klawisz..." << endl;
        int znak = _getch();
    }
    fileData.close();
    return graph;
}

string DataReader::readName()
{
    string temp;
    do
    {
        cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane:" << endl;
        cin >> temp;

        if (sizeof(temp) == 0)
        {
            cout << "Nazwa pliku nie moze byc pusta!" << endl;
        }

    } while (sizeof(temp) == 0);
    return temp;
}
