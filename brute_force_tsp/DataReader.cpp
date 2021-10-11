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

pair<string, int>* DataReader::readFileNames()
{
    int size = 0;
    int temp = 0;
    string temp2 = "";
    pair<string, int>* init = nullptr;

    std::string fileName = readName();
    fileName = fileName + ".txt";

    fstream fileData;
    fileData.open(fileName, fstream::in);

    if (fileData.good())
    {
        fileData >> temp2;
        fileData >> size;
        init = new pair<string, int>[size];
        init[0] = make_pair(temp2, size);

        for (int x = 1; x < size; x++)
        {
            temp = 0;
            temp2 = "";
            fileData >> temp2;
            fileData >> temp;
            init[x] = make_pair(temp2, temp);
            cout << init[x].first << ", " << init[x].second << endl;
        }
    }
    else
    {
        cout << "Blad pliku!" << endl;
        cout << "Plik nie zostal wczytany." << endl;
        cout << "\nWcisnij dowolny klawisz..." << endl;
        int znak = _getch();
        return nullptr;
    }

    fileData.close();
    return init;
}

string DataReader::readName()
{
    string temp;
    do
    {
        cout << "Nazwa pliku konfiguracyjnego: ";
        cin >> temp;

        if (sizeof(temp) == 0)
        {
            cout << "Nazwa pliku nie moze byc pusta!" << endl;
        }

    } while (sizeof(temp) == 0);
    return temp;
}
