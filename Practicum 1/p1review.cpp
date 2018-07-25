//Practicum 1 Review
//Arrays Review
/*
Question 1
Write a C++ function that removes all products in the array of structs with price that matches with given argument
'target'.Each time an element is removed, the array should be shifted to fill the gap. The function should return 
the size of the array after removing the matches. 
*/
struct Product{
	string pname;
	int price;
};

int ShiftArray(Product arr[], int size, int target)
{
	for (int i=0; i<size; i++)
	{
		if(arr[i].price==target)
		{
		    for(int j=i; j<size-1; j++)
		    {
		        arr[j]=arr[j+1];
		        
		    }
		    size--;
		}
	}
	return size;
}
/*
Question 2
Write a C++ function that returns the most common repeating element in an array of structs. The function takes two 
arguments - the input array of structs and the size of the array, and returns the most common product name.
*/
struct Product{
	string pname;
	int price;

string commonRepeatingElement(Product arr[], int length)
{
    Product mostCommon;
    int bestcount=0;
    for(int i=0; i<length; i++)
    {
        Product myProduct=arr[i];
        int count=0;
        for(int j=i+1; j<length; j++)
        {
            Product testProduct=arr[j];
            if(myProduct.pname==testProduct.pname)
            {
                count++;
            }
        }
       if(count>bestcount)
      {
        best=count=count;
        mostCommon=myProduct;
      }
    }
    return mostCommon.pname;
}

/*
Question 3
Write a C++ function to copy all elements of an array to a new array, except for a specified value, and 
return the new array. 
*/
int *CopyArray(int array[], int length, int value)
{
    int *newArray = new int[length];
    int cur = 0;
    for(int i=0; i<length; i++)
    {
        if(!(array[i]==value))
        {
            newArray[cur]=array[i];
            cur++;
        }
    }
    return newArray;
}
/*
Question 4
Write a C++ function to find the second largest element in an array. The function takes two arguments - the 
input array and the size of the array, and returns the second largest element. 
*/
int secondLargest(int arr[], int size)
{
    bool sorted=false;
	while(!sorted)
	{
		sorted=true;
		for (int i=0; i<size; i++)
		{
			if(arr[i]<arr[i+1])
			{
				int temp1;
				temp1=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp1;
				sorted=false;		
			}
		}
	}
	return arr[1];
}

//Linked List Review
/*
Question 1
Write a function called findMax that prints the maximum value in a linked list. 
*/
struct Node{
   int key;
   Node *next;
   Node *previous;
   Node(int k, Node *n, Node *p){
       key = k;
       next = n;
       previous = p;
   }

};

class LinkedList{
private:
   Node *head;
   Node *search(int value);

public:
   LinkedList(){head = NULL;};
   void addNode(int value, int newVal);
   void printList()
   void findMax();
};

void findMax()
{
	Node* current=head;
	int max=0;
	while(current!=NULL)
	{
		if(max<current->key)
		{
			max=current->key;
		}
		current=current->next;
	}
	cout<<max<<endl;
}

/*
Question 2
Write a function that enqueues a node to a singly linked list
*/
struct node
{
    int value;
    node *next;
    int *prev;
};

class Queue
{
    public:
        Queue(node *, node *);
        virtual ~Queue();
        void enqueue(node *newNode); 
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;
};

void Queue::enqueue(node* newNode)
{
    if(head==NULL)
    {
        head=newNode;
        tail=head;
    }
    else
    {
        tail->next=newNode;
        newNode->next=NULL;
        tail=newNode;
    }
}

//Linked List Review Cont'd
/*
Question 1
Write a C++ function to delete nodes in a linked list. The function takes two arguments - the head of the linked list 
and the value to be deleted. It should delete all nodes which contain the value to be deleted. It should return the 
head of the linked list.
*/
node* DeleteNode(node* head, int value)
{
  node* current=head;
  while(current!=NULL)
  {
 
      if(current->value==value && current->next==NULL)
      {
          current->prev->next=NULL;
          delete current;
          current=NULL;
          current=head;
      }
      else if(current->value==value && current==head)
      {
          head=head->next;
          head->prev=NULL;
          delete current;
          current=NULL;
          current=head;
      }
      else if(current->value==value)
      {
        node* previous=current->prev;
        node* nxt=current->next;
        previous->next=nxt;
        nxt->prev=previous;
        
        delete current;
        current=NULL;
        current=head;
      }
      else
         current=current->next;
  }
  return head;
}

/*
Question 2
Write a function that dequeues a node from a singly linked list. 
*/
struct node

{

    int value;

    node *next;

};



class Queue

{

    public:

        Queue(node *, node *);

        virtual ~Queue();

        node* dequeue(); 

        void displayQueue();

    protected:

    private:

        node *head;

        node *tail;

};

node* Queue::dequeue()
{
    node* output_node=head;
    if(head==NULL)
    {
        head=NULL;
        tail=NULL;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->next;
        delete output_node;
    }
    return output_node;
}
















