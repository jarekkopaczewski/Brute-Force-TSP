#include <windows.h>
#include <iostream>
#include "BruteForce.h"
#include "DataReader.h"
#include "Test.h"
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
    /*Graph* graph = DataReader::readFile(nullptr);
    graph->showMatrix();*/
    Test::runTest();
    return 0;
}
