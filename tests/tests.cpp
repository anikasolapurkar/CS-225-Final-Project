#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "./Airport.h"
#include "./Djikstras.h"
#include "./BFS.h"
#include "./PageRank.h"

std::vector<Airport> readAirportCSV(std::string filename) {
    std::vector<Airport> airports;
    std::fstream infile(filename);

     // Make sure the file is open
    if(!infile.is_open()) throw std::runtime_error("Could not open file");
    
    std::string line, field;
    while (std::getline(infile,line)) {

        Airport ap(line);
        airports.push_back(ap);
    }


    // Close the File
    infile.close();
    return airports;
}
TEST_CASE("Parsing entire airport database")
{
    std::vector<Airport> aps = readAirportCSV("../tests/airport.dat");
    REQUIRE(aps.size() == 7698);
    REQUIRE(aps[116].getName() == "Greater Moncton International Airport");
    REQUIRE((int)aps[116].getLatitude() == 46);
    REQUIRE((int)aps[116].getLongitude() == -64);
}

TEST_CASE("Testing PageRank with SMALL airport and route databases") {
    std::string airportFile = "../tests/ap_small.dat";
    std::string routesFile = "../tests/routes_small.dat";
    PageRank * pr = new PageRank();
    Graph graph(airportFile, routesFile);
    //make adjacency matrix from airport graph
    graph.adjMatrix(pr);
    //turn adjacency matrix to transition matrix
    pr->createTransition(pr->adjacency.size(), 0.85);
    //generate random initial vector
    std::vector<double> initial = pr->vec_initial();
    //calculate steady state vector
    std::vector<double> steady_state = pr->rank(initial, 30, true);
    //get the order of airports with most incoming flights, DESCENDING
    std::vector<int> order = pr->bestairport(initial.size());
    //first element is the airport with most incoming flights
    Airport most_popular_ap = graph.vertices[order[0]];
    REQUIRE(most_popular_ap.getID() == 3364);
    REQUIRE(most_popular_ap.getName() == "Beijing Capital International Airport");
}

TEST_CASE("Testing PageRank with ENTIRE airport and route databases") {
    std::string airportFile = "../tests/airport.dat";
    std::string routesFile = "../tests/routes.dat";
    PageRank * pr = new PageRank();
    Graph graph(airportFile, routesFile);
    //make adjacency matrix from airport graph
    graph.adjMatrix(pr);
    //turn adjacency matrix to transition matrix
    pr->createTransition(pr->adjacency.size(), 0.85);
    //generate random initial vector
    std::vector<double> initial = pr->vec_initial();
    //calculate steady state vector
    std::vector<double> steady_state = pr->rank(initial, 30, true);
    //get the order of airports with most incoming flights, DESCENDING
    std::vector<int> order = pr->bestairport(initial.size());
    //first element is the airport with most incoming flights
    Airport most_popular_ap = graph.vertices[order[0]];
    std::cout << "Testing PageRank with FULL airport and routes: " << std::endl;
    std::cout << "Most popular airport ID: " << most_popular_ap.getID() << std::endl;
    std::cout << "Most popular airport name: " << most_popular_ap.getName() << std::endl;
}
