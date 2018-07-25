#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue> 
#include <stdlib.h>
#include <time.h>
using namespace std;


struct patient{
	string name;
	int priority, treatment;
	patient(string initName, int initPriority, int initTreatment)
	{
		name=initName;
		priority=initPriority;
		treatment=initTreatment;
	}
};

struct compare{
	bool operator()(const patient &a, const patient &b){
		if(a.priority==b.priority)
		{
			return(a.treatment>b.treatment);
		}
		else
		{
			return a.priority>b.priority;
		}
	}
};

void buildSTL(string filename)
{
	priority_queue <patient, vector<patient>, compare> pq;
	string line="";
	int priority, treatment;
	vector<patient> patients;
	int load=-1;
	ifstream in(filename);
	while(in>>line)
	{

		if(load>0)
		{
			string curName, curPri, curTre;
			stringstream ss;
			ss<<line;
			getline(ss, curName, ',');
			getline(ss, curPri, ',');
			getline(ss, curTre, ',');
			patient P(curName, stoi(curPri), stoi(curTre));
			pq.push(P);
		}
		load++;
	}
	while(!pq.empty())
	{
		patient p=pq.top();
		cout<<p.name<<"  "<<p.priority<<"  "<<p.treatment<<endl;
		pq.pop();
	}
}

int main()
{
	ofstream outfile;
	outfile.open("Final.csv");
	
	clock_t t1, t2;
	int x;
	while(x<500)
	{
		t1=clock();
		buildSTL("patientData2270.csv");
		t2=clock();
		outfile<<(float(t2) - float(t1))/ CLOCKS_PER_SEC<<endl;
		x++;
	}

	buildSTL("patientData2270.csv");
	return 0;
}

