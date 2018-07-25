
// bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dist)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    std::string name;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
    bool ifPathExistsLessThanDist(string vertex1, string vertex2, int dist);
    protected:
    private:
        std::vector<vertex> vertices;

};

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < (int)vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.visited = false;
        vertices.push_back(v);

    }
}

bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dist)
{
    vertex *start;
    for(int i = 0; i<(int)vertices.size();i++)//int converts the size to a readable number
    {
        vertices[i].visited = false; // sets all nodes to not visited
        if(vertices[i].name == vertex1)
        {
            start = &vertices[i]; //finds the address of the source
        }
    }
    queue<vertex*> Q;
    Q.push(start);//adds start to queue
    start->visited = true; // sets start visited to true
    //start->prev = NULL;
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
                //node->adj[i].v->prev = node;
                if(node->adj[i].v->name == vertex2)
                {
                    last = node->adj[i].v;
                    break;
                }
                Q.push(node->adj[i].v);
            }
        }
    }
    vertex *temp = start;
    while(temp!=NULL)
    {
        if(temp->distance>dist)
        {
            return false;
        }
        else
        {

            return true;
        }
    }
    
}


    int main() {
    Graph g;

    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");

    g.addEdge("a", "b");
    g.addEdge("a", "d");
    g.addEdge("c", "d");
    g.addEdge("b", "c");
    g.addEdge("d", "e");
    g.addEdge("c", "e");

    cout << g.ifPathExistsLessThanDist("c", "b", 1) << endl;;

    return 0;
}