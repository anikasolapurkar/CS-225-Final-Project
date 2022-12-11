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
    




    // cout << "testing BFS_moves" << endl;
    // string airportFile = "airports.dat";
    // string routesFile = "routes.dat";    
    // BFS myBFS(airportFile, routesFile);
    // vector<string> result_moves = myBFS.BFS_moves(2, 50);
    // cout << "Printing out first 50 moves from O'Hare airport" << endl;
    // for(unsigned i = 0; i < result_moves.size(); i++){
    //     cout << result_moves[i] ;
    //     if(i != result_moves.size()-1)
    //         cout << " --> ";
    //     if(i%5 == 0 && i != 0)
    //         cout << endl;
    // }
    // cout << endl;

    // std::cout << (51 == result_moves.size()) << std::endl;
    // std::cout << (result_moves.size()) << std::endl;
    // // std::cout << ("Chicago O'Hare International Airport" == result_moves[0]) << std::endl;
    // // std::cout << (result_moves[0]) << std::endl;
    // return 0;

    



    // cout << "testing BFS_dest" << endl;
    // string airportFile = "airports.dat";
    // string routesFile = "routes.dat";    
    // BFS myBFS(airportFile, routesFile);
    // vector<string> result_dest = myBFS.BFS_dest(3830, 3494);
    // cout << "Printing out traversal from O'Hare to Newark" << endl;
    // for(unsigned i = 0; i < result_dest.size(); i++){
    //     cout << result_dest[i] ;
    //     if(i != result_dest.size()-1)
    //         cout << " --> ";
    //     if(i%5 == 0 && i != 0)
    //         cout << endl;
    // }
    // cout << endl;

    // cout << ("Chicago O'Hare International Airport" == result_dest[0]) << endl;

    
    
    
    
    // PageRank *p_r = new PageRank(); 
    // int size = 2;
    // p_r->adjacency.resize(size,vector<double>(size));

    // p_r->adjacency[0][0] = 0.0;
    // p_r->adjacency[1][0] = 0.0;

    // p_r->adjacency[0][1] = 4.0;   
    // p_r->adjacency[1][1] = 6.0;  

    // p_r->airport_id.resize(size);
    // p_r->num = size;

    // p_r->PageRank::createadjacency(size, 0.85);
    // cout << (0.5 == p_r->adjacency[0][0]) << endl;
    // cout << (0.5 == p_r->adjacency[1][0]) << endl;
    // cout <<(1 == p_r->adjacency[0][1] + p_r->adjacency[1][1]) << endl;



    cout << "\n\n\n\n >>>>>>>>Testing Pagerank function bestairport()\n" << endl;
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
    vector<int> rank = p_r->top_airport(3); 
    cout << (1 == rank[0]) << endl;
    cout << (3 == rank[1]) << endl;
    cout << (2 == rank[2]) << endl;

    return 0;
}