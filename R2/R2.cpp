#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct CarData
{
	string model;
	string make;
	string year;

	CarData(){}
	
	CarData(string ma, string mo, string y)
	{
		model=mo;
		make=ma;
		year=y;
	}
};

int main(int argc, char *argv[])
{
	CarData carArr[10];
	ifstream inFile;
	string data;
	inFile.open(argv[1]);
	ofstream outFile;
	outFile.open(argv[2]);
	if (inFile.is_open())
	{

		int count=0;
		cout<<"opened successfully"<<endl;
		while(getline(inFile, data))
		{
			//cout<<data<<endl;
			stringstream ss(data);
			//ss<<data;
			string line;
			getline(ss, line, ' ');
			carArr[count].make=line;
			getline(ss, line, ' ');
			carArr[count].model=line;
			getline(ss, line, ' ');
			carArr[count].year=line;

			
			outFile<<"make: "<<carArr[count].make<<" model: "<<carArr[count].model<<" year: "<<carArr[count].year<<endl;

			count++;
		}
		inFile.close();
		outFile.close();
	}

	else
	{
		cout<<"File unsuccessfully opened"<<endl;
	}
	
}




