// Nicole Richter
// Dr. Hoenigman
// CSCI 2270 Data Structures
// Assignment 3
// 2/11/18

#include <iostream>
#include <fstream>
using namespace std;

struct city{
	string cityName;
	string message;
	city *next;
	city(){}; //default constructor
	city(string c, city *n, string m)
	{
		cityName=c;
		next=n;
		message=m;
	}



	
};

city *buildNetwork()
{
	string cityArray[]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	city *head = new city(cityArray[0], NULL, "");
	for (int i=1; i<10; i++)
	{
		city *current = head;
		while(current->next !=NULL)
		{
			current=current->next;
		}
		current->next= new city(cityArray[i], NULL, "");
	}
	return head;
}

city *addCity(city *head, city *previous, string cityName)
{
	if(previous==NULL)
	{
		return new city(cityName, head, "");
	}
	else if(previous->next==NULL) //know you are at tail
	{
		previous->next = new city(cityName, NULL, "");
		return head; 
	}
	else
	{
		city *current = new city(cityName, previous->next, ""); 
		previous->next=current;
		return head;
	}
}

void transmitMsg(city *head)
{
	if(head==NULL)
	{
		cout<<"Empty list"<<endl;
	}
	else
	{
		string filename = "messageIn.txt";
		string message;
		city *tmp;
		ifstream myfile;
		myfile.open(filename);
		if(myfile.is_open())
		{
			while(myfile>>message)
			{
				tmp=head;
				while(tmp!=NULL)
				{
					tmp->message=message;
					cout<<tmp->cityName<<" received "<<tmp->message<<endl;
					tmp->message="";
					tmp=tmp->next;
				}
			}
			myfile.close();
		}
		else
		{
			cout<<"Error opening file"<<endl;
		}
	}
}

void printPath(city *head)
{
	city *tmp=head;
	cout<<"===CURRENT PATH==="<<endl;
	while(tmp!=NULL)
	{
		cout<<tmp->cityName<<" -> ";
		tmp=tmp->next;
	}
	cout<<" NULL"<<endl;
	cout<<"=================="<<endl;
}

void *search(string value, city *head)
{
	city *current = head;
	while(current!=NULL)
	{
		if(current->cityName==value)
		{
			return current;
		}
		current=current->next;
	}
	return NULL;
}

int main()
{
	city *head, *temp;
	string prevCity, newCity, menu_choice;
	while(menu_choice!="5")
	{
		cout<<"======MAIN MENU======"<<endl;
		cout<<"1. Build Network\n"<<"2. Print Network Path\n"<<"3. Transmit Message Coast to Coast\n"<<"4. Add City\n"<<"5. Quit"<<endl;
		getline(cin, menu_choice);
		if(menu_choice=="1")
		{
			head=buildNetwork();
		}
		else if(menu_choice=="2")
		{
			printPath(head);
		}
		else if(menu_choice=="3")
		{
			transmitMsg(head);
		}
		else if(menu_choice=="4")
		{
			cout<<"Enter a city name: "<<endl;
			getline(cin, newCity);
			cout<<"Enter a previous city name"<<endl;
			getline(cin, prevCity);
			temp=head;
			while(temp!=NULL)
			{
				if(prevCity==temp->cityName)
				{
					break;
				}
				temp=temp->next;
			}
			addCity(head, temp, newCity);
		}
	}
	if(menu_choice=="5")
		cout<<"Goodbye"<<endl;
}