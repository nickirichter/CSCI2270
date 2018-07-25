
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "patientDataLL.cpp"

int main()
{
	PatientLL LL;
	LL.buildLL(LL.readFile("patientData2270.csv"));
	// ofstream outfile;
	// outfile.open("Final.csv");
	// clock_t t1, t2;
	// int x;
	// while(x<500)
	// {
	// 	t1=clock();
	// 	LL.buildLL(LL.readFile("patientData2270.csv"));
	// 	t2=clock();
	// 	outfile<<(float(t2) - float(t1))/ CLOCKS_PER_SEC<<endl;
	// 	x++;
	// }
	LL.printLL();
	LL.dequeue();
	LL.deleteLL();
	LL.printLL();
}
	
