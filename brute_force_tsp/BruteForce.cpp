#include "BruteForce.h"
#include "Graph.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

BruteForce::BruteForce(Graph* graph)
{
    this->size = graph->getSize();
    this->matrix = graph->getGraphMatrix();
}

BruteForce::~BruteForce()
{
}

int BruteForce::findSolution()
{
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

    while (next_permutation(nodes.begin(), nodes.end()))
    {
        int path_weight = 0;
        int j = source;
        for (int i = 0; i < n; i++)
        {
            //cout << j;
            path_weight += matrix[j][nodes[i]];
            j = nodes[i];
        }
        path_weight += matrix[j][source];
        shortest_path = min(shortest_path, path_weight);
    }
    return shortest_path;
} 