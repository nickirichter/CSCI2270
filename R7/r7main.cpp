#include <iostream>
using namespace std;
#include "BST.h"

int main()
{
	BST b(8);
	b.insertNode(12);
	b.insertNode(3);
	b.insertNode(14);
	b.insertNode(7);
	
	b.searchKey(7);
	b.printTree();	
}