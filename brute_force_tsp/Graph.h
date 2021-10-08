#pragma once
class Graph
{
	public:
		Graph();
		Graph(int);
		~Graph();
		void setMatrix(int**);				//ustawia macierz -> wykorzystywane przy wczytywaniu z pliku
		void showMatrix();					//wyswietlanie macierzy
		int** getGraphMatrix();				//zwraca macierz
		int getSize();						//zwraca wielkosc - iloœæ wierzcho³ków
		void calcCords();					//oblicz macierz na podstawie wspó³rzêdnych punktów
	private:
		int** matrix;						//macierz s¹siedztwa
		int	edgeNumber;						//iloœæ krawêdzi
		int vertexNumber;
		void clearMatrix();					//usuwanie tablicy -> u¿ywane przez destruktor
};