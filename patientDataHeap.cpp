
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <vector>
#include "patientDataHeap.h"

PQH::PQH()
{
	
}

PQH::~PQH()
{
	
}
vector<priorityItem> PQH::readFile(string filename)
{
	string line="";
	string name;
	int priority, treatment;
	vector<priorityItem> vecFile;
	int load=-1;
	ifstream inFile(filename);
	getline(inFile, line, '\r');
	while(getline(inFile, line, '\r'))
	{
		string curName, curPri, curTre;
		stringstream ss;
		ss<<line;
		getline(ss, curName, ',');
		getline(ss, curPri, ',');
		getline(ss, curTre, ',');
		priorityItem x(curName, stoi(curPri), stoi(curTre));
		vecFile.push_back(x);
	}
	return vecFile;
}

void PQH::enqueue(vector<priorityItem> heap)
{
	heap.push_back(x);
	int i = heap.size() - 1;
	while(i > 1)
	{
		if(heap[i].primaryPriority < heap[i/2].primaryPriority)
		{
			priorityItemHeap* temp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = temp;
		}
		else if(heap[i].primaryPriority == heap[i/2].primaryPriority)
		{
			if(heap[i].secondPriority < heap[i/2].secondPriority)
			{
				swap(heap[i], heap[i/2]);
			}
		}
		i = i/2;
	}
}

void PQH::dequeue()
{
	heap[1] = heap.back();
	heap.pop_back();
	int i = 1;
	while(i*2 < heap.size())
	{
		int larger = 2*i;
		if(2*i+1 < heap.size())
		{
			if(heap[2*i+1] < heap[2*i])
			{
				larger++;
			}
		}
		if(heap[i] > heap[larger])
		{
			priorityItem* temp = heap[i];
			heap[i] = heap[larger];
			heap[larger] = temp;
		}
	}
}
