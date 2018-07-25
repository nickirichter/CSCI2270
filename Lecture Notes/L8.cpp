#include <iostream>
using namespace std;

//create a class with 3 private members: month, day, year
class Date()
{
public:
	Date(int m, int d, int y) //constructor
	{
		month=m;
		day=d;
		year=y;
	}


	void printDate()
	{
		cout<<month<<" "<<day<<" "<<year<<endl;
	}
	void setMonth(int m)
	{
		if(m>0 and m<13)
		{
			month=m;
		}
		else
		{
			cout<<"month out of range"<<endl;
		}
	}

private:
	int month;
	int day;
	int year;
};

int main()
{
	sDate sd;
	sDate *sdd= new sDate;

	Date d(1, 1, 2017);
	d.printDate();





	
}