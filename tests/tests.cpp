#include <iostream>
#include <vector>
#include <string>

#include "Airport.h"
#include "Djikstras.h"
#include "BFS.h"

#include "../catch/catch.hpp"
 
using namespace std;

<<<<<<< Updated upstream
TEST_CASE("Testing Airport constructor with vector") { 
    cout<<"Testing vector constructor with Goroka Airport"<<endl;
    vector<string> data = {"1","Goroka Airport","","", "", "", "-6.081689834590001,", "145.391998291"};
    arr["Goroka Airport"] = Airport(data);
    string name = arr["Goroka Airport"].getName();
    int id = arr["Goroka Airport"].getID();
    int latitude = (int)arr["Goroka Airport"].getLatitude();
    int longitude = (int)arr["Goroka Airport"].getLongitude();

    REQUIRE(1 == id);
    REQUIRE("Goroka Airport" == name);
    REQUIRE(-6 == latitude);
    REQUIRE(145 == longitude);
}

TEST_CASE("Testing Pagerank implementation on a subset of the whole data set") { 
    //adjust the precision of the weight of edge to be shown
    cout << setprecision(10);
    cout << "\n\n\n\n >>>>>>>>Testing constructing graph from a subset of data and pagerank on the data set\n" << endl;
    string airportFile = "tests/airport_sample.dat";
    string routesFile = "tests/routes_sample.dat";
    Graph airportGraph(airportFile, routesFile);
    unordered_map<int, Airport> airportMap = airportGraph.getVertices();x
    //printing out all flights departing from O'Hare, Newark and Beijing airport
    for(auto it = airportMap.begin(); it != airportMap.end(); ++it){
        cout << "Airport ID: " << it->first <<endl;
        if(it->first == 3830 || it->first == 3494 || it->first == 3364){
            cout << "Airport ID: " <<it->second.getID() << " ";
            cout << "Airport Name: " <<it->second.getName() << endl;
        }
    }
    cout << "\n";
    PageRank *test = new PageRank();                      //create pagerank obj                 
    test->createadjacency(test->num, 0.85);               //create adjmatrix
    test->print_adjmatrix();                              //print matrix
    vector<double> init = test->vec_initial();            //generate initial vector 
    vector<double> vec = test->rank(init, 100, true);     //perform pagerank alg, 5 iteration
    test->print_result();                                 //print result
    vector<int> ranking = test->top_airport(5);           //pickout the top 5 important airport

    REQUIRE(3364 == ranking[0]);
    REQUIRE(3728 == ranking[1]);
}



TEST_CASE("Testing Pagerank function createadjacency()") {
    PageRank *p_r = new PageRank();
    int size = 2;
    p_r->adjacency.resize(size,vector<double>(size));

    p_r->adjacency[0][0] = 0.0;
    p_r->adjacency[1][0] = 0.0;

    p_r->adjacency[0][1] = 4.0;   
    p_r->adjacency[1][1] = 6.0;  

    p_r->airport_id.resize(size);
    p_r->num = size;

    p_r->PageRank::createadjacency(size, 0.85);
    REQUIRE(0.5 == p_r->adjacency[0][0]);
    REQUIRE(0.5 == p_r->adjacency[1][0]);
    REQUIRE(1 == p_r->adjacency[0][1] + p_r->adjacency[1][1]);
=======
// TEST_CASE("Testing Airport constructor with vector") { 
//     cout<<"Testing vector constructor with Goroka Airport"<<endl;
//     vector<string> data = {"1","Goroka Airport","","", "", "", "-6.081689834590001,", "145.391998291"};
//     arr["Goroka Airport"] = Airport(data);
//     string name = arr["Goroka Airport"].getName();
//     int id = arr["Goroka Airport"].getID();
//     int latitude = (int)arr["Goroka Airport"].getLatitude();
//     int longitude = (int)arr["Goroka Airport"].getLongitude();

//     REQUIRE(1 == id);
//     REQUIRE("Goroka Airport" == name);
//     REQUIRE(-6 == latitude);
//     REQUIRE(145 == longitude);
// }

// TEST_CASE("Testing Airport constructor with string") { 
//     cout<<"Testing string constructor with Madang Airport"<<endl;
//     string madang = "2,\"Madang Airport\",\"Madang",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
//     vec["Madang Airport"] = Airport(madang);
//     int id = (vec["Madang Airport"].getID());
//     string name = (vertices["Madang Airport"].getName());
//     int latitude = (int)vertices["Madang Airport"].getLatitude();
//     int longitude = (int)vertices["Madang Airport"].getLongitude();
    
//     REQUIRE(2 == id);
//     REQUIRE("Madang Airport" == name);
//     REQUIRE(-5 == latitude);
//     REQUIRE(145 == longitude);
// }

// TEST_CASE("Testing Pagerank function createadjacency()") {
//     PageRank *p_r = new PageRank();
//     int size = 2;
//     p_r->adjacency.resize(size,vector<double>(size));

//     p_r->adjacency[0][0] = 0.0;
//     p_r->adjacency[1][0] = 0.0;

//     p_r->adjacency[0][1] = 4.0;   
//     p_r->adjacency[1][1] = 6.0;  

//     p_r->airport_id.resize(size);
//     p_r->num = size;

//     p_r->PageRank::createadjacency(size, 0.85);
//     REQUIRE(0.5 == p_r->adjacency[0][0]);
//     REQUIRE(0.5 == p_r->adjacency[1][0]);
//     REQUIRE(1 == p_r->adjacency[0][1] + p_r->adjacency[1][1]);
// }

// TEST_CASE("Testing Pagerank function bestairport()") { 
//     cout << "\n\n\n\n >>>>>>>>Testing Pagerank function bestairport()\n" << endl;
//     PageRank *p_r = new PageRank(); 
//     p_r->airport_id.resize(5);
//     p_r->page_rank.resize(5);

//     p_r->airport_id[0] = 0;
//     p_r->airport_id[1] = 1;
//     p_r->airport_id[2] = 2;
//     p_r->airport_id[3] = 3;
//     p_r->airport_id[4] = 4;

//     p_r->page_rank[0] = 0.245;
//     p_r->page_rank[1] = 324.15;
//     p_r->page_rank[2] = 23.21;
//     p_r->page_rank[3] = 56.33;
//     p_r->page_rank[4] = 4;

//     //pick out the top 3 airport's id
//     vector<int> rank = p_r->bestairport(3); 
//     REQUIRE(1 == rank[0]);
//     REQUIRE(3 == rank[1]);
//     REQUIRE(2 == rank[2]);
// }

TEST_CASE("Testing Dijkstras: Path exists between two nodes, [Part = 1]") {
    Djikstras d;
    vector<vector<int> > adjacencyMatrix
        = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    std::vector<int> expected;
    std::vector<int> result;
    result = d.dijkstra(adjacencyMatrix, 0, 8);
    REQUIRE(expected[0] == result[0]);
    REQUIRE(expected[1] == result[1]);
    REQUIRE(expected[2] == result[2]);
>>>>>>> Stashed changes
}

TEST_CASE("Testing Dijkstras: Path exists between two nodes, [Part = 2]") {
    Djikstras d;
    vector<vector<int> > adjacencyMatrix
        = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    std::vector<int> expected;
    std::vector<int> result;
    result = d.dijkstra(adjacencyMatrix, 0, 4);
    REQUIRE(expected[0] == result[0]);
    REQUIRE(expected[1] == result[1]);
    REQUIRE(expected[2] == result[2]);
    REQUIRE(expected[3] == result[3]);
}

// std::vector<Airport> readAirportCSV(std::string filename) {
//     std::vector<Airport> airports;
//     std::vector<std::string> test;
//     std::fstream infile(filename);

<<<<<<< Updated upstream





std::vector<Airport> readAirportCSV(std::string filename) {
    std::vector<Airport> airports;
    std::vector<std::string> test;
    std::fstream infile(filename);

     // Make sure the file is open
    if(!infile.is_open()) throw std::runtime_error("Could not open file");
=======
//      // Make sure the file is open
//     if(!infile.is_open()) throw std::runtime_error("Could not open file");
>>>>>>> Stashed changes
    
//     std::string line, field;
//     while (std::getline(infile,line)) {
//         test.push_back(line);
//         std::stringstream ss(line);
//         std::vector<std::string> fields;
//         while (std::getline(ss,field,',')) {
//             fields.push_back(field);
//             //std::cout << field << std::endl;
//         }
        
//         // int id = std::stoi(fields[0]);
//         // std::cout << id << std::endl;
//         // std::string name = fields[1];
//         // double lat = std::stod(fields[6]);
//         // double longi = std::stod(fields[7]);
//         // Airport ap(id, name, lat, longi);
//         // airports.push_back(ap);
//     }
//     // Close the File
//     infile.close();
//     return airports;
// }

// int main(int argc, char** argv)
// {
//     std::vector<Airport> aps = readAirportCSV("ap_small.dat");
//     std::vector<std::string> t = readAirportCSV("ap_small.dat");
//     for (auto ap : aps) {
//         //std::cout << "id:" << ap.getID() << ", name:" << ap.getName() << ", lat:" << ap.getLatitude() << ", long:" << ap.getLongitude();
//         std::cout << "hi" << std::endl;
//     }
//     for (auto str : t) {
//         std::cout << str << std::endl;
//     }
//     return 0;
// }
