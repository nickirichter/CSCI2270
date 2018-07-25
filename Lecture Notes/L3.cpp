#include <iostream>

//command line arguments are args to main function
//which runs when the program runs
//argc is number of arguments
//*argv is an array of pointers to the arguments
int main(int argc, char *argv[]){
	std::cout<<"hello world"<<std::endl;
	
	std::cout<<argc<<std::endl;
	//argv[0] is name of program running
	std::cout<<argv[0]<<std::endl;

	//std::cout<<argv[1]<<std::endl;
	//loop through arguments
	//don't have to know how many arguments because set with argc parameter
	for (int i =0; i<argc; i++)
	{
		std::cout<<argv[i]<<std::endl; //*(argv+i) is equivalent to argv[i]
	}
}