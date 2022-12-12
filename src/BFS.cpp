#include "BFS.h"
#include <climits>
#include <iostream>

//implementation constructor that calls a graph constructor
BFS::BFS(const string &airportFile, const string &routeFile){
    string a = airportFile;
    string r = routeFile;
    airport_graph = Graph(a, r);
}



vector<string> BFS::BFS_all(int sourceAP){
    vector<string> result;
    vector<bool> visited(14111, false);
    
    //BFS initialization
    queue<int> queue;
    queue.push(sourceAP);
    int currentAP = sourceAP;
    visited[currentAP] = true;
    
    
    while (!queue.empty()) {
        currentAP = queue.front();
        
        result.push_back(airport_graph.getAPName(currentAP));
        
        
        for (auto thing : airport_graph.adjVertWithWeight(currentAP)){
            
            if (visited[thing.first] == false) { 
                queue.push(thing.first);  
                visited[thing.first] = true;
            }
        }
        queue.pop();
    }
    return result;
}



vector<string> BFS::BFS_moves(int sourceAP, int moves){

    vector<string> result;
    vector<bool> visited(14111, false);
    //std::cout << __LINE__ << std::endl;
    
    queue<int> queue;
    queue.push(sourceAP);
    int currentAP = sourceAP;
    visited[currentAP] = true;
   
    while (!queue.empty()) {
        
        if(result.size() == (unsigned)moves + 1)
            return result;
        //cout << result.size() << endl;
        currentAP = queue.front();
        
        
        result.push_back(airport_graph.getAPName(currentAP));
        
        
        for (auto thing : airport_graph.adjVertWithWeight(currentAP)){
            
            //if the ID of the adjacent airport is not visited
            if (visited[thing.first] == false) { 
                //std::cout << __LINE__ << std::endl;
                //enqueue neighbor airport and set it to visited
                queue.push(thing.first);  
                visited[thing.first] = true;
            }
            //std::cout << __LINE__ << std::endl;
        }
        queue.pop();
    }

    return result;

}



vector<string> BFS::BFS_dest(int sourceAP, int destAP){
    vector<string> result;
    
    vector<bool> visited(14111, false);
    
    queue<int> queue;
    queue.push(sourceAP);
    int currentAP = sourceAP;
    visited[currentAP] = true;
    
   
    while (!queue.empty()) {
        
        currentAP = queue.front();
        if(currentAP == destAP){
            result.push_back(airport_graph.getAPName(currentAP));
            break;
        }
        //process currentAP by pushing its name to the vector
        result.push_back(airport_graph.getAPName(currentAP));
        //iterate thorugh all adjacent airports of the currentAP
        for (auto thing : airport_graph.adjVertWithWeight(currentAP)){
            //if the ID of the adjacent airport is not visited
            if (visited[thing.first] == false) { 
                //enqueue neighbor airport and set it to visited
                queue.push(thing.first);  
                visited[thing.first] = true;
            }
        }
        queue.pop();
    }
    //if destAP is not reached, return empty vector
    if(currentAP != destAP)
        return vector<string> ();
    return result;
}