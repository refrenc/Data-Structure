#pragma once
#include <iostream>

using namespace std;

class Node {
	friend class LinkedList;
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(int data);
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public :
	LinkedList();
	void Append(int data);
	void Prepend(int data);
	int Length();
	void Print();
	void PrintReverse();
};