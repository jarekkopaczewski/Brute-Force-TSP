#include "BruteForce.h"
#include "Graph.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int* BruteForce::findSolution(Graph* graph)
{
    int size = graph->getSize();
    int** matrix = graph->getGraphMatrix();
    int source = 0, shortest = INT_MAX, n = size - 1, iterations = -1;
    int* currentPath = new int[size+2];
    int* shortestPath = new int[size+2];
    vector<int> nodes;

    for (int i = 0; i < size; i++)                                  //lista wierzcho�k�w pomijaj�c startowy 
        if (i != source)
            nodes.push_back(i);
    do
    {
        int currentWeight = 0, j = source;
        currentPath[0] = j;
        for (int i = 0; i < n; i++)
        {
            currentWeight += matrix[j][nodes[i]];                   //dodanie wartosci aktualnego przemieszczenia
            j = nodes[i];                                           //
            currentPath[i+1] = j;
        }
        currentWeight += matrix[j][source];                         //dodanie warto�ci powrotu do pocz�tk
        if (currentWeight < shortest)
        {
            for (int z = 0; z < size; z++) shortestPath[z] = currentPath[z];
            shortest = currentWeight;                               //sprawdzenie czy obecna droga jest krotsza od najkrotszej 
        }
        iterations++;
    } while (next_permutation(nodes.begin(), nodes.end()));         //zwraca true je�eli mo�liwa jest leksykograficznie wi�ksza permutacja i false je�eli wr�cili�my do pocz�tku
    shortestPath[size+1] = shortest;
    shortestPath[size] = iterations;
    return shortestPath;
}
