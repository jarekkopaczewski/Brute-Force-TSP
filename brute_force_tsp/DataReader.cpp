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
    int z = 0;
    int size = 0;
    int x, y;                                                                              // kolejne informacje o wczytywanym punkcie
    string fileName = readName();
    fileName = fileName + ".txt";

    fstream fileData;
    fileData.open(fileName, fstream::in);

    if (fileData.good())
    {
        fileData >> size;
        graph = new Graph(initialTab);                                                      // tworzenie grafu o zadanych parametrach

        int** tab = new int*[initialTab[1]];
        for (int i = 0; i < initialTab[1]; i++)                                             // utworzenie tablicy reprezentującej macierz
        {
            tab[i] = new int[initialTab[1]]{ NULL };
            fill_n(tab[i], initialTab[1], numeric_limits<int>::max());                      // maksymalna wartość int reprezentuje nieskonczoność
        }

        while (z < initialTab[0])                                                           // wczytywanie ilość wierzchołków zadaną w pliku
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
