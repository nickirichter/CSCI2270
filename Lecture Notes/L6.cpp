#include <iostream>
using namespace std;

struct node
{
	int key; //data
	node *next; //pointer to another node
	node (int k, node *n)
{
		key=k;
		next=n;
	}
};



int main()
{
	node *x=new node(5, NULL);
	//print the key
	cout<<x->key<<endl; //same as (*x).key, dereferencing x and getting key value

	node *x2= new node(6, NULL);
	x->next=x2;
	cout<<x2<<endl;
	cout<<x->next<<endl;

	x2->key=10;
	cout<<x->next->key<<endl; //go to x, go to address xnext is pointing to, then get key value
}