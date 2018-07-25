/*
Nicole Richter
Rectitation 103- Shayon Gupta
CS2270 Data Structures
Dr. Rhonda Hoenigman
*/

#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;
	//cout<<nodeID<<endl;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	//cout<<nodeID<<endl;
	return true;

}

Node* doublyLL::search(int value, Node *head)
{
	Node *current = head;
	while(current!=NULL)
	{
		if(current->id==value)
		{
			return current;
		}
		current=current->next;
	}
	return NULL;
}

bool doublyLL::ToF(int value, Node* head) //checks to see if the value matches the current id
{
	Node* current = head;
	while(current!=NULL)
	{
		if(current->id==value)
		{
			return true;
		}
		current=current->next;
	}
	return false;
}

void doublyLL::deleteNode(int value)
{
	Node* current=head;
	while(ToF(value,current)==true)
	{
		Node* searching=search(value, current);
		if(searching==head)
		{
			head=head->next;
			head->prev=NULL;
			delete searching;
		}
		else
		{
			if(searching==tail)
			{
				tail=tail->prev;
				tail->next=NULL;
				delete searching;
			}
			else
			{
				searching->prev->next=searching->next;
				searching->next->prev=searching->prev;
				delete searching;
			}
		}
	}
}

void doublyLL::printPath() 
{
	Node* temp = head;
	while(temp != NULL) 
	{
		cout << temp->id << " -> ";
		temp = temp->next;
	}
	cout<<endl<<endl;
}







