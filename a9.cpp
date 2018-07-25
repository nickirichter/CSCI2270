#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <set>
#include "Graph.hpp"

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addVertex(string name)
{
bool found = false;
for(int i = 0; i < vertices.size(); i++)
{
if(vertices[i].name == name)
{
found = true;
cout << name << "already in graph." << endl;
}
}
if(found == false)
{
vertex v;
v.name = name;
v.districtID = -1;
vertices.push_back(v);
}
}

void Graph::addEdge(string v1, string v2, int distance)
{
for(int i = 0; i < vertices.size(); i++)
{
if(vertices[i].name == v1)
{
for(int j = 0; j < vertices.size(); j++)
{
if(vertices[j].name == v2 && j != i)
{
adjVertex av;
av.v = &vertices[j];
av.weight = distance;
vertices[i].adj.push_back(av);

/*adjVertex av2;
av2.v = &vertices[i];
av2.weight = distance;
vertices[j].adj.push_back(av2);*/
}
}
}
}
}

/*int Graph::isAdjacent(string v1, string v2)
{
for(int i = 0; i < vertices.size(); i++)
{
for(int j = 0; j < vertices[i].adj.size(); j++)
{
if(vertices[i].name == v1 && vertices[i].adj[j].v->name == v2)
{
return 1;
}
else if(vertices[i].name == v2 && vertices[i].adj[j].v->name == v1)
{
return 1;
}
}
}
return 0;
}*/

vertex * Graph::findVertex(string city)
{
for(int i = 0; i < (int)vertices.size(); i++)
{
if(vertices[i].name == city)
{
return &vertices[i];
}
}
}

void Graph::assignDistricts()
{
    if(vertices[0].districtID == -1)
    {
    int count = 1;
    for(int i = 0; i < (int)vertices.size(); i++)
    {
    if(vertices[i].visited == false)
    {
    DFSLabel(vertices[i].name, count);
    count ++;
    }
    }
    }
}

//DFS
void Graph::DFSLabel(string startingCity, int distID)
{
vertex *start;
for(int i = 0; i < (int)vertices.size(); i++)
{
if(vertices[i].name == startingCity)
{
start = &vertices[i];
}
}

start->visited = true;
start->districtID = distID;
stack <vertex*> stack;
stack.push(start);
while(!stack.empty())
{

vertex *n = stack.top();
stack.pop();
for(int i = 0; i < (int)n->adj.size(); i++)
{
if(!n->adj[i].v->visited)
{
n->adj[i].v->districtID = distID;
n->adj[i].v->visited = true;
stack.push(n->adj[i].v);
}
}
}
}


//BFS
void Graph::shortestPath(std::string scity, std::string ecity)
{
vertex* start = findVertex(scity);
vertex* end = findVertex(ecity);
if(start == NULL || end == NULL)
{
cout << "One or more cities doesn't exist" << endl;
return;
}
if(start->districtID == -1 || end->districtID == -1)
{
cout << "Please identify the districts before checking distances" << endl;
return;
}
if(start->districtID != end->districtID)
{
cout<< "No safe path between cities" << endl;
return;
}
for(unsigned int i=0; i< vertices.size(); i++)
vertices[i].visited = false;
queue <vertex*> Q;
start->visited = true;
start->parent = NULL;
start->unweightedDistance=0;
Q.push(start);
while(!Q.empty())
{
vertex* node = Q.front();
Q.pop();
for(unsigned int i =0; i<node->adj.size(); i++)
{
if(!node->adj[i].v->visited)
{
node->adj[i].v->visited=true;
node->adj[i].v->parent=node;
node->adj[i].v->unweightedDistance = node->unweightedDistance+1;
Q.push(node->adj[i].v);

}
}
}
int dist=end->unweightedDistance;
stack<string> path;
while(end !=NULL)
{
path.push(end->name);
end = end->parent;
}
cout<<dist;
while(!path.empty())
{
cout<<", "<<path.top();
path.pop();
}
cout<<endl;
return; 

}
//Djikstras
void Graph::shortestWeightedPath(string startingCity, string endingCity)
{
    vertex *start = findVertex(startingCity);
    vertex *end = findVertex(endingCity);
   
/*vertex *start;
for(int i = 0; i < (int)vertices.size(); i++)
{
if(vertices[i].name == startingCity)
{
start = &vertices[i];
}
}
vertex *end;
for(int i = 0; i < (int)vertices.size(); i++)
{
if(vertices[i].name == endingCity)
{
end = &vertices[i];
}
}*/
if(start == NULL || end == NULL)
{
cout << "One or more cities doesn't exist" << endl;
return;
}
if(start -> districtID != end -> districtID)
{
cout << "No safe path between cities" << endl;
return;
}
if(start -> districtID == -1 || end -> districtID == -1)
{
cout << "Please identify the districts before checking distances" << endl;
return;
}
for(int i = 0; i < (int)vertices.size(); i++)
{
vertices[i].visited = false;
}
start -> visited = true;
start -> weightedDistance = 0;
start -> parent = NULL;
vector<vertex*> solved;
solved.push_back(start);
while(!end -> visited)
{
int minDistance = INT_MAX;
vertex* solvedV = NULL;
vertex *parent = NULL;
for(int i = 0; i < (int)solved.size(); i++)
{
vertex *s = solved[i];
for(int j = 0; j < (int)s -> adj.size(); j++)
{
if(!s -> adj[j].v -> visited)
{
int dist = s -> weightedDistance + s -> adj[j].weight;
if(dist < minDistance)
{
solvedV = s -> adj[j].v;
minDistance = dist;
parent = s;
}
}
}
}
solvedV -> weightedDistance = minDistance;
solvedV -> parent = parent;
solvedV -> visited = true;
solved.push_back(solvedV);
}
int dist = end -> weightedDistance;
stack<string> path;
while(end != NULL)
{
path.push(end -> name);
end = end -> parent;
}
cout << dist;
while(!path.empty())
{
cout << ", " << path.top();
path.pop();
}
cout << endl;
return;
}

void Graph::displayEdges()
{
for(int i = 0; i < vertices.size(); i++)
{
    cout << vertices[i].districtID << ":" << vertices[i].name << "-->";
for(int j = 0; j < vertices[i].adj.size(); j++)
{
cout << vertices[i].adj[j].v->name;
if(j != vertices[i].adj.size()-1)
{
cout << "***";
}
}
cout << endl;
}
}​

