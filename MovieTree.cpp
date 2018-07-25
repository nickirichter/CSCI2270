#include <iostream>
using namespace std;
#include "MovieTree.h"

MovieTree::MovieTree()
{
	root=NULL;
}

MovieTree::~MovieTree()
{
	//cout<<"N"<<endl;
	DeleteAll(root);
	root=NULL;
}

void MovieTree::DeleteAll(MovieNodeBST* node)
{
	if(node==NULL)
	{
		//cout<<"X"<<endl;
		return;
	}
	else if(node->letter<'A' && node->letter>'z')
	{
		//cout<<"Y"<<endl;
		return;
	}
	else
	{
		//cout<<"Z"<<endl;
		DeleteAll(node->leftChild);
		DeleteAll(node->rightChild);
		MovieNodeLL* temp=node->head;
		while(temp!=NULL)
		{
			MovieNodeLL* x=temp;
			if(temp->quantity!=0)
			{
				cout<<"Deleting: "<<x->title<<endl;

			}
			temp=temp->next;
			delete x;
		}
		delete node;
	}
}

MovieNodeLL* addLL(MovieNodeLL* head, MovieNodeLL* add)
{
    if(head->title>add->title)
    {
        add->next=head;
        return add;
    }
    else
    {
        MovieNodeLL* x=head;
        while(x!=NULL)
        {
            if(x->next==NULL)
            {
                x->next=add;
                break;
            }
            else
            {
                if(x->next->title>add->title)
                {
                    add->next=x->next;
                    x->next=add;
                    break;
                }
            }
            x=x->next;
        }
    }
    return head;
}

// MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title)
// {
// 	MovieNodeLL *current = head;
// 	while(current!=NULL)
// 	{
// 		if(current->title==title)
// 		{
// 			return current;
// 		}
// 		current=current->next;
// 	}
// 	return NULL;
// }

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title)
{
	MovieNodeLL *current = head;
	if(current==NULL)
	{
		return NULL;
	}
	if(current->title==title)
	{
		return current;
	}
	else
	{
		if(current->next==NULL)
		{
			return NULL:
		}
		else
			return searchLL(current->next, title);
	}
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
	MovieNodeLL* newMovie= new MovieNodeLL(ranking, title, releaseYear, quantity);
	if(root==NULL)
	{
	    root=new MovieNodeBST(title[0]);
	    root->head=newMovie;
	}
	else if(root->letter==title[0])
	{
	    root->head=addLL(root->head, newMovie);
	}
	else
	{
	    MovieNodeBST* n=root;
	    while(n->letter!=title[0])
	    {
	        if(n->letter>title[0])
	        {
	            MovieNodeBST* newBST= new MovieNodeBST(title[0]);
	            if(n->leftChild==NULL)
	            {
	                n->leftChild=newBST;
	                newBST->parent=n;
	                newBST->head=newMovie;
	                break;
	            }
	            else if(n->leftChild->letter==title[0])
	            {
	                n->leftChild->head=addLL(n->leftChild->head, newMovie);
	                n->leftChild=newBST;
	                newBST->parent=n;
	                newBST->head=newMovie;
	                break;
	            }
	            n=n->leftChild;
	        }
	        else 
	        {
	            if(n->rightChild==NULL)
	            {
	                MovieNodeBST* newBST=new MovieNodeBST(title[0]);
	                n->rightChild=newBST;
	                newBST->parent=n;
	                newBST->head=newMovie;
	                break;
	            }
	            else if(n->rightChild->letter==title[0])
	            {
	                n->rightChild->head=addLL(n->rightChild->head, newMovie);
	            }
	            n=n->rightChild;
	        }
	    }
	}
}

void MovieTree::deleteMovieNode(string title)
{
	int flag=-1;
	MovieNodeBST* movieLetter=searchBST(root, title);
	if(movieLetter==NULL)
	{
		cout<<"Movie not found."<<endl;
	}
	else
	{
		MovieNodeLL* deleteMovie=searchLL(movieLetter->head, title);
		if(deleteMovie==NULL)
		{
			cout<<"Movie not found."<<endl;
			return;
		}
		else if(movieLetter->head!=deleteMovie)
		{
			MovieNodeLL* temp=movieLetter->head;
			MovieNodeLL* prev=NULL;
			while(temp!=NULL)
			{
				if(temp->title==title)
				{
					if(temp->next==NULL)
						prev->next=NULL;
					else
					{
						prev->next=temp->next;

					}
					delete deleteMovie;
					return;
				}
				prev=temp;
				temp=temp->next;
			}
		}
		else 
		{
			if(movieLetter->head->next==NULL)
			{
				delete deleteMovie;
				flag=0;
			}
			else 
			{
				movieLetter->head=deleteMovie->next;
				delete deleteMovie;
				
			}
			
			if(flag==0)
			{
				if(movieLetter->leftChild == NULL && movieLetter->rightChild == NULL) // no children case
				{
					if(movieLetter==root)
					{
						delete movieLetter;
						root = NULL;
					}
					else
					{
						MovieNodeBST* prev=movieLetter->parent;
						if(prev->leftChild==movieLetter)
						{
							delete movieLetter;
							prev->leftChild=NULL;
						}
						else
						{
							delete movieLetter;
							prev->rightChild=NULL;
						}
					}	
				}
				else if(movieLetter->leftChild != NULL && movieLetter->rightChild == NULL) // one child case
				{
					if(movieLetter!=root)
					{
						MovieNodeBST *prev = movieLetter->parent;
						if(prev->leftChild==movieLetter)
						{
							prev->leftChild=movieLetter->leftChild;
							movieLetter->leftChild->parent=prev;
						}
						else
						{
							prev->rightChild=movieLetter->leftChild;
							movieLetter->leftChild->parent=prev;
						}
						delete movieLetter;
					}
					else
					{
						root=movieLetter->leftChild;
						movieLetter->leftChild->parent=NULL;
						delete movieLetter;
					}

				}

				else if(movieLetter->leftChild == NULL && movieLetter->rightChild != NULL) // one child case
				{
					if(movieLetter!=root)
					{
						MovieNodeBST *prev = movieLetter->parent;
						if(prev->rightChild==movieLetter)
						{
							
							prev->rightChild=movieLetter->rightChild;
							movieLetter->rightChild->parent=prev;
						}
						else
						{
							
							prev->leftChild=movieLetter->rightChild;
							movieLetter->rightChild->parent=prev;
						}
						delete movieLetter;
					}
					else
					{
						
						root=movieLetter->rightChild;
						movieLetter->rightChild->parent=NULL;
						delete movieLetter;

					}
				}
				else //two child case
				{
					
					MovieNodeBST* min=treeMinimum(movieLetter->rightChild);
					movieLetter->head=min->head;
					movieLetter->letter=min->letter;
					
					if(min->rightChild)
					{
						
						min->rightChild->parent=min->parent;
						
					}
					if(movieLetter->rightChild==min)
					{
						movieLetter->rightChild=min->rightChild;
						delete min;
						return;
					}
					min->parent->leftChild=min->rightChild;
					delete min;
				}
			}
		}
	}
}
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST* node)
{
	if(node!=NULL)
    {
        while(node->leftChild!=NULL)
        {
            node=node->leftChild;
        }
        return node;
    }
    else
    {
        return NULL;
    }
}t

MovieNodeBST* MovieTree::searchBST(MovieNodeBST* node, string value)
{
    MovieNodeBST* current= new MovieNodeBST;
    current=node;
	char letter1;
	letter1=value[0];
	if(current==NULL)
	{
		return current;
	}
	else
	{
    	if(current->letter==letter1)
    	{
    		return current;
    	}
    	else if(current->letter>letter1)
    	{
    		return searchBST(current->leftChild, value);
    		
    	}
    	else
    	{
    		return searchBST(current->rightChild, value);
    	}
    }
}

void MovieTree::findMovie(string title)
{

	//foundMovie==BST node
	//theMovie==LL node
	MovieNodeBST* foundMovie=searchBST(root, title);
	//cout << "$" << endl;
    if(foundMovie!=NULL)
    {
        MovieNodeLL* theMovie=searchLL(foundMovie->head, title);
        if(theMovie->quantity==0)
        {
        	cout<<"Movie not found."<<endl;
        }
        else
        {
	        cout<<"Movie info:"<<endl;
	    	cout<<"==========="<<endl;
	    	cout<<"Ranking:"<<theMovie->ranking<<endl;
	    	cout<<"title:"<<theMovie->title<<endl;
	    	cout<<"Year:"<<theMovie->year<<endl;
	    	cout<<"Quantity:"<<theMovie->quantity<<endl;
	    }
    }
    else
    {
    	cout<<"Movie not found."<<endl;
    }
}

void MovieTree::countMovieNodes(MovieNodeBST* node, int* c)
{
    *c=*c+1;
    if(node==NULL)
    {
        *c=0;
        return;
    }
    if(node==root)
    {
        *c=*c+1;
    }
    if(node->leftChild!=NULL)
    {
        countMovieNodes(node->leftChild, c);
    }
    if(node->rightChild!=NULL)
    {
        countMovieNodes(node->rightChild,c);
    }
}

void MovieTree::rentMovie(string title)
{
	MovieNodeBST* foundMovie=searchBST(root, title);
    if(foundMovie!=NULL)
    {
        MovieNodeLL* theMovie=searchLL(foundMovie->head, title);
       if(theMovie->quantity!=0)
        {
        	theMovie->quantity--;
			cout<<"Movie has been rented."<<endl;
	        cout<<"Movie info:"<<endl;
	    	cout<<"==========="<<endl;
	    	cout<<"Ranking:"<<theMovie->ranking<<endl;
	    	cout<<"title:"<<theMovie->title<<endl;
	    	cout<<"Year:"<<theMovie->year<<endl;
	    	cout<<"Quantity:"<<theMovie->quantity<<endl;

        }
        else
        {
        	cout<<"Movie not found."<<endl;
        	delete theMovie;
        	return;
	    }
    }
    else
    {
    	cout<<"Movie not found."<<endl;
    }	
}

void MovieTree::printMovieInventory(MovieNodeBST* node) 
{
	//cout<<"x"<<endl;
	//MovieNodeLL* current= new MovieNodeLL(ranking, title, year, quantity);
	if (node != NULL) 
	{
		//cout<<"y"<<endl;
		if (node->leftChild != NULL) 
		{
			cout<<"n"<<endl;
			printMovieInventory(node->leftChild);
			//current=node->leftChild->head;
			
				//cout<<"Movie: "<<current->title<<" "<<current->quantity<<endl;
				//current=current->next;
		}
		//cout<<"a"<<endl;
		//printMovieInventory(node);

		current=node->head;
		while(current!=NULL)
		{
			//cout<<"L"<<endl;
			if(current->quantity!=0)
			{
				cout<<"Movie: "<<current->title<<" "<<current->quantity<<endl;
				
			}
			current=current->next;

		}
		if (node->rightChild != NULL) 
		{
			
			printMovieInventory(node->rightChild);
			
		}
	}
}

void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

