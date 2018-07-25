#include <iostream>
#include <fstream>
#include "CommunicationNetwork.h"
using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
	buildNetwork();
}

CommunicationNetwork::~CommunicationNetwork()
{
	deleteNetwork();
}

void CommunicationNetwork::buildNetwork()
{
	addCity("Los Angeles", "first");
	addCity("Phoenix", "Los Angeles");
	addCity("Denver", "Phoenix");
	addCity("Dallas", "Denver");
	addCity("St. Louis", "Dallas");
	addCity("Chicago", "St. Louis");
	addCity("Atlanta", "Chicago");
	addCity("Washington, D.C.", "Atlanta");
	addCity("New York", "Washington, D.C.");
	addCity("Boston", "New York");
	
}

void CommunicationNetwork::addCity(string newcityName, string previouscityName)
{
	City* newCity=new City(newcityName, NULL, NULL, "");
	City* current=head;
	if(head==NULL)
	{
		head=newCity;
		tail=newCity;
	}
	else
	{
		while(current!=NULL)
		{
			if(current->cityName==previouscityName)
			{
				break;
			}
			current=current->next;
		}
		if(previouscityName=="First")
		{
			newCity->next=head;
			head->previous=newCity;
			head=newCity;
		}
		else if(current==NULL)
		{
			newCity->previous=tail;
			tail->next=newCity;
			tail=newCity;
		}
		else if(current!=NULL)
		{
			newCity->next=current->next;
			current->next=newCity;
			newCity->next->previous=newCity;
			newCity->previous=current;
		}
		else if(previouscityName=="")
		{
			newCity->previous=tail;
			tail->next=newCity;
			tail=newCity;
		}
	}
	
}

void CommunicationNetwork::transmitMsg(char *filename)
{
	if(filename==NULL)
	{
		cout<<"Empty list"<<endl;
	}
	else
	{
		string message;
		City *tmp;
		City* temp;
		ifstream myfile;
		myfile.open(filename);
		if(myfile.is_open())
		{
			while(myfile>>message)
			{
				tmp=head;
				temp=tail->previous;
				while(tmp!=NULL)
				{
					tmp->message=message;
					cout<<tmp->cityName<<" received "<<tmp->message<<endl;
					tmp->message="";
					tmp=tmp->next;
				}
				while(temp!=NULL)
				{
					temp->message=message;
					cout<<temp->cityName<<" received "<<temp->message<<endl;
					temp=temp->previous;
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

void CommunicationNetwork::printNetwork()
{
	City* tmp=head;
	cout<<"===CURRENT PATH==="<<endl;
	while(tmp!=NULL)
	{
		cout<<"NULL<-"<<tmp->cityName<<" -> ";
		tmp=tmp->next;
	}
	cout<<" NULL"<<endl;
	cout<<"=================="<<endl;
}

void CommunicationNetwork::deleteCity(string removeCity)
{
	City* current=head;
	while(current!=NULL && removeCity!=current->cityName)
	{
		current=current->next;
	}
	if(current==NULL)
	{
		cout<<removeCity<<" not found"<<endl;
	}
	while(current!=NULL)
	{
		if(current->cityName==removeCity)
		{	
			if(current==head)
			{
				head=head->next;
				head->previous=NULL;
				delete current;
			}
			else
			{
				if(current==tail)
				{
					tail=tail->previous;
					tail->next=NULL;
					delete current;
				}
				else
				{
					current->previous->next=current->next;
					current->next->previous=current->previous;
					delete current;
				}
			}
		}
		current=current->next;
	}
}


void CommunicationNetwork::deleteNetwork()
{
	deleteCity("Los Angeles");
	cout<<"deleting Los Angeles"<<endl;
	deleteCity("Phoenix");
	cout<<"deleting Phoenix"<<endl;
	deleteCity("Denver");
	cout<<"deleting Denver"<<endl;
	deleteCity("Dallas");
	cout<<"deleting Dallas"<<endl;
	deleteCity("St. Louis");
	cout<<"deleting St. Louis"<<endl;
	deleteCity("Chicago");
	cout<<"deleting Chicago"<<endl;
	deleteCity("Atlanta");
	cout<<"deleting Atlanta"<<endl;
	deleteCity("Washington, D.C.");
	cout<<"deleting Washington, D.C."<<endl;
	deleteCity("New York");
	cout<<"deleting New York"<<endl;
	deleteCity("Boston");
	cout<<"deleting Boston"<<endl;
	head=NULL;
	
}







