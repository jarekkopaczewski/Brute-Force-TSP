#include "Graph.h"
#include "DataReader.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

Graph::Graph()
{
	edgeNumber = 0;
	vertexNumber = 0;
	firstVertex = 0;
	lastVertex = 0;
	matrix = nullptr;
}

Graph::Graph(int* initialTab)																// konstruktor incializujący parametry
{
	this->edgeNumber = initialTab[0];
	this->vertexNumber = initialTab[1];
	this->firstVertex = initialTab[2];
	this->lastVertex = initialTab[3];
	matrix = nullptr;
}

Graph::~Graph()
{
	clearMatrix();
}

void Graph::setMatrix(int** matrix)															// wczytanie tablicy do grafu
{
	if (vertexNumber != 0) clearMatrix();
	this->matrix = matrix;
	for (int i = 0; i < vertexNumber; i++)
	{
		this -> matrix[i] = matrix[i];
	}
}

void Graph::showMatrix()																	// wyświetlanie tablicy
{
	cout << endl;
	cout << "\t\t\t\t\t    ";

	for (int k = 0; k < vertexNumber; k++)
	{
		cout << k << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < vertexNumber; i++)
	{
		cout << "\t\t\t\t\t";
		cout << i << "   ";
		for (int j = 0; j < vertexNumber; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			if(matrix[i][j] != 2147483647)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << matrix[i][j] << " ";
			}
			else
			{
				cout << "- ";
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\nWcisnij dowolny klawisz..." << endl;
	int znak = _getch();
}

int** Graph::getGraphMatrix()
{
	return matrix;
}

int Graph::getSize()
{
	return vertexNumber;
}

void Graph::clearMatrix()
{
	delete[] matrix;
}


