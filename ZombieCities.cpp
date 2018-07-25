Assignment 8
#include <iostream>
#include <vector>
using namespace std;

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

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    Graph a;
    string line, number, namescities, firstcity, secondcity;
    bool quit = false;
    int i = 0;
    if (infile.fail())
    {
        cout << "problem opening file" << endl; 
    }
    else
    {
        //vector <vertex> cities;
        vector<string> cityName;
        getline(infile, line);
        stringstream ss(line);
        getline(ss, namescities, ',');
        while(getline(ss, namescities, ','))
        {
            a.addVertex(namescities);
            cityName.push_back(namescities);
        }

        string w= "";
        while(getline(infile, line))
        {
            stringstream ss(line);
            int j= 0;
            getline(ss, w, ',');
            while(getline(ss, w, ','))
            {
                int dist= stoi(w);
                if(dist!=0 && dist!=-1)
                {
                    a.addEdge(cityName[i], cityName[j], dist);
                }
                j++;
            }
            i++;
        }

        infile.close();
    }

    while(quit == false)
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Vertex adjacent" << endl;
        cout << "3. Quit" << endl;
        cin >> number;

        if(number == "1")
        {
            a.displayEdges();
        }
        else if(number == "2")
        {
            cout << "Enter first city:" << endl;
            cin >> firstcity;
            cout << "Enter second city:" << endl;
            cin >> secondcity;
            if(0 == a.isAdjacent(firstcity, secondcity))
            {
                cout << "False" << endl;
            }
            else if(1 == a.isAdjacent(firstcity, secondcity))
            {
                cout << "True" << endl;
            }
        }
        else if(number == "3")
        {
            cout << "Goodbye!" << endl;
            quit = true;
            break;
        }
    }
}

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