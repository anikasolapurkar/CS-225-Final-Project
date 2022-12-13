#pragma once
// #include "airport_graph.h"
// #include "Flight.h"
// #include "Airport.h"

#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Djikstras {
    public:
        // Djikstras(const string &airportFile, const string &routeFile);
        std::vector<int> finalvector(int currentVertex, std::vector<int> parents);
        std::vector<int> dijkstra(std::vector<std::vector<double>> adjacencyMatrix, int startVertex, int destination);
    private:
        
};