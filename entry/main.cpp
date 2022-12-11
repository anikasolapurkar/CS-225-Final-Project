

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
    std::cout << "testingtestingtesting" << std::endl;
    vector<string> data = {"1","Goroka Airport","","", "", "", "-6.081689834590001,", "145.391998291"};
    Airport a;
    
    return 0;

    TEST_CASE("Testing BFS_moves") {
    
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

    REQUIRE(51 == result_moves.size());
    REQUIRE("Chicago O'Hare International Airport" == result_moves[0]);
}
}