#include <iostream>
#include "SLL.h"
using namespace std;

//implement what is used in header file

SLL::SLL()
{
	//default constructor
	//:: means in the scope of the class
}

SLL::SLL(int nodeID)
{
	//create head node
	head = new Node;
	head->next = nullptr;
	head->id=nodeID;

}
SLL::~SLL()
{
	//free memory associated with linked list
	if(head!=nullptr)
	{
		//cout<<"deleting"<<head->id<<endl;
		delete head;
	}
}
bool SLL::insertNodeAtEnd(int nodeID)
{
	//check if head is null, and if so, create a head node
	//if head is not null, add a new node at end of list
	Node *newNode = new Node;
	newNode->next = nullptr;
	newNode->id = nodeID;
	//coiuld use the tail pointer and set new node as tail->next
	//then, tail =new Node;
	if (head==nullptr)
	{
		head= new Node;
	}
	else
	{
		Node *current = head;
		while(current->next != nullptr) //traverse the list
		{
			current=current->next;

		}
		current->next= new Node;
	}
	return true;
	
}

void SLL::printList()
{
	Node *tmp=head; //won't enter while loop if list is empty
	while(tmp!= nullptr)
	{
		cout<<tmp->id<<endl;
		tmp=tmp->next;
	}
}




