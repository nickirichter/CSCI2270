#include <iostream>
#include "SLL.h"
using namespace std;

int main()
{
	//these methods are public
	SLL llCoolList(10);
	llCoolList.insertNodeAtEnd(12);
	llCoolList.insertNodeAtEnd(13);
	llCoolList.insertNodeAtEnd(14);
	llCoolList.insertNodeAtEnd(15);
	llCoolList.insertNodeAtEnd(16);
	llCoolList.printList();




}