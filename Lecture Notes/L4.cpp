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

int main()
{
	
	int a=5; //regular variable
	cout<<&a<<endl;

	int *b=&a; //b is pointer to memory address of a
	cout<<&b<<", "<<b<<", "<<*b<<endl; //print what is stored in b
	//*b=dereference operator- go to b, get address stored in b
	//then get value is stored at the address b is pointing to
	//* used to declare pointers, also used for dereferencing the pointer
	//& means address of
	//pointer and address it points to have to be same type

	a=10;
	//what is value of *b?
	cout<<&b<<", "<<b<<", "<<*b<<endl; //print what is stored in b, by dereferencing b, get new value of a

	int c=20;
	b=&c; //change address stored in b to the address of c
	//b now points to c
	cout<<*b<<", "<<endl; //prints 20

	int arrayA[5];
	cout<<arrayA<<endl; //address of first element of array A

	//functions
	passByvalue(a); //makes copy of variable
	cout<<a<<endl; //prints 10, a unchanged
	cout<<b<<" address stored in b"<<endl;
	passBypointer(b); //updates the value at the address stored in b
	cout<<*b<<endl;





}
