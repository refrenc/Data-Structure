#include "list.h"

Node::Node(int data) : data(data) {
	this->next = NULL;
	this->prev = NULL;
}

LinkedList::LinkedList() {
	this->head = NULL;
	this->tail = NULL;
}

void LinkedList::Append(int data) {
	Node* temp = new Node(data);

	if (this->tail == NULL) {
		this->head = temp;
		this->tail = temp;
	}
	else {
		this->tail->next = temp;
		temp->prev = this->tail;
		this->tail = temp;
	}
}

void LinkedList::Prepend(int data) {
	Node* temp = new Node(data);
	
	if (this->head == NULL) {
		this->head = temp;
		this->tail = temp;
	}
	else {
		this->head->prev = temp;
		temp->next = this->head;
		this->head = temp;
	}
}

int LinkedList::Length() {
	int nodeNum = 0;
	Node* tempHead = this->head;
	while (tempHead->next != NULL) {
		tempHead = tempHead->next;
		nodeNum++;
	}

	return ++nodeNum;
}

void LinkedList::Print() {
	Node* tempHead = this->head;
	while (tempHead->next != NULL) {
		cout << tempHead->data << " ";
		tempHead = tempHead->next;
	}
	cout << tempHead->data << endl;
}

void LinkedList::PrintReverse() {
	Node* tempTail = this->tail;
	while (tempTail->prev != NULL) {
		cout << tempTail->data << " ";
		tempTail = tempTail->prev;
	}
	cout << tempTail->data << endl;
}