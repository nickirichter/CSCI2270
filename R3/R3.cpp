#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


void arrdouble(int* oldArray, int* size)
{
	int new_size= *size * 2;
	int* newArray= new int[new_size];
	for (int i=0; i<new_size; i++)
	{
		newArray[i]=oldArray[i];
	}
	oldArray=NULL;
	delete[] oldArray;
	oldArray=newArray;
	*size=new_size;
}

int main(int argc, char *argv[])
{
	ifstream inFile;
	string data;
	int count;
	inFile.open(argv[1]);
	int size=2;
	int* myArray= new int[size];
	int numOfElement=0;
	if (inFile.is_open())
	{
		cout<<"opened successfully"<<endl;
		while(getline(inFile, data))
		{
			myArray[count]=stoi(data);
			count++;
			numOfElement++;
			if(numOfElement>size)
			{
				arrdouble(myArray, &size);
			}
		}
	}
	for(int i=0; i<size; i++)
	{
		cout<<myArray[i]<<endl;
	}
}