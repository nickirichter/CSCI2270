Assignment 8
#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex;

struct adjVertex{
    vertex *v; //stores the address of an element in vertices
    int weight;
};

struct vertex{
    string name;
    vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(string v1, string v2, int weight);
        void addVertex(string name);
        void displayEdges();
    protected:
    private:
        //vector<edge> edges;
        vector<vertex> vertices;

};

#endif // GRAPH_H

