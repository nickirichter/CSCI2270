#include <iostream>
#include <fstream> //file stream
#include <sstream>

struct Student
{
	//ID, name, major
	int ID;
	std::string name;
	std::string major;
	Student(){} //default constructor
	//constructor
	Student(int id, std::string n, std::string m)
	{
		ID=id;
		name=n;
		major=m;
	}
};


int main()
{
	std::cout<<"hello world"<<std::endl;
	//create instance of student called s
	Student s;
	s.ID=5; //setting ID property for Student s to 5
	s.name="Bob";
	s.major="skiing";
	Student s2(6, "jimmy", "swimming");
	std::cout<<s2.ID<<" "<<s2.name<<" "<<s2.major<<std::endl;

	//arrays
	int a[10]; //array of 10 ints called a
	for (int i=0; i<10; i++)
	{
		a[i]=i; //initialize a[i]=i
		std::cout<<a[i]<<std::endl;
	}
	//array of Students
	//this will be populated with file data
	Student allStudents[10];
	//read stream
	std::ifstream myfile("students.txt");
	if(myfile.is_open())
	{
		//read file
		std::string line;
		//getline(stream, string, delimiter)
		int counter=0;
		while(getline(myfile, line))
		{
			std::cout<<line<<std::endl;
			//string stream-include sstream, 
			std::stringstream ss;
			//write line string into stringstream 
			ss<<line;
			std::string item;
			getline(ss, item, ',');
			allStudents[counter].ID= stoi(item);
			//read name
			getline(ss, item, ',');
			allStudents[counter].name=item;
			//reads major
			getline(ss, item);
			allStudents[counter].major=item;

			counter++;

		}
	}
	else
	{
		std::cout<<"error"<<std::endl;
	}
	for(int i=0; i<10; i++)
	{
		std::cout<<allStudents[i].ID<<" "<<allStudents[i].name<<" "<<allStudents[i].major<<std::endl;
	}

}








