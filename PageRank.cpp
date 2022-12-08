#include <iostream>
#include "PageRank.h"
#include <vector>
#include <numeric>

//default constructor 
PageRank::PageRank(){}

//initalizes the intitial vector passed into PageRank
vector<double> PageRank::vec_initial(){
    vector<double> init(this->num);
    for(int i = 0; i < this->num; i++){
        init[i] = rand();
    }
    return init;
}

//adjusts the adjacency matrix 
void PageRank::createadjacency(int num, double d) {
    this->num = num;
    double factor = (1-d)/num;
    for(int i = 0; i < num; i++){
        double sum = 0;
        for(int j = 0; j < num; j++){
            sum += adjacency[j][i];
        }     
        if(sum == 0){
            for(int j = 0; j < num; j++){
                adjacency[j][i] = 1/(double)num;
            }              
        }

        for(int j = 0; j < num; j++){
            adjacency[j][i] = (adjacency[j][i]/sum)*(d+factor);
        }             
    }
}

//perform pagerank algorithm and stores result in vector
vector<double> PageRank::rank(vector<double> initial, int time, bool store) {
    vector<double> vec = init;
    vector<double> vec2 = init;
    for(int t = 0; t < time; t++){
        for(int i = 0; i < num; i++){
            vec2[i] = 0;
            for(int j = 0; j < num; j++){
                vec2[i] += adjacency[i][j] * vec[j];
                if(store) {
                    double sum = 0;
                    for(std::vector<double>::iterator it = vec2.begin(); it != vec2.end(); it++)
                        sum += (*it)*(*it);
                        double s = sqrt(sum);
                    for(int k = 0; k < num; k++){
                        vec2[k] = vec2[k] / s;
                    }
                }
            }     
        }
        vec = vec2;
    }
    page_rank = vec;
    return vec;
}


//pick out the most important airport
vector<int> PageRank::top_airport(int num){
    int pos = 0;
    vector<double> biggest(num);
    vector<int> airport(num);
    for(int i = 0; i < num; i++){
        double maximum = 0;
        for(auto j = page_rank.begin(); j != page_rank.end(); j++){
            if(maximum < i*){
                bool val = true;
                for(auto k = biggest.begin(); k != biggest.end(); ++k){
                    if(*j == *k) {
                        val = false;
                        break;
                    }
                }
                if(val)
                    maximum = *i;
            }
        }
        biggest[pos] = (maximum);
        pos++;
    }
    pos = 0;
    for(int i = 0; i < num; i++){
        int counter = 0;
        for(auto it = page_rank.begin(); it != page_rank.end(); it++){
            if(biggest[i] == *it){
                airport[pos] = (airport_id[counter]);
                pos++;
            }
            counter++;
        }
    }
    //printing out the top airport 
    cout<<"top "; 
    cout<<num; 
    cout<<" important airport\n"; 
    for(int i = 0; i < num; i++){
        cout<<airport[i];
        cout<<"\n";
    }
    return airport;
}

//prints out the results of page rank algorithm
void PageRank::print_result(){
    cout<<"page rank result\n"; 
    cout<<" ID      value\n"; 
    for(int i = 0; i < this->num; i++){
        cout<<this->airport_id[i];
        cout<<" ";
        cout<<this->page_rank[i];
        cout<<"\n";
    }
    cout<<"\n";
}

//prints out adjancency matrix 
void PageRank::print_adjmatrix(){
    cout<<"adj matrix"<<endl;
    cout<<"      ";
    for(int i = 0; i < this->num; i++){
        cout<<this->airport_id[i];
        cout<<"           ";
    }
    cout<<"\n";
    for(int i = 0; i < this->num; i++){
        cout<<this->airport_id[i];
        cout<<"  ";
        for(int j = 0; j < this->num; j++){
            cout<<this->adjacency[i][j];
            cout<<"  ";
        } 
        cout<<"\n";
    }
    cout<<"\n";
}

