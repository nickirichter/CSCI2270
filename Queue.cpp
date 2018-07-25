/*
Nicole Richter
Assignment 5
Dr. Rhonda Hoenigman
CSCI 2270
*/
#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

Queue::Queue(int qs)
{
	// Setting the queueHead and queueTail to 0 initializes the index in the arrayQueue for
	// the head and tail positions.
	queueSize = qs;
	arrayQueue = new std::string[queueSize];
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
}

Queue::~Queue()
{
	delete[] arrayQueue;
	arrayQueue=nullptr; 
}

//Insert a new word into the circular queue, print out the added word and the index 
void Queue::enqueue(string word)
{
	if(!queueIsFull())
	{
		arrayQueue[queueTail]=word;
		queueTail++;
		if(queueTail==queueSize)
		{
			queueTail=queueTail%queueSize;
		}
		if(queueCount<queueSize)
		{
			queueCount++;
		}
		cout<<"E: "<<word<<endl;
		cout<<"H: "<<queueHead<<endl;
		cout<<"T: "<<queueTail<<endl; 
	}
	else
	{
		cout << "Queue is full." << endl; 
	}
}

// Perform the dequeue operation on the circular queue and print out the indices of
// the head and tail positions. Also print the word that was dequeued. If the queue is
// empty, print "Queue is empty."
void Queue::dequeue()
{
	if(queueIsEmpty() && queueCount==0)
	{
		cout << "Queue is empty" << endl; 
	}
	else
	{
	    if (queueHead != queueTail || queueCount != 0)
	    {
	        cout<<"H: "<<(queueHead+1)%queueSize<<endl;
    		cout<<"T: "<<queueTail<<endl;
    		cout<<"word: "<<arrayQueue[queueHead]<<endl;
	        
	        queueHead++;
	        if(queueHead==queueSize)
		    {
			    queueHead=queueHead%queueSize; //checks index of head, if we reach the end of array, we wrap to beginning of array
		    }
    		
    		queueCount--;
	    }
	    else
	    {
	        queueTail=queueHead=0;
	    }
	    
	}
	
}

// Print all of the elements in the queue in the specified format from Appendix A. If
// the queue is empty print “Empty”.
void Queue::printQueue()
{
    if(queueIsFull())
	{
		for(int i=queueTail; i<queueSize; i++)
		{
			cout<<i<<": "<<arrayQueue[i]<<endl;
		}
		for(int j=0; j<queueTail; j++)
		{
		    cout<<j<<": "<<arrayQueue[j]<<endl;
		}
	}
	else if(!queueIsEmpty())
	{
	    while(queueHead!=queueTail)
	    {
	        cout<<queueHead<<": "<<arrayQueue[queueHead]<<endl;
	        queueHead++;
	    }
	}
	else
		cout<<"Empty"<<endl;
}

void Queue::enqueueSentence(string input)
{
    stringstream ss;
    ss<<input;
    string item;
    while(getline(ss, item, ' '))
    {
        enqueue(item);
    }
}


// Returns true of false whether or not the queue is full
bool Queue::queueIsFull()
{
	if (queueCount == queueSize) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


// Returns true or false whether or not the queue is empty
bool Queue::queueIsEmpty()
{
	if (queueHead == 0 && queueTail == 0 && queueCount==0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}




