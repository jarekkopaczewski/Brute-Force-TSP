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
		int getSize();						//zwraca wielkosc - iloœæ wierzcho³ków
	private:
		int** matrix;						//macierz s¹siedztwa
		int	edgeNumber;						//iloœæ krawêdzi
		int vertexNumber;					//iloœæ wierzcho³ków
		int firstVertex;					//pocz¹tek drogi
		int lastVertex;						//koniec drogi
		void clearMatrix();					//usuwanie tablicy -> u¿ywane przez destruktor
};