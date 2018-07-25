// Nicole Richter
// Dr. Hoenigman
// CSCI 2270 Data Structures
// Rectitation 103

#include <iostream>
using namespace std;

struct Node
{
	int key; //data
	Node *next; //pointer to another node
	Node (int k, Node *n)
{
		key=k;
		next=n;
	}
};

Node *search(int value, Node *head)
{
	Node *current=head;
	while(current!=NULL)
	{
		if(current->key==value)
			return current;
		current=current->next;
	}
	return NULL;
}


Node insertNode(Node *previous, int value, Node *head) //previous=value of node before, value=new node, //head=beginning of list
{
	Node *left=search(value, head); //create new node
	Node *n=new Node(value, NULL);
	if(left==NULL)
	{
		//Previous not found, add at head
		n->next=head;
		head=n; //changes where the head was pointing to and moves it to new node
	}
	return *head;
}
void printPath(Node *head)
{
	Node *tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->key<<" -> ";
		tmp=tmp->next;
	}
}

int main()
{
	int i=1;
	Node *head= new Node(i, NULL);
	Node *p= head; //head and p point to same memory
	i++;
	p=head;
	while(p!=NULL)
	{
		if(p->key%2==0)
		{
			printPath(p);
		}
		p=p->next;
	}

}