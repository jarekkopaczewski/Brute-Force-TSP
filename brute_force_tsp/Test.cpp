#include "Test.h"
#include <windows.h>
#include <iostream>
#include "BruteForce.h"
#include "DataReader.h"
#include "Graph.h"
#include <iomanip>
#include <fstream>
using namespace std;

void Test::runTest()
{
    system("cls");
    Graph* graph = new Graph();
    long long int frequency, start = 0, elapsed, sum, size = 0;
    int* result = nullptr;
    int nmbrOfTests = 1;
    string path = "";
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    pair<int[3], string[2]>* initValues = DataReader::readFileNames();

    if (initValues == nullptr)
    {
        cout << "Program konczy prace." << endl;
        return;
    }

    int numberOfFiles = initValues[0].first[0];
    string outputName = initValues[0].second[0] + ".csv";

    ofstream  outputFile;
    outputFile.open(outputName);
    outputFile << "Nazwa pliku,czas[ms],czas[s],ilosc testow\n";
    cout << "Rozpoczeto szukanie optymalnej drogi..." << endl;

    for (int k = 1; k < numberOfFiles; k++)
    {
        sum = 0;
        path = "";
        graph = DataReader::readFile(&(initValues[k].second[0]));
        size = graph->getSize();
        graph->showMatrix();
        cout << endl << "================ " << initValues[k].second[0] << " ================ " << endl;
        cout << "================ Liczba testow " << initValues[k].first[0] << " ================ " << endl << endl;

        for (int i = 0; i < initValues[k].first[0]; i++)
        {
            start = read_QPC();
            result = BruteForce::findSolution(graph);
            elapsed = read_QPC() - start;
            sum += elapsed;
        }

        cout << "Optymalna droga ma dlugosc: " << result[size+1] << endl << "Ilosc iteracji: " << result[size] << endl << "Optymalna droga: ";
        for (int o = 0; o < size; o++) 
            path += to_string(result[o]) + "->";
        path += to_string(result[0]);
        cout << path << endl;
        cout << "Sredni czas operacji[us] = " << setprecision(3) << sum / 100.0 / float(initValues[k].first[0]) << endl;
        cout << "Sredni czas operacji[ms] = " << setprecision(3) << sum / 100.0 / 1000.0 / float(initValues[k].first[0]) << endl;
        cout << "Sredni czas operacji [s] = " << setprecision(3) << sum / 100.0 / 1000000.0 / float(initValues[k].first[0]) << endl << endl;
        outputFile << initValues[k].first << "," << sum / 100.0 / 1000.0 / float(initValues[k].first[0]) << "," << setprecision(3) << sum / 100.0 / 1000000.0 / float(initValues[k].first[0]) << "," << initValues[k].first[0] << ", " << path << "\n";
        if (initValues[k].first[1] == result[size + 1] && initValues[k].first[2] == result[size] && path == initValues[k].second[1])
            cout << "Rozwiazanie jest w pelni poprawne." << endl;
        else
            cout << "Rozwiazanie jest bledne." << endl;
        delete result;
    }
    outputFile.close();
    cout << "Wyniki zapisano do: " << outputName << endl << endl;
}

long long int Test::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}
