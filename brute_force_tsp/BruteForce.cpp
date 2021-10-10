#include "BruteForce.h"
#include "Graph.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

int BruteForce::findSolution(Graph* graph)
{
    int size = graph->getSize();
    int** matrix = graph->getGraphMatrix();
    int source = 0;
    vector<int> nodes;
    for (int i = 0; i < size; i++)
    {
        if (i != source)
        {
            nodes.push_back(i);
        }
    }
    int n = nodes.size();
    int shortest_path = INT_MAX;

    do
    {
        int path_weight = 0;
        int j = source;
        for (int i = 0; i < n; i++)
        {
            path_weight += matrix[j][nodes[i]];
            j = nodes[i];
        }
        path_weight += matrix[j][source];
        shortest_path = min(shortest_path, path_weight);
    }while (next_permutation(nodes.begin(), nodes.end()));

    return shortest_path;
} 