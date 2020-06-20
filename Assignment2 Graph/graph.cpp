#include "graph.h"
#include <fstream>

void Graph::LoadMatrix(std::string& filename) {
	std::ifstream readFile;
	readFile.open(filename);
	
	/*사이즈 읽어오기*/
	int size;
	readFile >> size;
	this->size = size;

	/*새로 배정*/
	weight = new int* [size];
	check = new bool[size];
	dist = new int [size];

	/*weighted graph 입력*/
	for (int i = 0; i < size; i++) {
		weight[i] = new int[size];
		for (int j = 0; j < size; j++) {
			readFile >> weight[i][j];
		}
	}
}

void Graph::PrintMatrix() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << weight[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int Graph::GetSize() {
	return size;
}

int Graph::Choose(int s) {
	int selectedVertex;
	for (int i = 0; i < size; i++) {
		if (!check[i]) {
			selectedVertex = i;
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		if (dist[selectedVertex] > dist[i] && check[i] == false) {
			selectedVertex = i;
		}
	}

	return selectedVertex;
}

void Graph::PrintShortestPath(int s) {
	int* c = new int[size];
	/*초기화*/
	for (int i = 0; i < size; i++) {
		check[i] = false;
		dist[i] = weight[s][i];
	}
	check[s] = true;
	dist[s] = 0;

	/*경로 설정*/
	for (int i = 0; i < size - 2; i++) {
		int selectedVertex = Choose(s);		//정점 선정
		c[i] = selectedVertex;
		check[selectedVertex] = true;
		for (int w = 0; w < size; w++) {
			if (!check[w] && dist[selectedVertex] + weight[selectedVertex][w] < dist[w])
				dist[w] = dist[selectedVertex] + weight[selectedVertex][w];
		}
	}

	for (int i = 0; i < size; i++) {
		std::cout << dist[i] << std::endl;
	}
}

void Graph::PrintShortestPathWeight(int s) {
	int** path = new int* [size];

	/*초기화*/
	for (int i = 0; i < size; i++) {
		check[i] = false;
		dist[i] = weight[s][i];
	}
	check[s] = true;
	dist[s] = 0;
	for (int i = 0; i < size; i++) {
		path[i] = new int[size];
		for (int j = 0; j < size; j++) path[i][j] = -1;
		if (dist[i] != 999 && dist[i] != 0) {
			path[i][0] = s;
			path[i][1] = i;
		}
	}

	/*경로 설정*/
	for (int i = 0; i < size - 2; i++) {
		int selectedVertex = Choose(s);		//정점 선정
		check[selectedVertex] = true;
		for (int end, w = 0; w < size; w++) {
			if (!check[w] && dist[selectedVertex] + weight[selectedVertex][w] < dist[w]) {
				dist[w] = dist[selectedVertex] + weight[selectedVertex][w];
				for (int k = 0; k < size && path[w][k] != -1; k++) path[w][k] = -1;		//초기화
				for (int j = 0; j < size && path[selectedVertex][j] != -1; end = ++j) {
					path[w][j] = path[selectedVertex][j];		//정점 경로 복사
				}
				path[w][end] = w;								//경로 마지막에 추가
			}
		}
	}

	/*출력*/
	for (int i = 0; i < size; i++) {
		if (i == s) continue;
		for (int j = 0; path[i][j] != -1; j++) {
			std::cout << path[i][j] << " ";
		}
		std::cout << std::endl;
	}
}