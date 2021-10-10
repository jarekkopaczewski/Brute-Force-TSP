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
    int size = 0;
    string fileName = readName();
    fileName = fileName + ".txt";

    fstream fileData;
    fileData.open(fileName, fstream::in);

    if (fileData.good())
    {
        fileData >> size;
        graph = new Graph(size);                                                      // tworzenie grafu o zadanych parametrach
        int** tab = new int*[size];

        for (int i = 0; i < size; i++)
        {
            tab[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                fileData >> tab[i][j];
            }
        }
        graph->setMatrix(tab);                                                              // ustawienie wczytanej macierzy w grafie
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
