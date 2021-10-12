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
    int source = 0, shortestPath = INT_MAX, n = size - 1, iterations = -1;
    vector<int> nodes;

    for (int i = 0; i < size; i++)                              //lista wierzcho³ków pomijaj¹c startowy 
        if (i != source)
            nodes.push_back(i);
    do
    {
        int currentWeight = 0, j = source;
        for (int i = 0; i < n; i++)
        {
            currentWeight += matrix[j][nodes[i]];               //dodanie wartosci aktualnego przemieszczenia
            j = nodes[i];                                       //
        }
        currentWeight += matrix[j][source];                     //dodanie wartoœci powrotu do pocz¹tku
        shortestPath = min(shortestPath, currentWeight);        //sprawdzenie czy obecna droga jest krotsza od najkrotszej 
        iterations++;
    }while(next_permutation(nodes.begin(), nodes.end()));       //zwraca true je¿eli mo¿liwa jest leksykograficznie wiêksza permutacja i false je¿eli wróciliœmy do pocz¹tku
    return new int[2]{shortestPath, iterations};
} 