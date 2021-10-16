#include <windows.h>
#include <iostream>
#include "BruteForce.h"
#include "DataReader.h"
#include "Test.h"
#include <conio.h>
using namespace std;

int main(int argc, char** argv)
{
    Test::runTest();
    cout << "\nWcisnij dowolny klawisz..." << endl;
    int znak = _getch();
    return 0;
}
