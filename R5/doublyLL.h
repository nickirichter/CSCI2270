/*
Nicole Richter
Rectitation 103- Shayon Gupta
CS2270 Data Structures
Dr. Rhonda Hoenigman
*/
#ifndef doublyLL_H
#define doublyLL_H



struct Node {
	int id=-1;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class doublyLL {
	private:
		Node* createNode(int,Node*,Node*);
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		bool insertNodeAtEnd(int);
		doublyLL();	//default constructor
		doublyLL(int);	//overloaded constructor
		~doublyLL();	//destructor
		Node* search(int, Node*);
		void deleteNode(int);
		void printPath();
		bool ToF(int, Node*);
};

#endif