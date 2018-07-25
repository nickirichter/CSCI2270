#include <iostream>
using namespace std;

//Trees
//map of cities
//linked list is not sufficient complexity to capture the relationship between the nodes
//2 next pointers, one previous pointer
//binary tree: one parent. 0, 1, or 2 children
//general tree structure: one parent, 0...n children
//hierarchical structure
//Nodes in a binary tree
	//binary tree: each node has 0, 1, or 2 children, will have data, parent
	//each node has 3 pointers
		//parent node, left child node, right child node
		//pointers to nodes of the same type
	//pointers in LL
		//next, previous
	//pointers in binary tree
		//parent, left child, right child
//top of tree is known as the root
//know the root because root's parent is NULL
//left child and right child's parent is root of tree
//if a node doesn't have a left or right child, then that child is NULL
//know you are at the bottom of the tree when child points to NULL of that specific branch
//search tree until we reach bottom of tree on every branch

//Subtrees
//tree defined by subtrees
//subtree can have a root (different than root of entire tree) and left and right children
	//self-similarity: where an object is similar to a part of itself
//Computationally: can examine smaller and smaller pieces of tree (subtrees), starting at the root of the subtree
//Recursive structure: structure is defined in terms of itself
	//ex. tree defined by smaller subtrees
//Recursive algorithm: algorithm calls itself. typically called on smaller and smaller input until smallest case is reached

//Example:
//assume we have a tree
//traverse through tree and print nodes in binary tree

//void printNode(node* n)
	//cout<<n->key<<endl;
	// if(n->leftchild!=NULL)
	// {
		//printNode(n->leftchild);
	// }
	// if(n->rightchild!=NULL)
	// {
		 //printNode(n->rightchild);
	// }

//see pic of above algorithm on phone
//Rules of recursion:
	//Base case: smallest unit of the problem that can be defined, or a terminating scenario
		//algorithm exits without additional recursive calls once base case is reached
	//Rules to reduce all cases to the base case:
		//algorithm never exits if it never reaches the base case
//Binary search trees (BST)
	//special case of binary tree where data is ordered
	//noders left of parent have values less than parent
	//nodes right of parent have value >= parent value
	//tree is constructed as values are read. Same data in different order can generate diff. tree
	//as it's being constructed, add data to first available location that doesn't violate BST rules
//Example: build BST from 4, 2, 6, 9, 1, 3
	//Read 4 first, add 4 as the root
	//2<4 so 2 added as left child of 4
	//6>4 so 6 is added as right child of 4
	//start at 4; 9>4, so go to right child-> 9>6, so 9 is right child of 6
	//1<4, go to left child, 1<2 so 1 is left child of 2
	//3<4, go to 2, 3>2 so 3 is right child of 2
//Example: BST from words
	//DEN, LA, CHI, VEGAS, SD, DET, NY
	//DEN is root
	//look at ASCI values of first letter and compare to first letter of root
	//LA is right child of DEN
	//CHI is left child of DEN
	//VEGAS is right child of LA
	//SD is left child of VEGAS
	//DET is left child of LA
	//NY is left child of SD
//Why use a BST?
	//makes searching really fast
	//inventory system
	//order matters for the tree that's built
	//worst case: we build a linked list
//Operations on a BST
	//insert a new node
		//insert(value) value is the node info, data (not a pointer)
		//Node(key, parent, left child, right child)
		//Node* parent=NULL;
		//Node* temp=root; assuming root is a private pointer in class
		//Node* n=newNode(value, NULL, NULL, NULL)
		//while(temp!=NULL)
			//parent=temp;
			//if(n->key<temp->key) means we want to go to left child of temp
				//temp=temp->leftchild;
			//else
				//temp=temp->rightchild;
		//if(parent==NULL) true when tree is empty
			//root=n; 
		//else if(n->key<parent->key)
			//parent->leftchild=n
			//n->parent=parent
		//else
			//parent->rightchild=n
			//n->parent=parent
		//Example: add a 7 to the tree (root=5, leftchild=5, rightchild=15, 5's leftchild=4)
		
		//tmp=10
		//n=7
		//parent=tmp ---> parent=7
		//n->key=7 so temp->key=10
		//temp=5 after first if statement in while loop
		//parent points to 10, so parent=5
		//go to else, now temp=temp->rightchild which means temp=NULL
		//go to else statement, parent=5 rightchild=7
	//search for a value
		//recursive version: calling on smaller and smaller instance of the structure
			//search(node, searchkey) searchkey is value that we are looking for
			//if (node==NULL)
				//return node
			//else 
				//if(node->key ==searchkey)
					//return node
				//else if(node->key>searchkey)
					//return search(node->leftchild, searchkey)
				//else
					//return search(node->rightchild, searchkey)
			//returns node with searchkey value if it's found, else we return NULL
			//base case: node==NULL, or node==searchkey (we find it or we don't)
		
		//iterative version: returns pointer to node where searchkey found, returns NULL if not found
			//search(searchkey)
			//Node *n=root; create a pointer to root
			//while(n!=NULL)
				//if(n->key>searchkey)
					//n=n->leftchild
				//else if(n->key<searchkey)
					//n=n->rightchild
				//else
					//return n
			//return NULL 
	//delete a node: must preserve BST properties (must have root); remove node and update parent child pointers
		//node might need to be replaced by another node in the tree
		//3 cases to consider
		//Case 1: Node has no children
		//Case 2: Node has 1 child
			//need to assign new parent, and new rightchild 
		//Case 3: Node has 2 children
			//most complicated, two options
			//max value in left subtree or min value in right subtree will preserve BST properties
			//convetion is to use min in right subtree
				//replacement node is deleted node's rightchild
				//replacement node is not rightchild
					//replace node with minimum value in its right subtree

		
		/*
		delete(value)
			Node* n = search(value) //n is node we want to delete
			if(n!=NULL)
				if(n!=root) //Case 1
					if(n->leftchild==NULL && n->rightchild==NULL)
						if(n==n->parent->leftchild) 
							n->parent->leftchild=NULL
						else
							n->parent->rightchild=NULL
						delete n
				else if(n->leftchild!=NULL &&n->rightchild!=NULL) //Case 3
				

				else //Case 2 where left!=Null or right!=NULL but not both
					node* x=n->leftchild
					//check if we need to look at the right child or the left child of the parent
					n->parent->rightchild=x
					x->parent=n->parent
					delete n
		*/
	//print the contents of the tree
	

/*delete in Case 3
//first find the min in right subtree
Node* min=treeMinimum(n->rightchild) //input to treemin is right child of node we want to delete
treeMinimum(n) //n is a node pointer
	Node* x=n;
	while(x->leftchild!=NULL)
	{
		x=x->leftchild;
	}
	return x;
//delete 15
	n=search(15);
	treeMinimum(n->rightchild);
		//returns pointer to leftmost leftchild of right subtree

//if min is right child of node delete
min=treeMinimum(15->rightchild);
if(min==n->rightchild)
	n->parent->leftchild=min; 
	min->parent=n->parent;
	min->leftchild=n->leftchild;
	min->leftchild->parent=min;
else
	//condition where min not right child
	//nodes involved: min->rightchild, min->parent gets new leftchild, n->leftchild, n->rightchild, n->parent
	min->parent->leftchild=min->rightchild
	min->rightchild->parent=min->parent
	min->parent=n->parent
	min->parent->leftchild=min
	min->leftchild=n->leftchild
	min->rightchild=n->rightchild
	n->rightchild->parent=min
	n->leftchild->parent=min
delete n 




























