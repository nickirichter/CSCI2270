//Jan. 24 2018
//Number Bases and Pointers

#include <iostream>
using namespace std;

void passByvalue(int a)
{
	a++;
}
void passBypointer(int *ptr)
{
	cout<<ptr<<" address stored in ptr"<<endl; 
	*ptr=*ptr+1;
}
void passByReference(int &a)
{
	//input is reference/address of a
	a++;
}
void passByArray(int *a) //could also define using passByArray(a[])
{
	a[0]=10;
	a[1]=11;
}

int main()
{
	
	int a=5; //regular variable
	//cout<<&a<<endl;

	int *b=&a; //b is pointer to memory address of a
	//cout<<&b<<", "<<b<<", "<<*b<<endl; //print what is stored in b
	//*b=dereference operator- go to b, get address stored in b
	//then get value is stored at the address b is pointing to
	//* used to declare pointers, also used for dereferencing the pointer
	//& means address of
	//pointer and address it points to have to be same type

	a=10;
	//what is value of *b?
	//cout<<&b<<", "<<b<<", "<<*b<<endl; //print what is stored in b, by dereferencing b, get new value of a

	int c=20;
	b=&c; //change address stored in b to the address of c
	//b now points to c
	//cout<<*b<<", "<<endl; //prints 20

	int arrayA[5];
	//cout<<arrayA<<endl; //address of first element of array A

	//functions
	passByvalue(a); //makes copy of variable
	//cout<<a<<endl; //prints 10, a unchanged
	//cout<<b<<" address stored in b"<<endl;
	passBypointer(b); //updates the value at the address stored in b
	cout<<*b<<endl;
/*
	//pass by reference
	passByReference(a); //is regular variable, NOT pointer
	cout<<a<<endl;

	for(int i=0; i<5; i++)
	{
		arrayA[i]=0;
	}

	passByArray(arrayA);
	for(int i=0; i<5; i++)
	{
		cout<<arrayA[i]<<endl;
	}

	//Stack: finite amount of memory used to control program execution
		//local variables are stored here
		//Pros:fast, memory management done for you
		//Cons: relatively small, allocating large amounts of memory during execution can crash stack

	//Heap: large pool of memory (much larger than stack)
		//for large data structures that we want to allocate during run time
		//use dynamic memory allocation

	//dynamically allocate an array
	//new used to allocate memory on the heap
	//must use pointer to access heap memory 
	//y is pointer to array of 10 ints (y is stack variable pointing to array on heap)
	int *y = new int[10];
	double *x= new double[20]; //array of 20 doubles
	//for every new we need to have a delete
	delete y; //frees memory allocated to y
	delete x; //frees memory allocated to x

	int *x2= new int;
	*x2=5;
	y=x2; //y now points to same address as x2
	cout<<*y<<endl;
	//x=x2; //doesn't work because double can't point to an integer (must be same type)

	//program can slow down
	int *x3=new int[100]; //x3 points to array of 100 ints
	x3[0]=100;
	x3[10]=200;
	x3=x2;
	//how do I get data out of x3?
	//I can't get back to x3 because it now points to same address of x2
	//array of 100 ints in memory that can't be accessed
	//memory leak


*/

















}







