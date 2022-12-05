#include <iostream>
#include "PageRank.h"
#include <vector>
#include <numeric>


//initalizes the intitial vector passed into PageRank
vector<double> PageRank::vec_initial(){
    vector<double> init(this->num);
    for(int i = 0; i < this->num; i++){
        initial[i] = rand();
    }
    return init;
}


//adjusts the adjacency matrix 
void PageRank::createadjacency(int n, double d) {
    this->n = n;
    double factor = (1-d)/n;
    for(int i = 0; i < n; i++){
        double sum = 0;
        for(int j = 0; j < n; j++){
            sum += adjacency[j][i];
        }     
        if(sum == 0){
            for(int j = 0; j < n; j++){
                adjacency[j][i] = 1/(double)n;
            }              
        }

        for(int j = 0; j < n; j++){
            adjacency[j][i] = (adjacency[j][i]/sum)*d+factor;
        }             
    }
}

//perform pagerank algorithm and stores result in vector
vector<double> PageRank::rank(vector<double> initial, int t, bool store) {
    vector<double> vec = initial;
    vector<double> vec2 = initial;
    for(int t = 0; t < t; t++){
        for(int i = 0; i < num; i++){
            vec2[i] = 0;
            for(int j = 0; j < num; j++){
                vec2[i] += adjacency[i][j] * vec[j];
                if(store) {
                    double sum = 0;
                    for(std::vector<double>::iterator it = vec2.begin(); it != vec2.end(); ++it)
                        sum += (*it)*(*it);
                        double s = sqrt(sum);
                    for(int n = 0; n < num; n++){
                        vec2[n] = vec2[n] / s;
                    }
                }

            }     
        }
        vec = vec2;
    }
    page_rank = vec;
    return vec;
}

