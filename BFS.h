#pragma once
#include "Airport.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "AirportGraph.h"

class BFS {
    public:
    //constructor
    BFS(const std::string &airports, const std::string &routes);

    //returns the traversals that contain the inital airport
    std::vector<std::string> BFS_traversed(int initialAirport);

    //returns the traversals that go up until the given number of iterations/moves
    std::vector<std::string> BFS_iterations(int initialAiport, int moves);

    //returns the traversal until it reaches the desired airport
    std::vector<std::string> BFS_iterations(int initialAiport, int desAirport);

    private:
    Graph airports;
    

};
