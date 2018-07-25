#include "Graph.h"
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
//adds edges to each vertex by updating the adjacent vector for the vertex
void Graph::addEdge(string v1, string v2, int weight){
    //both vertices must exist in the graph to add an edge
    for(int i = 0; i < vertices.size(); i++){
        //check if vertex 1 is found
        if(vertices[i].name == v1){
            //if v1 is found, then start loop again and check for v2
            for(int j = 0; j < vertices.size(); j++){

                if(vertices[j].name == v2 && i != j){
                    //v1 and v2 are both found in vertices
                    //create an instance of adj vertex, called av
                    adjVertex av;
                    //set the vertex pointer to point to address of vertices[j] 
                    av.v = &vertices[j];
                    //set the weight using input value to function
                    av.weight = weight;
                    //add to adj vector for vertices[i]
                    vertices[i].adj.push_back(av);
                    
                    //another vertex for edge in other direction
                    //REMOVE THIS FOR ASSIGNMENT 8
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        //create a local instance of vertex, called v
        vertex v; //new vertex object
        v.name = n; //set name property of v to n
        vertices.push_back(v); //push the new vertex onto the vertices

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){ //vertices[i].adj is a vector, therefore use the size method to get num of elements
            cout<<vertices[i].adj[j].v->name<<"***"; 
            //if we wanted to show weight, verticies[i].adj[j].weight, no need to dereference
        }
        cout<<endl;
    }

}
