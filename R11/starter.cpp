#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct vertex;

struct adjVertex {
	vertex* v;
	int weight;
};

struct vertex {
	string key;
	vector<adjVertex> adjacent;
	bool visited = false;
};

class Graph {
	private:
		//vertices
		vector<vertex> vertices;
		vertex* findVertex(string);
	public:
		//methods for accessing graphs
		Graph();
		~Graph();
		void insertVertex(string);	//identifier of the vertex
		void insertEdge(string,string,int);	//start, end, weight
		void printGraph();
		void BFS(string);
		void DFSpath(string, string);
		void findNodeWithMaximumAdjacent(string);

};

Graph::Graph() {}

Graph::~Graph() {}

void Graph::insertVertex(string value) {
	bool found = false;
	int i=0;
	while (i<vertices.size() && !found) {
		if (vertices[i].key == value) {
			found = true;
		}
		i++;
	}
	if (!found) {
		vertex v;
		v.key = value;
		vertices.push_back(v);
	}
	else {
		cout << "There is already a vertex " << value << " in this graph" << endl;
	}
}

vertex* Graph::findVertex(string value) {
	int i=0;
	while (i<vertices.size()) {
		if (vertices[i].key == value) {
			return &vertices[i];
		}
		i++;
	}
	return nullptr;
}



void Graph::insertEdge(string v1, string v2, int weight) {
	vertex *vStart = findVertex(v1);
	vertex *vEnd = findVertex(v2);
	if (vStart!=nullptr && vEnd!=nullptr) {
		//this code assumes that an edge doesn't exist
		//write some error checking to handle when it does
		adjVertex v1v2Edge;
		v1v2Edge.weight = weight;
		v1v2Edge.v = vEnd;
		vStart->adjacent.push_back(v1v2Edge);
	}
	else {
		if (vStart == nullptr) {
			cout << "no vertex with name " << v1 << " in this graph" << endl;
		}
		if (vEnd == nullptr) {
			cout << "no vertex with name " << v2 << " in this graph" << endl;
		}
	}
}

void Graph::findNodeWithMaximumAdjacent(string vertName) 
{
	queue<vertex*> vertexQ;
	vertex* MaxV;
	int max;
	queue<vertex*> myqueue;
	vertex* currentVert = findVertex(vertName);
	if (currentVert != nullptr) {
		currentVert->visited = true;
		vertexQ.push(currentVert);
		while (vertexQ.size()!=0) {
			vertex* curV = vertexQ.front();	
			vertexQ.pop();
			for (int i=0; i<curV->adjacent.size(); i++) {
				if (!curV->adjacent[i].v->visited) {
					curV->adjacent[i].v->visited = true;
					cout<<curV->adjacent[i].v->key<<" ";
					vertexQ.push(curV->adjacent[i].v);
					if(max<curV->adjacent.size())
					{
						max=curV->adjacent.size();
						MaxV=curV;
					}
				}
			}
		}
		cout<<endl;
		cout<<"Max vertex is: "<<MaxV->key<<endl;
	}
	else {
		cout << "vertex " << vertName << " not in graph" << endl;
	}
}


void Graph::DFSpath(string src, string dst) 
{
	stack<vertex*> vertexQ;
	vertex* curV;
	for(int i=0;i<vertices.size(); i++)
	{
		vertices[i].visited=false;
	}
	stack<vertex*> myqueue;
	vertex* currentVert = findVertex(src);
	if (currentVert != nullptr) {
		currentVert->visited = true;
		vertexQ.push(currentVert);
		while (vertexQ.size()!=0) {
			curV = vertexQ.top();	
			vertexQ.pop();
			cout<<curV->key<<" ";
			if(curV->key==dst)
			{
				return;
			}
			for (int i=0; i<curV->adjacent.size(); i++) {
				if (!curV->adjacent[i].v->visited) {
					curV->adjacent[i].v->visited = true;
					vertexQ.push(curV->adjacent[i].v);
				}
			}
			
		}
	}
	else {
		cout << "vertex " << curV->key << " not in graph" << endl;
	}
}






int main() {

	Graph myGraph;

	myGraph.insertVertex("A");
	myGraph.insertVertex("B");
	myGraph.insertVertex("C");
	myGraph.insertVertex("D");
	myGraph.insertVertex("E");
	myGraph.insertVertex("F");
	myGraph.insertVertex("G");

	myGraph.insertEdge("A", "B", 0); myGraph.insertEdge("B", "A", 0);
	myGraph.insertEdge("A", "C", 0); myGraph.insertEdge("C", "A", 0);
	myGraph.insertEdge("B", "D", 0); myGraph.insertEdge("D", "B", 0);
	myGraph.insertEdge("C", "D", 0); myGraph.insertEdge("D", "C", 0);
	myGraph.insertEdge("E", "D", 0); myGraph.insertEdge("D", "E", 0);
	myGraph.insertEdge("E", "B", 0); myGraph.insertEdge("B", "E", 0);
	myGraph.insertEdge("E", "G", 0); myGraph.insertEdge("G", "E", 0);
	myGraph.insertEdge("F", "G", 0); myGraph.insertEdge("G", "F", 0);

	myGraph.findNodeWithMaximumAdjacent("A");
	myGraph.DFSpath("A", "E");




	


}