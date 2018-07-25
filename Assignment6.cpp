#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "MovieTree.hpp"

int main(int argc, char *argv[])
{
	MovieTree Movies;
	string line;
	char menu_choice;
	string ranking, quantity, year, title;
	int Ranking, Quantity, Year;
	ifstream myfile;
	myfile.open(argv[1]);
	if(myfile.is_open())
	{
		while(!myfile.eof())
		{
			getline(myfile, line);
			stringstream ss;
			ss<<line;
			getline(ss, ranking, ',' );
			Ranking=stoi(ranking);
			getline(ss, title, ',');
			getline(ss, year, ',');
			Year=stoi(year);
			getline(ss, quantity, '\n');
			Quantity=stoi(quantity);
			Movies.addMovieNode(Ranking, title, Year, Quantity);
		}
	}
	else
	{
		cout<<"error opening file"<<endl;
	}
	myfile.close();
	while(menu_choice!='6')
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Find a movie" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Print the inventory" << endl;
		cout << "4. Delete a movie" << endl;
		cout << "5. Count the movies" << endl;
		cout << "6. Quit" << endl;
		cin>>menu_choice;
		if(menu_choice=='1')
		{
			string title;
			cout<<"Enter title:"<<endl;
			cin.ignore();
			getline(cin, title);
			Movies.findMovie(title);
		}
		else if(menu_choice=='2')
		{
			string title;
			cout<<"Enter title: "<<endl;
			cin.ignore();
			getline(cin, title);
			Movies.rentMovie(title);
		}
		else if(menu_choice=='3')
		{
			Movies.printMovieInventory();
		}
		else if(menu_choice=='4')
		{
			string title;
			cout<<"Enter title: "<<endl;
			cin.ignore();
			getline(cin, title);
			Movies.deleteMovieNode(title);
		}
		else if(menu_choice=='5')
		{
			cout<<"Tree contains: "<<Movies.countMovieNodes()<<" movies."<<endl;
		}
	}
	if(menu_choice=='6')
	{
		//Movies.~Movies();
		cout<<"Goodbye!"<<endl;
	}
}