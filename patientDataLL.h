
#include <iostream>
#include <vector>
// #include "STL_library.h"
using namespace std;

#ifndef PATIENTDATALL_H
#define PATIENTDATALL_H

struct Node
{
	string name;
	int priority;
	int treatment;
	Node* next=NULL;
	
};

struct patient
{
	string N;
	int P, T;
	//patient();
	patient(string initName, int initPriority, int initTreatment)
	{
		N=initName;
		P=initPriority;
		T=initTreatment;
	}
};

class PatientLL
{
	public:
		vector<patient> readFile(string);
		void buildLL(vector<patient>);
		void printLL();
		Node* dequeue();
		void deleteLL();
	protected:
	private:
		Node *head=NULL;
		
};

#endif 
