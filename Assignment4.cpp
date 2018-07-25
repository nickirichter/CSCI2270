#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;

int main(int argc, char *argv[])
{
	City *head, *temp;
	string prevCity, newCity, removeCity, menu_choice;
	CommunicationNetwork mynetwork;
	while(menu_choice!="7")
	{
		cout<<"======Main Menu======"<<endl;
		cout<<"1. Build Network\n"<<"2. Print Network Path\n"<<"3. Transmit Message Coast-To-Coast-To-Coast\n"<<"4. Add City\n"<<"5. Delete City\n"<<
		"6. Clear Network\n"<<"7. Quit"<<endl;
		getline(cin, menu_choice);
		if(menu_choice=="1")
		{
			mynetwork.buildNetwork();
			mynetwork.printNetwork();
		}
		else if(menu_choice=="2")
		{
			mynetwork.printNetwork();
		}
		else if(menu_choice=="3")
		{
			mynetwork.transmitMsg("messageIn.txt");
		}
		else if(menu_choice=="4")
		{
			cout<<"Enter a city name: "<<endl;
			getline(cin, newCity);
			cout<<"Enter a previous city name: "<<endl;
			getline(cin, prevCity);
			temp=head;
			mynetwork.addCity(newCity, prevCity);
		}
		else if(menu_choice=="5")
		{
			cout<<"Enter a city name: "<<endl;
			getline(cin, removeCity);
			mynetwork.deleteCity(removeCity);
		}
		else if(menu_choice=="6")
		{
			mynetwork.deleteNetwork();
		}
	}
	if(menu_choice=="7")
		cout<<"Goodbye!"<<endl;
}