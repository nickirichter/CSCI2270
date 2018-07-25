#include "Graph.h"
#include <limits.h>
#include <algorithm>
#include <
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}
void Graph::addEdge(string v1, string v2, int distance){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = distance;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    /*
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                    */
                }
            }
        }
    }
}
int Graph::isAdjacent(std::string v1, std::string v2)
{
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name==v1)
        {
            for(int j=0; j<vertices[i].adj.size(); j++)
            {
                if(vertices[i].adj[j].v->name==v2)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size()-1; j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<vertices[i].adj[vertices[i].adj.size()-1].v->name;
        cout<<endl;
    }

}
void Graph::shortestWeightedPath(string starting, string destination)
{
vector<vertex *> solved;
vertex * solvedV = NULL;
vertex * startV = NULL;
vertex * endV = NULL;
vertex * temp = NULL;
vertex * parent = NULL;
startV = findVertex(starting);
endV = findVertex(destination);
for(int i = 0; i < vertices.size(); i ++) vertices[i].visited = false;
if(startV == NULL || endV == NULL) {
cout << "one or more cities doesn't exist" << endl;
return;
}
if(startV->districtID == -1) {
cout << "Please identify the districts before checking distances" << endl;
return;
}
if(startV->districtID == endV->districtID){
startV->weightedDistance = 0;
startV->visited = true;
solved.push_back(startV);
while(!endV->visited){
int mdist = 500000;
int dist;
solvedV = NULL;
for(int j = 0; j < solved.size(); j++){
temp = solved[j];
for(int k = 0; k < temp->adj.size(); k++){
if(!temp->adj[k].v->visited){
dist = temp->weightedDistance + temp->adj[k].weight;
if(dist < mdist){
solvedV = temp->adj[k].v;
mdist = dist;
parent = temp;
}

}
}
}
solvedV->weightedDistance = mdist;
solvedV->visited = true;
solvedV->parent = parent;
solved.push_back(solvedV);
}
vertex * current = endV;
vector<vertex *> printV;
while(current != NULL){
printV.push_back(current);
if(current -> parent != NULL) current = current->parent;
else break;
}
cout << printV.size() - 1;
for(unsigned i = printV.size(); i-- > 0;){
cout << ", " << printV[i]->name;
}
cout << endl;
}else{
cout << "No safe path between cities" << endl;
}


}

void Graph::shortestPath(string startS, string endS){
vertex * start = NULL;
vertex * end = NULL;
for(int i = 0 ; i < vertices.size() ; i++){
if(vertices[i].name == startS) start = &vertices[i];
if(vertices[i].name == endS) end = &vertices[i];
vertices[i].visited == false;
}

if(start == NULL || end == NULL){
cout << "One or more cities doesn't exist" << endl;
return;
}
if(start->districtID == end->districtID ){
std::queue<vertex*> bfs;
start -> visited = true;
start -> unweightedDistance = 0;
bfs.push(start);
while(!bfs.empty()){
vertex *n = bfs.front();
bfs.pop();
for(int x = 0 ; x < n->adj.size() ; x++){
if(!n -> adj[x].v->visited){
n->adj[x].v->unweightedDistance = n->unweightedDistance + 1;
n->adj[x].v->parent = n;

if(n->adj[x].v->name == end -> name){
vertex * travel = end;
vector<vertex*> path;
while(travel != NULL){
path.push_back(travel);
travel = travel -> parent;
}
cout << path.size() - 1;
for (int i = path.size() - 1 ; i >= 0 ; i--){
cout << "," << path[i]->name;
}
cout << endl;
return;
}
else{
n->adj[x].v->visited = true;
bfs.push(n->adj[x].v);

}
}

}
}

}else{
cout << "No safe path between cities" << endl;
return;
}
}

void Graph::assignDistricts()
{
    int ID=1;
    for(int i=0; i<vertices.size(); i++)
    {
        vertices[i].visited=false;
        if(vertices[i].districtID==-1)
        {
            DFSLabel(vertices[i].name, ID);
            ID++;
        }
    }
    
}

void Graph::DFSLabel(string startingCity, int distID)
{
    vertex* current=findVertex(startingCity);
    current->visited=true;
    current->districtID=distID;
    for(int i=0; i<current->adj.size(); i++)
    {
        if(!current->adj[i].v->visited)
        {
            DFSLabel(current->adj[i].v->name, distID);
        }
    }
}