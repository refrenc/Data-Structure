#pragma once
#include <iostream>

class Graph {
public:
	void LoadMatrix(std::string& filename);
	void PrintMatrix();
	int GetSize();
	int Choose(int size);
	void PrintShortestPathWeight(int s);
	void PrintShortestPath(int s);
private:
	int size;
	int** weight;
	int* dist;
	bool* check;
};
