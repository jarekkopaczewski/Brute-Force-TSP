#include <windows.h>
#include <iostream>
#include "BruteForce.h"
#include "DataReader.h"
using namespace std;

int main(int argc, char** argv)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    Graph* graph = DataReader::readFile();
    graph->showMatrix();
    BruteForce* brute = new BruteForce(graph);
    cout << brute->findSolution();
    return 0;
}