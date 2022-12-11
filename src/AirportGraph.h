#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Routes.h"
#include "PageRank.h"

using namespace std;

class Graph {
    public:
        //default constructor
        Graph();
        //constructor that accepts the airport and routes.dat files
        Graph(string & airportFile, string & routesFile);
        
        //functions to insert vertices with airport id and aiport object in it
        void insertVertex(int v, Airport ap);
        void insertAllVertices(std::string & fileName);
        
        //functions to create and insert edges
        vector<string> createEdgeHelper(string & line);
        Route createEdge(vector<string> flightVector);     
        void insertEdge(Route r);
        void insertAllEdge(std::string & fileName);
        
        //functions that return private maps for debugging
        unordered_map<int, Airport> getVertices();
        unordered_map<int, Route> adjVertWithWeight(int airportID);
        string getAPName(int ID);
        
        //function to harvest adjmatrix from a graph obj
        
        //ADD BACK
        //void adjMatrix(PageRank* pr_obj);

        unordered_map<int, Airport> vertices;


    private:
        //functions that calculate the weight of an edge
        double calcWeight(int source, int dest);
        double radianConvert(double degree);
        
        //each graph object hosts a map of airports to its corresponding ID
        
};