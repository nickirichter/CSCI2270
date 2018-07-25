/*
Nicole Richter
Assignment 2
Dr. Rhonda Hoenigman
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct wordItem
{
	string word;
	int count;
	
};


void getStopWords(char *ignoreWordFilename, string ignoreWords[])
{
	ifstream inFile(ignoreWordFilename);
	int counter=0;
	string line;
	if(inFile.is_open())
	{	
		cout<<"success"<<endl;
		while(getline(inFile, line))
		{
			stringstream ss(line);
			ss >> ignoreWords[counter];
			//ignoreWords[counter]=line;
			//cout << ignoreWords[counter] << endl;
			counter++;
			//cout<<ignoreWords[counter]<<endl;
		}
		inFile.close();
	}
	else
	{
		cout<<"Error opening file"<<endl;
	}
}

bool isStopWord(string word, string ignoreWords[])
{
	for (int i=0; i<50; i++)
	{
		if (ignoreWords[i] == word)
		{
			//cout << word << endl;
			return true;
		}
	}	
	return false;
}

int getTotalNumberNonStopWords(wordItem list[], int length)
{
	int count=0;
	for (int i=0; i<length; i++)
	{
		count+=list[i].count;
	}
	return count;
}
void arraySort(wordItem list[], int length)
{
	bool sorted=false;
	while(!sorted)
	{
		sorted=true;
		for (int i=0; i<length; i++)
		{
			if(list[i].count<list[i+1].count)
			{
				int temp1;
				temp1=list[i].count;
				list[i].count=list[i+1].count;
				list[i+1].count=temp1;

				string temp2;
				temp2=list[i].word;
				list[i].word=list[i+1].word;
				list[i+1].word=temp2;
				sorted=false;		
			}

		}
	}
}
void printTopN(wordItem wordItemList[], int topN)
{
	for(int i=0; i<topN; i++)
	{
		cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
	}
}

int main(int argc, char *argv[])
{
	int timesdoubled=0;
	ifstream myfile(argv[2]);
	string line;
	int size=100;
	wordItem *currentArray= new wordItem[size];
	int counter = 0;

	string ignoreWords[50];
	getStopWords(argv[3], ignoreWords);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			stringstream ss;
			ss<<line;
			string item;
			while(getline(ss, item, ' '))
			{
				if(item.length()!=0)
				{
					if (!isStopWord(item, ignoreWords))
					{
						bool isfound=false;
						for (int i=0; i<counter; i++)
						{
							if(currentArray[i].word==item) //word in file is an instance of the wordItem word
							{
								currentArray[i].count++;
								isfound=true;
							}
						}
				
					if (counter==size)
					{
						int new_size= size * 2; //doubles size
						wordItem* newArray= new wordItem[new_size]; //creates new array with doubled size
						for (int i=0; i<size; i++)
						{
							newArray[i].word=currentArray[i].word; //copies contents of original array into new array
							newArray[i].count=currentArray[i].count;
						}
						delete[] currentArray; //delete memory associated with old array
						currentArray=newArray; //allows use of new array
						size=new_size; //pointer is now the new size (double original size)
						timesdoubled++;
					}
					if(isfound==false)
					{
						currentArray[counter].word=item;
						currentArray[counter].count=1;
						counter++;
					}
				}
			}
		}
	}
}

	else
	{
		cout<<"error opening file"<<endl;
	}

	arraySort(currentArray, counter);
	printTopN(currentArray, *argv[1]);
	
	cout<<'#'<<endl;
	cout<<"Array doubled: "<<timesdoubled<<endl;
	cout<<'#'<<endl;
	cout<<"Unique non-common words: "<<counter<<endl;
	cout<<'#'<<endl;
	cout<<"Total non-common words: "<<getTotalNumberNonStopWords(currentArray, counter)<<endl;	
}

