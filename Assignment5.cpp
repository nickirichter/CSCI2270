/*
Nicole Richter
Assignment 5
Dr. Rhonda Hoenigman
CSCI 2270
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Queue.h"
using namespace std;

int main(int argc, char* argv[])
{
	Queue q(10);
	char menu;
	while(menu!='5')
	{
		cout<<"======Main Menu====="<<endl;
		cout<<"1. Enqueue word\n"<<"2. Dequeue word\n"<<"3. Print queue\n"<<"4. Enqueue sentence\n"<<"5. Quit"<<endl;
		cin>>menu;
		if(menu=='1')
		{
			string word;
			cout<<"word: ";
			cin.ignore();
			getline(cin, word);
			q.enqueue(word);
		}
		else if(menu=='2')
		{
			q.dequeue();
		}
		else if(menu=='3')
		{
			q.printQueue();
		}
		else if(menu=='4')
		{
			string sentence;
			cout<<"sentence: ";
			cin.ignore();
			getline(cin, sentence);
			q.enqueueSentence(sentence);
		}
	}
	if(menu=='5')
	{
		cout<<"Goodbye!"<<endl;
	}

}