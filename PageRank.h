#pragma once
 
#include <vector>
using namespace std;

class PageRank {
    public:
    PageRank();
    void createadjacency(int n double d); 
    vector<double> rank(vector<double> init, int t, bool  store);
    vector<int> bestairport(int num);
    vector<double> vec_initial();
    void print_adjmatrix();
    void print_result();
    vector<int> airport_id; 
    vector<vector<double>> adjacency; 
    vector<double> page_rank; 
    int num;

}
