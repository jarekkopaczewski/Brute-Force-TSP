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

Graph* DataReader::readFile(string* name)                                                               // typ definiuje rodzaj grafu (nie)skierowany
{
    Graph* graph = new Graph();
    int size = 0;
    std::string fileName = "";

    if (name == nullptr)
    {
        fileName = readName();
        fileName = fileName + ".txt";
    }
    else
    {
        fileName = *name + ".txt";
    }

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

std::string* DataReader::readFileNames()
{
    int size = 0;
    string* fileNames = nullptr;

    std::string fileName = readName();
    fileName = fileName + ".txt";

    fstream fileData;
    fileData.open(fileName, fstream::in);

    if (fileData.good())
    {
        fileData >> size;
        fileNames = new string[size];

        for(int x = 0; x < size; x++)
            fileData >> fileNames[x];
    }
    else
    {
        cout << "Blad pliku!" << endl;
        cout << "Plik nie zostal wczytany." << endl;
        cout << "\nWcisnij dowolny klawisz..." << endl;
        int znak = _getch();
    }

    fileData.close();
    return fileNames;
}

string DataReader::readName()
{
    string temp;
    do
    {
        cout << "Podaj nazwe pliku konfiguracyjnego z ktorego chcesz skorzystac: ";
        cin >> temp;

        if (sizeof(temp) == 0)
        {
            cout << "Nazwa pliku nie moze byc pusta!" << endl;
        }

    } while (sizeof(temp) == 0);
    return temp;
}
