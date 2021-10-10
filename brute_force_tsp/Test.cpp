#include "Test.h"
#include <windows.h>
#include <iostream>
#include "BruteForce.h"
#include "DataReader.h"
#include "Graph.h"
#include <iomanip>
using namespace std;

void Test::runTest()
{
    Graph* graph = new Graph();
    long long int frequency, start = 0, elapsed, result = 0, sum;
    int nmbrOfTests = 1;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    system("cls");

    cout << "Podaj ilosc testow do sredniej: ";
    cin >> nmbrOfTests;

    string* fileNames = DataReader::readFileNames();
    int numberOfFiles = sizeof(fileNames)/2;

    cout << "Rozpoczeto szukanie optymalnej drogi..." << endl;

    for (int k = 0; k < numberOfFiles; k++)
    {
        sum = 0;
        graph = DataReader::readFile(&fileNames[k]);
        cout << "================ " << fileNames[k] << "================ " << endl << endl;
        for (int i = 0; i < nmbrOfTests; i++)
        {
            start = read_QPC();
            result = BruteForce::findSolution(graph);
            elapsed = read_QPC() - start;
            sum += elapsed;
        }
        cout << "Optymalna droga ma dlugosc:" << result << endl;
        cout << "Sredni czas operacji[us] = " << setprecision(3) << sum / 100.0 / float(nmbrOfTests) << endl;
        cout << "Sredni czas operacji[ms] = " << setprecision(3) << sum / 100.0 / 1000.0 / float(nmbrOfTests) << endl;
        cout << "Sredni czas operacji [s] = " << setprecision(3) << sum / 100.0 / 1000000.0 / float(nmbrOfTests) << endl << endl;
    }
}

long long int Test::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}
