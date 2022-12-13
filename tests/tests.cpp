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






TEST_CASE("Testing Airport constructor with string")
{
    string madang = "5,\"O'Hare Airport\",\"Chicago\",\"United States\",\"MAG\",\"AYMD\",-5.183719292,123.2738192,30,68,\"U\",\"Atlantic/Midway\",\"airport\",\"OurAirports\"";
    unordered_map<string, Airport> vec;
    vec["O'Hare Airport"] = Airport(madang);
    int id = (vec["O'Hare Airport"].getID());
    string name = (vec["O'Hare Airport"].getName());
    int latitude = (int)vec["O'Hare Airport"].getLatitude();
    int longitude = (int)vec["O'Hare Airport"].getLongitude();
    
    REQUIRE(5 == id);
    REQUIRE("O'Hare Airport" == name);
    REQUIRE(-5 == latitude);
    REQUIRE(123 == longitude);
}



TEST_CASE("Testing the number of the moves from one airport and testing if it goes to the right airport")
{
    std::string airportFile = "../tests/airport.dat";
    std::string routesFile = "../tests/routes.dat";

    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_moves(3830, 50);
    cout << "Printing out first 50 moves from O'Hare airport" << endl;
    for(unsigned i = 0; i < result_moves.size(); i++){
        cout << result_moves[i] ;
        if(i != result_moves.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
    cout << endl;
    REQUIRE(51 == result_moves.size()) ;
    REQUIRE("Chicago O'Hare International Airport" == result_moves[0]) ;
}

TEST_CASE("Testing PageRank with hardcoded adjacency matrix")
{
    PageRank *p_r = new PageRank(); 
    int size = 2;
    p_r->adjacency.resize(size,vector<double>(size));

    p_r->adjacency[0][0] = 0.0;
    p_r->adjacency[1][0] = 0.0;

    p_r->adjacency[0][1] = 4.0;   
    p_r->adjacency[1][1] = 6.0;  

    p_r->airport_id.resize(size);
    p_r->num = size;

    p_r->PageRank::createTransition(size, 0.85);
    REQUIRE(0.5 == p_r->adjacency[0][0]) ;
    REQUIRE(0.5 == p_r->adjacency[1][0]);
    REQUIRE(1 == p_r->adjacency[0][1] + p_r->adjacency[1][1]);
}

TEST_CASE("Testing Pagerank function bestairport() hardcoded")
{
    PageRank *p_r = new PageRank(); 
    p_r->airport_id.resize(5);
    p_r->page_rank.resize(5);

    p_r->airport_id[0] = 0;
    p_r->airport_id[1] = 1;
    p_r->airport_id[2] = 2;
    p_r->airport_id[3] = 3;
    p_r->airport_id[4] = 4;

    p_r->page_rank[0] = 0.245;
    p_r->page_rank[1] = 324.15;
    p_r->page_rank[2] = 23.21;
    p_r->page_rank[3] = 56.33;
    p_r->page_rank[4] = 4;

    //pick out the top 3 airport's id
    vector<int> rank = p_r->bestairport(3); 
    REQUIRE(1 == rank[0]);
    REQUIRE(3 == rank[1]);
    REQUIRE(2 == rank[2]);
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
    std::vector<double> steady_state = pr->rank(initial, 30, false);
    //get the order of airports with most incoming flights, DESCENDING
    std::vector<int> order = pr->bestairport(initial.size());
    //first element is the airport with most incoming flights
    Airport most_popular_ap = graph.vertices[order[0]];
    REQUIRE(most_popular_ap.getID() == 3364);
    REQUIRE(most_popular_ap.getName() == "Beijing Capital International Airport");
}

TEST_CASE("Testing PageRank with FULL databases") {
    std::string airportFile = "../tests/airport.dat";
    std::string routesFile = "../tests/routes.dat";
    PageRank * pr = new PageRank();
    Graph graph(airportFile, routesFile);
    auto airportMap = graph.getVertices();
    std::cout << "graph made" << std::endl;
    //make adjacency matrix from airport graph
    graph.adjMatrix(pr);
    std::cout << "adjacency matrix made" << std::endl;
    //turn adjacency matrix to transition matrix
    pr->createTransition(pr->adjacency.size(), 0.85);
    std::cout << "transition matrix made" << std::endl;
    //generate random initial vector
    std::vector<double> initial = pr->vec_initial();
    std::cout << "initial vector created" << std::endl;
    //calculate steady state vector
    std::vector<double> steady_state = pr->rank(initial, 100, false);
    std::cout << "steady state found" << std::endl;
    //get the order of airports with most incoming flights, DESCENDING
    std::vector<int> order = pr->bestairport(initial.size());
    std::cout << "order found" << std::endl;
    //first element is the airport with most incoming flights
    Airport most_popular_ap = graph.vertices[order[0]];
    std::cout << "Testing PageRank with FULL airport and routes: " << std::endl;
    std::cout << "Most popular airport ID: " << most_popular_ap.getID() << std::endl;
    std::cout << "Most popular airport name: " << most_popular_ap.getName() << std::endl;
}

TEST_CASE("Testing BFS_dest with SMALL databases") {
    std::string airportFile = "../tests/ap_small.dat";
    std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_dest(3670, 3364);
    
    for(unsigned i = 0; i < result_moves.size(); i++){
        cout << result_moves[i] ;
        if(i != result_moves.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
}

TEST_CASE("Testing BFS_dest with SMALL databases NO ROUTE") {
    std::string airportFile = "../tests/ap_small.dat";
    std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_dest(3988, 2359);
    
    REQUIRE(result_moves.empty());
}

TEST_CASE("Testing BFS_dest with FULL databases") {
    std::string airportFile = "../tests/airport.dat";
    std::string routesFile = "../tests/routes.dat";
    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_dest(2972, 350);
    
    for(unsigned i = 0; i < result_moves.size(); i++){
        cout << result_moves[i] ;
        if(i != result_moves.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
}

TEST_CASE("Testing BFS_all with SMALL databases") {
    std::string airportFile = "../tests/ap_small.dat";
    std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_all(2305);
    
    REQUIRE(result_moves.size() == 4);
}

