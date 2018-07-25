/*
Nicole Richter
Rectitation 103- Shayon Gupta
CS2270 Data Structures
Dr. Rhonda Hoenigman
*/
#include <iostream>
#include "doublyLL.cpp"
using namespace std;

int main()
{
	doublyLL numList(20);
	for(int i=0; i<19; i++)
	{
		if(i%4==0)
		{
			numList.insertNodeAtEnd(4);
		}
		else
		{
			numList.insertNodeAtEnd(i);
		}
	}

	numList.printPath();
	numList.deleteNode(4);
	numList.printPath();


}

