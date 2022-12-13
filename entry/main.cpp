#include <iostream>
#include <vector>
#include <string>

#include "./Airport.h"
#include "./Djikstras.h"
#include "./BFS.h"
#include "./PageRank.h"

using namespace std;

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



int main(int argc, char** argv)
{
    std::string airportFile = "../tests/airport.dat";
    std::string routesFile = "../tests/routes.dat";
    std::string airportFileSmall = "../tests/ap_small.dat";
    std::string routesFileSmall = "../tests/routes_small.dat";
    

    // TEST CASES
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "TEST CASE: Testing Airport constructor with string" << std::endl;
    string madang = "5,\"O'Hare Airport\",\"Chicago\",\"United States\",\"MAG\",\"AYMD\",-5.183719292,123.2738192,30,68,\"U\",\"Atlantic/Midway\",\"airport\",\"OurAirports\"";
    unordered_map<string, Airport> vec;
    vec["O'Hare Airport"] = Airport(madang);
    int id = (vec["O'Hare Airport"].getID());
    string name = (vec["O'Hare Airport"].getName());
    int latitude = (int)vec["O'Hare Airport"].getLatitude();
    int longitude = (int)vec["O'Hare Airport"].getLongitude();
    
    cout << (5 == id) << endl;
    cout << ("O'Hare Airport" == name) << endl;
    cout << (-5 == latitude) << endl;
    cout << (123 == longitude) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    
    std::cout << "TEST CASE: Populating the Airport Graph using filenames" << std::endl;
    Graph* airportgraph = new Graph(airportFile, routesFile);
    unordered_map<int, Airport> airportMap = airportgraph->getVertices();
    cout << "Number of airports: " << airportMap.size() <<endl;
    //printing out all flights departing from O'Hare, Newark and Beijing airport
    for(auto it = airportMap.begin(); it != airportMap.end(); ++it){
        //cout << "Airport ID: " << it->first <<endl;
        if(it->first == 3830 || it->first == 3494 || it->first ==3364){
            cout << "Airport ID: " <<it->second.getID() << " ";
            cout << "Airport Name: " <<it->second.getName() << endl;
            unordered_map<int, Route> adjList = it->second.destAPs;
            for(auto it = adjList.begin(); it != adjList.end(); ++it){
                cout << "Source ID: " << it->second.getSourceId() << " ";
                cout << "Destination ID: " << it->second.getDestId() << " ";
                cout << "Flight weight: " << it->second.getWeight() << endl;
            }
        }
    }
    cout << (7000 <= airportMap.size()) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing Airport Graph" << std::endl;
    Graph* airportgraph1 = new Graph(airportFile, routesFile);
    unordered_map<int, Airport> airportMap1 = airportgraph1->getVertices();
    cout << "Number of airports: " << airportMap1.size() <<endl;
    for(auto it = airportMap1.begin(); it != airportMap1.end(); ++it){

        if(it->first == 567 || it->first == 123 || it->first ==634){
            cout << "Airport ID: " <<it->second.getID() << " ";
            cout << "Airport Name: " <<it->second.getName() << endl;
            unordered_map<int, Route> adjList = it->second.destAPs;
            for(auto it = adjList.begin(); it != adjList.end(); ++it){
                cout << "Source ID: " << it->second.getSourceId() << " ";
                cout << "Destination ID: " << it->second.getDestId() << " ";
                cout << "Flight weight: " << it->second.getWeight() << endl;
            }
        }
    }
    cout << (6000 <= airportMap.size()) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing the number of the moves from one airport and testing if it goes to the right airport " << std::endl; 
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
    cout << (51 == result_moves.size()) << endl;
    cout << ("Chicago O'Hare International Airport" == result_moves[0]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing BFS" << std::endl;
    // BFS myBFS(airportFile, routesFile);
    vector<string> result_dest = myBFS.BFS_dest(3830, 3494);
    cout << "Printing out traversal from O'Hare to Newark" << endl;
    for(unsigned i = 0; i < result_dest.size(); i++){
        cout << result_dest[i] ;
        if(i != result_dest.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
    cout << endl;
    cout << ("Chicago O'Hare International Airport" == result_dest[0]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: PageRank" << std::endl;
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
    cout << (0.5 == p_r->adjacency[0][0]) << endl;
    cout << (0.5 == p_r->adjacency[1][0]) << endl;
    cout <<(1 == p_r->adjacency[0][1] + p_r->adjacency[1][1]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    cout << "TEST CASE: Testing Pagerank function bestairport()" << endl;
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
    cout << (1 == rank[0]) << endl;
    cout << (3 == rank[1]) << endl;
    cout << (2 == rank[2]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing Dijkstras: Path exists between two nodes" << std::endl;
    Djikstras d;
    vector<vector<double> > adjacencyMatrix
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
    expected.push_back(0);
    expected.push_back(1);
    result = d.dijkstra(adjacencyMatrix, 0, 1);
    cout << (expected[0] == result[0]) << endl;
    cout << (expected[1] == result[1]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing Dijkstras: Path exists between two nodes, [Part = 2]" << std::endl;
    vector<vector<double> > adjacencyMatrix1
        = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    std::vector<int> expected1;
    std::vector<int> result1;
    expected1.push_back(0);
    expected1.push_back(7);
    expected1.push_back(6);
    expected1.push_back(5);
    expected1.push_back(4);
    result1 = d.dijkstra(adjacencyMatrix1, 0, 4);
    cout << (expected1[0] == result1[0]) << endl;
    cout << (expected1[1] == result1[1]) << endl;
    cout << (expected1[2] == result1[2]) << endl;
    cout << (expected1[3] == result1[3]) << endl;
    cout << (expected1[4] == result1[4]) << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "TEST CASE: Testing Dijkstras: Path exists between two nodes" << std::endl;
    vector<vector<double> > adjacencyMatrix2
        = { { 10, 4, 23, 78, 100 },
            { 69, 420, 85, 100, 33 },
            { 68, 21, 5, 83, 62 },
            { 9, 14, 101, 42, 86 },
            { 12, 0, 10, 0, 0 } };
    std::vector<int> expected2;
    std::vector<int> result2;
    expected2.push_back(2);
    expected2.push_back(1);
    expected2.push_back(4);
    result2 = d.dijkstra(adjacencyMatrix2, 2, 4);
    cout << (expected2[0] == result2[0]) << endl;
    cout << (expected2[1] == result2[1]) << endl;
    cout << (expected2[2] == result2[2]) << endl;
    std::cout << "--------------------------------------------------" << std::endl;

    //REAL DATA SETS
    std::cout << ("Parsing entire airport database") << std::endl;
    std::vector<Airport> aps = readAirportCSV("../tests/airport.dat");
    std::cout << (aps.size() == 7698) << std::endl;
    std::cout << (aps[116].getName() == "Greater Moncton International Airport") << std::endl;
    std::cout << ((int)aps[116].getLatitude() == 46) << std::endl;
    std::cout << ((int)aps[116].getLongitude() == -64) << std::endl;
    
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << ("Testing PageRank with SMALL airport and route databases") << std::endl;
    // std::string airportFile = "../tests/ap_small.dat";
    // std::string routesFile = "../tests/routes_small.dat";
    PageRank * pr = new PageRank();
    Graph graph(airportFileSmall, routesFileSmall);
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
    std::cout << (most_popular_ap.getID() == 3364) << std::endl;
    std::cout << (most_popular_ap.getName() == "Beijing Capital International Airport") << std::endl;
    
    std::cout << "--------------------------------------------------" << std::endl;

    //NOTE: this test tests PageRank with FULL database, but it will most likely take a very long time due
    //to continuous matrix multiplication of large dimensions. Uncomment block to test.
    
    /*std::cout << ("Testing PageRank with FULL databases")  << std::endl;
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
    std::cout << "Most popular airport name: " << most_popular_ap.getName() << std::endl; */
    
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << ("Testing BFS_dest with SMALL databases") << std::endl;
    // std::string airportFile = "../tests/ap_small.dat";
    // std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS0(airportFileSmall, routesFileSmall);
    vector<string> result_moves0 = myBFS0.BFS_dest(3670, 3364);
    
    for(unsigned i = 0; i < result_moves0.size(); i++){
        cout << result_moves0[i] ;
        if(i != result_moves0.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }

    cout << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    

    std::cout << ("Testing BFS_dest with SMALL databases NO ROUTE") << std::endl;
    // std::string airportFile = "../tests/ap_small.dat";
    // std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS1(airportFileSmall, routesFileSmall);
    vector<string> result_moves1 = myBFS1.BFS_dest(3988, 2359);
    
    std::cout << (result_moves1.empty()) << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << ("Testing BFS_dest with FULL databases")  << std::endl;
    // std::string airportFile = "../tests/airport.dat";
    // std::string routesFile = "../tests/routes.dat";
    BFS myBFS2(airportFile, routesFile);
    vector<string> result_moves2 = myBFS2.BFS_dest(2972, 350);
    
    for(unsigned i = 0; i < result_moves2.size(); i++){
        cout << result_moves2[i] ;
        if(i != result_moves2.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }

    cout << endl;

    std::cout << "--------------------------------------------------" << std::endl;
    

    std::cout << ("Testing BFS_all with SMALL databases") << std::endl;
    // std::string airportFile = "../tests/ap_small.dat";
    // std::string routesFile = "../tests/routes_small.dat";
    BFS myBFS3(airportFileSmall, routesFileSmall);
    vector<string> result_moves3 = myBFS3.BFS_all(2305);
    
    std::cout << (result_moves3.size() == 4) << std::endl;
    

    std::cout << "--------------------------------------------------" << std::endl;
    
    return 0;
}