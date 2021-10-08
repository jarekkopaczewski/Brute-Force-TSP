#pragma once
class Graph
{
	public:
		Graph();
		Graph(int*);
		~Graph();
		void setMatrix(int**);				//ustawia macierz -> wykorzystywane przy wczytywaniu z pliku
		void showMatrix();					//wyswietlanie macierzy
		int** getGraphMatrix();				//zwraca macierz
		int getSize();						//zwraca wielkosc - ilo�� wierzcho�k�w
	private:
		int** matrix;						//macierz s�siedztwa
		int	edgeNumber;						//ilo�� kraw�dzi
		int vertexNumber;					//ilo�� wierzcho�k�w
		int firstVertex;					//pocz�tek drogi
		int lastVertex;						//koniec drogi
		void clearMatrix();					//usuwanie tablicy -> u�ywane przez destruktor
};