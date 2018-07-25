
#include <iostream>
#include <vector>
using namespace std;

#ifndef PATIENTDATAHEAP_H
#define PATIENTDATAHEAP_H

struct priorityItem
{
	string name;
	int priority;
	int treatment;
	priorityItem(string initName, int initPriority, int initTreatment)
	{
		name=initName;
		priority=initPriority;
		treatment=initTreatment;
	}
};

class PQH
{
	public:
		PQH();
		~PQH();
		void readFile(string);
		void enqueue(priorityItem*);
		void dequeue();
		//string peek();
		void printPQ();
	private:
		int lastIndex = 0;
		int maxIndex = 900;
		priorityItem *heap;
};






#endif
