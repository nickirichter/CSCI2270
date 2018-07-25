/*
Nicole Richter
Assignment 1
Dr. Hoenigman
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Item
{
	string type;
	int price;
	int forsale;
	Item(){} //default constructor

	Item(string t, int p, int f) //passes in attributes of Item object
	{
		type=t;
		price=p;
		forsale=f;
	}
};

void deleteArrayElement(Item A[], int index, int numElements) //function to delete element
{
	for (int i=index; i<numElements; i++)
	{
		A[i]=A[i+1]; //moves index to account for deleted element
	}
}

void print_item_array(Item A[], int counter)
{
	string salestatus; //changes my forsale to string again for print statement
	for(int i=0; i<counter;i++)
	{
		if(A[i].forsale==0)
		{
			salestatus="for sale,";
		}
		else if(A[i].forsale==1)
		{
			salestatus="wanted,";
		}
		cout<<A[i].type<<", "<<salestatus<<" "<<A[i].price<<endl; //prints all items unmatched
	}
}

int check_match(int counter, Item newItem, Item itemArray[]) //function for checking matches
{
	for(int j=0; j<counter; j++) //counter is number of elements in array
	{
		//0 is for sale, 1 is wanted
		Item arrayItem=itemArray[j]; //saves variable as element in itemArray at j
		if(arrayItem.type==newItem.type) //compares array item with the new item type to determine match
		{
			if(arrayItem.forsale==0 and newItem.forsale==1) //then checks if array item is for sale and the compared item is wanted
			{
				if(arrayItem.price <= newItem.price) //confirms that the price of the item for sale is less than the price of wanted item
				{
					deleteArrayElement(itemArray, j, counter); //calls delete function
					counter--; //decrements counter to make up for deleted item in array
					cout<<arrayItem.type<<" "<<arrayItem.price<<endl; //prints the matched item type and price
					return counter; //returns counter to update the number of elements in array
				}
			}
			else if (arrayItem.forsale==1 and newItem.forsale==0) //checks opposite case where array item is wanted compared to new item for sale
			{
				if(arrayItem.price>=newItem.price) //mmakes sure price of array item wanted is greater than price of for sale item
				{
					deleteArrayElement(itemArray, j, counter); //calls delete function
					counter--;
					cout<<newItem.type<<" "<<newItem.price<<endl; //prints match
					return counter; 
				}
			}
		}
	}
	itemArray[counter++]=newItem; //stores new item in array, also increments counter
	return counter; //updates counter
}


int main(int argc, char *argv[])
{
	Item itemArray[100]; //declare item array
	ifstream myfile(argv[1]); //opens file with command line argument
	int counter=0; //counter variable for array elements number
	if(myfile.is_open()) //check if file is open
	{
		string line; //variable to store read-in lines
		while(getline(myfile, line)) //getline to read file
		{
			stringstream ss; //makes stringstream variable
			ss<<line; //stores read line in ss object
			string info; 
			Item newItem;
			getline(ss, info, ','); //reads ss until comma to get the type of the new item
			newItem.type=info; 
			
			getline(ss, info, ','); //continues reading to get the wanted vs for sale status
			int wanted=0; //new variable to store string "for sale" or "wanted" into integer 0 for for sale, 1 for wanted
			if (info==" for sale")
			{
				wanted=0;
			}
			if (info==" wanted")
			{
				wanted=1;
			}
			newItem.forsale=wanted; //after converting, stores wanted in forsale of new item 
			
			getline(ss, info); //final part of line for getting price
			newItem.price=stoi(info); //use stoi to convert string of numbers for price to actual integer

			counter=check_match(counter, newItem, itemArray); //sets counter (which is returned in check_match) and calls check_match function
		}
		cout<<'#'<<endl; //prints #
		print_item_array(itemArray, counter); //calls print function to print all remaining items in message board
		cout<<'#'; //final #
		myfile.close();
	}
	else
		cout<<"error opening file"<<endl; //handles if file was not opened correctly
}

