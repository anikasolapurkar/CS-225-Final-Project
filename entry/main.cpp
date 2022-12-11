#include <iostream>
#include <vector>
#include <string>

#include "./Airport.h"
#include "./Djikstras.h"
#include "./BFS.h"
#include "./PageRank.h"

using namespace std;



int main(int argc, char** argv)
{
    // std::cout << "testingtestingtesting" << std::endl;
    // vector<string> data = {"1","Goroka Airport","","", "", "", "-6.081689834590001,", "145.391998291"};
    // Airport a;
    
    // return 0;
    // Djikstras d;
    // vector<vector<int> > adjacencyMatrix
    //     = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //         { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //         { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //         { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //         { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //         { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
    //         { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
    //         { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    // std::vector<int> result;
    // result = d.dijkstra(adjacencyMatrix, 0, 3);
    // for (unsigned i = 0; i < result.size(); i++) {
    //   std::cout << result[i] << std::endl;
    // }
    
    cout << "testing BFS_moves" << endl;
    string airportFile = "airports.dat";
    string routesFile = "routes.dat";    
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

    std::cout << (51 == result_moves.size()) << std::endl;
    std::cout << ("Chicago O'Hare International Airport" == result_moves[0]) << std::endl;
}