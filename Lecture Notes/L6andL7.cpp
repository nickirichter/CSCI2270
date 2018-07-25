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

node *search(int value, node *head)
{
	node *current=head;
	while(current!=NULL)
	{
		if(current->key==value)
			return current;
		current=current->next;
	}
	return NULL;
}


int main()
{
	// node *x=new node(5, NULL);
	// //print the key
	// cout<<x->key<<endl; //same as (*x).key, dereferencing x and getting key value

	// node *x2= new node(6, NULL);
	// x->next=x2;
	// cout<<x2<<endl;
	// cout<<x->next<<endl;

	// x2->key=10;
	// //cout<<x->next->key<<endl; //go to x, go to address xnext is pointing to, then get key value
	// //rather than an index, linked lists use pointers
	// //node *p=x;
	int i=1;
	node *head= new node(i, NULL);
	node *p= head; //head and p point to same memory
	i++;
	while (i<=10)
	{
		node *n= new node(i, NULL); //n->next=NULL, n->key=i
		p->next=n; //sets p's next node to point to n
		p=n;
		i++;
	}
	p=head; //go back to beginning of list
	while(p!=NULL)
	{
		//how to find something in the list?
	//do any of the key values=4?
		//modify to only print if a 4 is found
		if(p->key==4)
			cout<<p->key<<endl;
		p=p->next;
	}
	
	p=search(17, head);
	if(p!=NULL)
		cout<<"Found it"<<endl;
	else
		cout<<"Not in List"<<endl;

}









