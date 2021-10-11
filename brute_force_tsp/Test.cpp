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
    Graph* graph = new Graph();
    long long int frequency, start = 0, elapsed, result = 0, sum;
    int nmbrOfTests = 1;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    system("cls");

    pair<string, int>* initValues = DataReader::readFileNames();
    if (initValues == nullptr)
    {
        cout << "Program konczy prace." << endl;
        return;
    }
    int numberOfFiles = initValues[0].second;
    string outputName = initValues[0].first + ".csv";

    ofstream  outputFile;
    outputFile.open(outputName);

    outputFile << "Nazwa pliku,czas[ms],czas[s],ilosc testow\n";
    cout << "Rozpoczeto szukanie optymalnej drogi..." << endl;

    for (int k = 1; k < numberOfFiles; k++)
    {
        sum = 0;
        graph = DataReader::readFile(&(initValues[k].first));
        cout << endl << "================ " << initValues[k].first << " ================ " << endl;
        cout << "================ Liczba testow " << initValues[k].second << " ================ " << endl << endl;
        for (int i = 0; i < initValues[k].second; i++)
        {
            start = read_QPC();
            result = BruteForce::findSolution(graph);
            elapsed = read_QPC() - start;
            sum += elapsed;
        }
        cout << "Optymalna droga ma dlugosc: " << result << endl;
        cout << "Sredni czas operacji[us] = " << setprecision(3) << sum / 100.0 / float(nmbrOfTests) << endl;
        cout << "Sredni czas operacji[ms] = " << setprecision(3) << sum / 100.0 / 1000.0 / float(nmbrOfTests) << endl;
        cout << "Sredni czas operacji [s] = " << setprecision(3) << sum / 100.0 / 1000000.0 / float(nmbrOfTests) << endl << endl;
        outputFile << initValues[k].first << "," << sum / 100.0 / 1000.0 / float(nmbrOfTests) << "," << setprecision(3) << sum / 100.0 / 1000000.0 / float(nmbrOfTests) << "," << initValues[k].second << "\n";
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
