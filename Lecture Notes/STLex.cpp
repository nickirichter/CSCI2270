#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue> //priority queue lives here
using namespace std;

struct patient{
	string name;
	int priority, treatment;
	patient();
	patient(string initName, int initPriority, int initTreatment)
	{
		name=initName;
		priority=initPriority;
		treatment=initTreatment;
	}
};
struct compare{
	bool operator()(const patient &a, const patient &b){
		return a.priority>b.priority;
	}
};

int main(int argc, char* argv[])
{
	//create few patient objects
	//how do I compare p1.x and p3.x
	string line, curName, curPri, curTre;
	int priority, treatment, menu_choice;
	//patient P;
	ifstream myfile;
	myfile.open(argv[1]);
	vector<patient> patients;
	priority_queue<patient, vector<patient>, compare > pq;
	
	
	if(myfile.is_open())
	{
		getline(myfile, line);
		while(getline(myfile, line, '\r'))
		{
			patient P;
			stringstream ss;
			ss<<line;
			getline(ss, curName, ',');
			P.name=curName;
			getline(ss, curPri, ',');
			P.priority=stoi(curPri);
			getline(ss, curTre, '\r');
			P.treatment=stoi(curTre);
			patients.push_back(P);
			//pq.push(curName, priority, treatment);
		}
		// return patients;
	}
	else
	{
		cout<<"error opening file"<<endl;
	}
	myfile.close();
	for(int i=0; patients.size(); i++)
	{
		pq.push(patients[i]);
	}
	
	while(!pq.empty())
	{
		patient p=pq.top();
		cout<<p.name<<"-"<<p.priority<<"-"<<p.treatment<<endl;
		pq.pop();
	}
}

