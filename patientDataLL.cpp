#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
#include "patientDataLL.h"

vector<patient> PatientLL::readFile(string filename)
{
	string line="";
	string name;
	int priority, treatment;
	vector<patient> vecFile;
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
		patient x(curName, stoi(curPri), stoi(curTre));
		vecFile.push_back(x);
	}
	return vecFile;
}

void PatientLL::buildLL(vector<patient> vec)
{
	for(int i = 0; i<vec.size();i++)
	{
		if(head==NULL)
		{
			Node *start = new Node;
			start->name =vec[i].N;
			start->priority = vec[i].P;
			start->treatment = vec[i].T;
			start->next = NULL;
			head = start;
			//cout<<"TEST 1"<<endl;
		}
		else
		{
			Node *temp =head;
			Node *parent = temp;
			while(temp!=NULL)
			{
				if(vec[i].P > temp->priority)
				{
					parent = temp;
					temp = temp->next;
					//cout<<"TEST 2"<<endl;
				}
				else if(vec[i].P < temp->priority)
				{
					if(temp == head)
					{
						Node *insert = new Node;
						insert->name =vec[i].N;
						insert->priority = vec[i].P;
						insert->treatment = vec[i].T;
						insert->next = head;
						head = insert;
						break;
						//cout<<"TEST 3"<<endl;
					}
					Node *insert = new Node;
					insert->name =vec[i].N;
					insert->priority = vec[i].P;
					insert->treatment = vec[i].T;
					insert->next = temp;
					parent->next = insert;
					break;
					//cout<<"TEST 4"<<endl;

				}
				else if(vec[i].P == temp->priority)
				{
					if(vec[i].T < temp->treatment)
					{
						if( temp == head)
						{
							Node *insert = new Node;
							insert->name =vec[i].N;
							insert->priority = vec[i].P;
							insert->treatment = vec[i].T;
							insert->next = head;
							head = insert;
							break;
						}
						Node *insert = new Node;
						insert->name =vec[i].N;
						insert->priority = vec[i].P;
						insert->treatment = vec[i].T;
						insert->next = temp;
						parent -> next = insert;
						break;
					}
					else if(vec[i].T== temp->treatment)
					{
						if(temp == head)
						{
							Node *insert = new Node;
							insert->name =vec[i].N;
							insert->priority = vec[i].P;
							insert->treatment = vec[i].T;
							insert->next = head;
							head = insert;
							break;
						}
						Node *insert = new Node;
						insert->name =vec[i].N;
						insert->priority = vec[i].P;
						insert->treatment = vec[i].T;
						insert->next = temp;
						parent->next = insert;
						break;

					}
					else
					{
						parent = temp;
						temp = temp->next;
					}
				}
				if(temp == NULL)
				{
						Node *insert = new Node;
						insert->name =vec[i].N;
						insert->priority = vec[i].P;
						insert->treatment = vec[i].T;
						insert->next=NULL;
						parent ->next= insert;
						break;
				}
			}
		}
	}
}

void PatientLL::printLL()
{
	int rank=1;
	Node* tmp=head;
	if(tmp==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	while(tmp!=NULL)
	{
		cout<<rank<<":	"<<tmp->name<<",  "<<tmp->priority<<",  "<<tmp->treatment<<endl;
		rank++;
		tmp=tmp->next;
	}
}

Node* PatientLL::dequeue()
{
	if(head==NULL)
	{
		return NULL;
	}
	Node* temp=head;
	head=head->next;
	return head;
}

void PatientLL::deleteLL()
{
	cout<<"Deleting the list"<<endl;
	while(head!=NULL)
	{
		Node* temp=head;
		head=temp->next;
		temp=temp->next;	
	}
}

