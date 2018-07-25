#include <iostream>
using namespace std;

// Stacks and Queues
// data structures that restrict which elements can be accessed
// at a given time. Array or linked list implementation

//Stack- Last In First Out (LIFO)
	//stack of cafeteria plates
	//push(value)- addd to stack
	//pop()- remove from stack
//Queue- First In First Out(FIFO)
	//Line at the grocery store
	//Enqueue(value)- add to queue
	//Dequeue()- remove from queue
	//Enq. at the tail
	//Deq. at the head
//Array-based implementation of a stack
	//position where element is added is called the top
	//pop, push to top of the stack
	//data[0...top-1] are contents of the stack
	//when top=1, stack is empty
	//when top=maxsize, the stack is full
	//when top>maxsize, called stack overflow, error
//Linked list implementation of a stack
	//when top=NULL, stack is empty

//Stack
	//private:
		//top
		//data
		//maxsize
	//public:
		//Stack()
		//isFull()
		//isEmpty()
		//push(value)
		//pop()
//push(value)
//{
	//if(!isFull())
	//{
		//data[top]=value
		//top++
	//}
//}

//pop()
//{
	//top-- //moves back to where valid data is
	//return data[top]
//}

//Queue(array implementation)
//Given a sentence, add words to the queue
//A liger its pretty much my favorite animal
//with every enqueue, move the tail over
//dequeue at the head
//deq() returns "A"
//shift everything over by 1, leave head in the same spot (expensive)
//move the head(better), now head is pointing at liger
//deq() returns "liger"
//Circular Array Queue
	//head and tail can wrap around to beginning of the array with dequeue and enqueue
	//produces circular queue since tail can also move
	//efficient, no shifting, trickier to implement






int main()
{

}