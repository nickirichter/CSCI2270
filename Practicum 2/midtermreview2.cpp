//Midterm Review 2
//Q1
// Write a c++ function to check if the unweighted shortest path between two vertices passes 
// through the third vertex. The function takes three parameters: source vertex, destination 
// vertex and intermediate vertex. It should check if the unweighted shortest path between source 
// and destination vertices passes through the intermediate vertex. It should display "Yes" if 
// the path passes through intermediate vertex. Otherwise, it should display "No".
// To answer this question, you need to know whether BFS or DFS is guaranteed to produce the shortest path in an unweighted graph
void Graph::shortestPath(string source, string destination, string intermediate)
{
    vertex *start;
    for(int i = 0; i<(int)vertices.size();i++)//int converts the size to a readable number
    {
        vertices[i].visited = false; // sets all nodes to not visited
        if(vertices[i].name == source)
        {
            start = &vertices[i]; //finds the address of the source
        }
    }
    queue<vertex*> Q;
    Q.push(start);//adds start to queue
    start->visited = true; // sets start visited to true
    start->prev = NULL;
    vertex *last;
    while(!Q.empty())
    {
        vertex *node = Q.front();//finds the first node in queue
        Q.pop();
        for(int i = 0; i<(int)node->adj.size();i++)
        {
            if(!node->adj[i].v->visited)
            {
                node->adj[i].v->visited=true;
                node->adj[i].v->prev = node;
                if(node->adj[i].v->name == destination)
                {
                    last = node->adj[i].v;
                    break;
                }
                Q.push(node->adj[i].v);
            }
        }
    }
    vertex *temp = last;
    while(temp!=NULL)
    {
        if(temp->prev==NULL)
        {
            break;
        }
        else if(temp->prev->name == intermediate)
        {
            cout<<"Yes";
            return;
        }
        temp = temp->prev;
    }
 cout<<"No";   
}

//Q2
// In the graph provided, each vertex in the graph contains a parent ID, which is the ID of 
// the parent vertex in a BFS. Some of the vertices have an incorrect parent ID assigned. 
// Write a C++ method that prints all vertices that have a mis-labeled parent ID. You do not need to check the parentID for the starting node.
void Graph::printMislabeledParents(int startVertex) {
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	cout << start->value << endl;
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
			for (int i =0; i<(int)node->adj.size();i++)
			{
			    if(!node->adj[i].v->visited)
			    {
			        node->adj[i].v->visited = true;
                    if(node->adj[i].v->parentID != node->value)
                    {
                        cout<<node->adj[i].v->value<<endl;
                    }
                    Q.push(node->adj[i].v);
				}
			}
		}
}

//Q3
// Print all the odd valued adjacent vertices in a graph
// You need to fill appropriate code in the following function which 
// has already been defined for you.
void Graph::findOddAdjacent(int startVertex) {
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	cout << start->value << " ";
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
		for (int i = 0; i < (int)node->adj.size(); i++) {
			if(node->adj[i].v->visited==false)
			{
			        node->adj[i].v->visited = true;
                    if(node->adj[i].v->value%2 != 0)
                    {
                        cout<<node->adj[i].v->value<<" ";
                    }
                    Q.push(node->adj[i].v);
			}
                
                   

		}
	}
}

//Q4
// Write a method that prints the vertices in a graph visited in a breadth-first search (BFS) 
// and the vertex with the maximum number of adjacent nodes.
// You need to fill in the appropriate code in the following function, which has already been 
// defined for you. Copy the code provided into the coding window as the starting point for your 
// answer.
void Graph::findNodeWithMaximumAdjacent(int startVertex) 
{
    
    int max = 0; 
    
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) 
	{
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) 
		{
			start = &vertices[i];
		}
	}
        queue<vertex*> Q;
    	Q.push(start);
    	start->visited = true;
    	cout << start->value << " ";
            //Students have to fill in this part 
            int maxNode = 0;
            while (!Q.empty()) 
            {
    		vertex *node = Q.front();
    		Q.pop();
    		int yungcount = 0; 
    		
    		for (int i = 0; i < (int)node->adj.size(); i++) 
    		{
    		    yungcount ++; 
    		    
    		    if(!(int)node->adj[i].v->visited)
    		    {
    		        node->adj[i].v->visited = true;
    		        Q.push(node->adj[i].v);
    		        cout << node->adj[i].v->value << " ";
    		    }
    		     if(yungcount > max)
    		        {
    		            max = yungcount; 
    		            maxNode = node->value;
    		        }
    
    		}
            
        }
        cout << endl; 
        cout << maxNode << endl; 
	
}

//Q5
// Find all nodes in a BST that are between a given range of values. Then build a linked list of 
// the values and the list should be in ascending order.
// NOTE: the head of the linked list is declared globally in the back end and its initial value 
// is NULL. Just add the nodes to the linked list using head. The printing of the linked list will 
// also be done in the backend. Helper functions can be used.
void RangeSearch(TreeNode *node, char m, char n)
{
    TreeNode *temp = node;
    if(temp!=NULL)
    {
        RangeSearch(temp->right,m,n);
        if(temp->key>=m && temp->key<=n)
        {
            Node *temp1 = head;
            Node *next = new Node();
            next->key = temp->key;
            next->next = temp1;
            head = next;
        }
        RangeSearch(temp->left,m,n);
    }
}

//Q6
// Write a function to insert a node into a binary search tree. The function will take in 
// the root node and a value to be inserted as arguments and return the root. You are not 
// allowed to hard code any answers. 
Node* insert(Node *root, int value)
{
    Node *temp = root;
    Node *par = NULL;
    
    while(temp !=NULL)
    {
    //cout<<temp->parent->key<<endl;
        if(value< temp->key )
        {
            if(temp->left == NULL){
                par = temp;
                Node *newnode = new Node(par, NULL,NULL);
                newnode->key=value;
                cout<<"inserted: "<< value<< " left child of: "<< par->key<<endl;
                return newnode;
                
            }
            temp=temp->left;
            //cout<<"go left"<<endl;
            
        } 
        if(value>temp->key )
        {
            if(temp->right == NULL){
                par = temp;
                Node *newnode = new Node(par, NULL,NULL);
                newnode->key=value;
                cout<<"inserted: "<< value<< " right child of: "<< par->key<<endl;
                return newnode;
                
            }
        
            temp=temp->right;
            //cout<<"go right"<<endl;
            
            
        }
    }
    
    return root;
}

//Q7
// Write a c++ function to color vertices based on distance from the source. The function takes 
// one parameter: starting vertex. Color the source node as "Red". Color all its neighbors
// (1 hop away from source) as "Black". Color all vertices that are 2 hops away from source as 
// "Red", 3 hops away as "Black" and so on. Use the built-in C++ queue data structure to implement 
// the queue.
void Graph::colorVertices(string sourceVertex)
{
    vertex *start;
    int i=0;
    while(i<vertices.size())
    {
        if(vertices[i].name == sourceVertex)
        {
            start = &vertices[i]; 
            break;
        }
        i++; 
    }
    
    queue<vertex*> Q;
    if(start != nullptr)
    {
        start->visited = true;
        start->color = "Red";
        Q.push(start);
        
            while (!Q.empty()) 
            {
            vertex *nudes = Q.front();
            Q.pop();
            for (int i = 0; i < nudes->adj.size(); i++) 
            {
                if(!nudes->adj[i].v->visited)
                {
                    nudes->adj[i].v->visited = true;
                    Q.push(nudes->adj[i].v);
                    if(nudes->color == "Red")
                    {
                        nudes->adj[i].v->color = "Black";
                    }
                    else
                    {
                        nudes->adj[i].v->color = "Red";
                    }
                    
                }
    
            }
            
        }
    }
    
}

//Q8
// Write a c++ function to find all vertices with no adjacent vertices. It should print 
// the vertices name separated by space. Otherwise, it should display "Not Found!".

void Graph::findVerticesWithNoAdjacentVertices()
{
    bool lilbool = false; 
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].adj.size() == 0)
        {
            lilbool = true; 
            cout << vertices[i].name << " "; 
        }

    }
            if(lilbool == false)
        {
            cout << "Not Found!" << endl; 
        }
}
