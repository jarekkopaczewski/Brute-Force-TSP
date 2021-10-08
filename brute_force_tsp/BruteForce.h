#include "Graph.h"

class BruteForce
{
public:
    BruteForce(Graph* graph);
    virtual ~BruteForce();
    int findSolution();      //wczytuje nazwe pliku
private:
    int** matrix;						        //macierz s¹siedztwa
    int size;
};