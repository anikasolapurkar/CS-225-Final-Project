#include "AirportGraph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;


//default constructor
Graph::Graph(){

}


//constructor with airport.dat and routes.dat
//it calls the two helper functions
Graph::Graph(std::string & airportFile, std::string & routesFile){
    //std::cout << __LINE__ << std::endl;
    insertAllVertices(airportFile);
    insertAllEdge(routesFile);
    

}


//construct the vertices 
//such that each airport object is connected with its ID
void Graph::insertVertex(int v, Airport ap)
{
    //std::cout << __LINE__ << std::endl;
    vertices[v] = ap;
    //std::cout << __LINE__ << std::endl;
}


//takes airport.dat and insert each airport into the class line by line
void Graph::insertAllVertices(std::string & fileName)
{
    
    std::fstream file;
    //open the file
    file.open(fileName, ios::in);
    if (file.is_open()){   
        std::string currLine;
        //iterate through each line of the file
        while(getline(file, currLine)){ 
            //if a line has insufficient information, 
            //discard the line by returning default vector
            int commas = 0;
            
            for(unsigned i = 0; i < currLine.size(); ++i){
                //std::cout << __LINE__ << std::endl;
                char current = currLine[i];
                if(current == ',') {
                    commas++;
                }
            }
            //std::cout << commas << std::endl;
            if(commas == 13){
                //create and insert an airport object from current line in file
                
                Airport ap(currLine);
                
                insertVertex(ap.getID(), ap);
            
            }
        }
        file.close(); 
    }
    
}


std::vector<std::string> Graph::createEdgeHelper(string & line){
    std::string currString = "";
    std::vector<std::string> vect;

    int comma = 0;
    for(size_t i = 0; i < line.size(); ++i){
        char current = line[i];
        if(current == '\\')
            return vect;
        if(current == ',')
            comma++;
    }
    if(comma != 8)
        return vect;
    
    // Iterate through all characters in the line
    for(size_t i = 0; i < line.size(); ++i){
        char curr = line[i];
        //if a comma is detected, push the current string to the vector
        if(curr == ',') {
            vect.push_back(currString);
            currString = "";
        }
        //otherwise if it's just a regular char, append it to the current string
        else
            currString += curr;
    }

    return vect;
}



Route Graph::createEdge(std::vector<std::string> flightVector){
    int source = stoi(flightVector[3]);
    int dest = stoi(flightVector[5]);
    auto it = vertices.find(source);
    auto it2 = vertices.find(dest);
    
    if(it != vertices.end() && it2 != vertices.end()){
        double weight = calcWeight(source, dest);
        return Route(source, dest, weight);
    }
    return Route();
}



void Graph::insertEdge(Route r){       
    int source = r.getSourceId();
    int dest = r.getDestId();

    if (vertices[source].destAPs.find(dest) == vertices[source].destAPs.end())   
        (vertices[source].destAPs)[dest] = r;
}


//similar to insert all vertices
//iterates through routes.dat and insert flight for each line 
void Graph::insertAllEdge(std::string & fileName){
    std::fstream file;
    //open the file
    file.open(fileName, ios::in);
    if (file.is_open()){   
        std::string currLine;
                    
        //iterate through each line of the file
        while(getline(file, currLine)){ 
            std::vector<std::string> vect = createEdgeHelper(currLine);
            
            if(vect != std::vector<std::string>()){
                Route r = createEdge(vect);
                Route defaultr = Route();
                if(!(r == defaultr))
                    insertEdge(r);
            }
        }
        file.close(); 
    }
}



unordered_map<int, Airport> Graph::getVertices(){
    return vertices;
}



unordered_map<int, Route> Graph::adjVertWithWeight(int airportID) {
    auto it = vertices.find(airportID);
    if(it != vertices.end()){
        Airport& ap = vertices[airportID];
        return ap.destAPs;
    }
    return unordered_map<int, Route> ();
}

string Graph::getAPName(int ID){
    auto it = vertices.find(ID);
    if(it != vertices.end()){
        return vertices[ID].getName();
    }
    return string();
}



double Graph::calcWeight(int fromID, int toID){
    double latitude1 = radianConvert(vertices[fromID].getLatitude());
    double longitude1 = radianConvert(vertices[fromID].getLongitude());
    double latitude2 = radianConvert(vertices[toID].getLatitude());
    double longitude2 = radianConvert(vertices[toID].getLongitude());

    //calculate the difference
    double lonDiff = longitude2 - longitude1;
    double latDiff = latitude2 - latitude1;
    
    //using Haversine Formula, R is radious of earth in KM
    long double ans = pow(sin(latDiff / 2), 2) +cos(latitude1) * cos(latitude2) * pow(sin(lonDiff / 2), 2);
    ans = 2 * asin(sqrt(ans));
    double R = 6371;
    ans *= R;
    return ans; 
}


//helper function to calcWeight
double Graph::radianConvert(double degree)
{
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 

//traversal graph to populate adj matrix for pagerank
void Graph::adjMatrix(PageRank *matr){

    int size = vertices.size();
    matr->adjacency.resize(size,vector<double>(size));
    matr->airport_id.resize(size);
    matr->num = size;


    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matr->adjacency[i][j] = 0.0;
        }        
    }

    int x = 0;
    for(auto it = vertices.begin(); it != vertices.end(); ++it){
        if(it->second.getID() == 0){
            continue;
        }
        matr->airport_id[x] = (it->second.getID());
        x++;     
    }
    
    x = 0;
    for(auto it = vertices.begin(); it != vertices.end(); ++it){
        if(x == size) break;
        if(it->second.getID() == 0){
            continue;
        }

        //check the flights of the current vertices/airport
        for(auto flight = it->second.destAPs.begin(); flight != it->second.destAPs.end(); ++flight){
            int y = 0;
            //find out the proper place for the weight of the current flight according to the namelist
            for (auto temp = matr->airport_id.begin(); temp != matr->airport_id.end(); ++temp) {
                if (*temp == flight->second.getDestId()) break;
                y++;
            } 
            if(y == size) break;
           // matr->adjacency[y][x] = flight->second.getWeight();
            if (flight->second.getWeight() > 0) {
                matr->adjacency[y][x] = 1.0;
            }
        }
        x++;
    }
}

void Graph::populateAdjWeighted() {
    int size = vertices.size();
    adjWeighted.resize(size,vector<double>(size));
    airport_id.resize(size);


    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            adjWeighted[i][j] = 0.0;
        }        
    }

    int x = 0;
    for(auto it = vertices.begin(); it != vertices.end(); ++it){
        if(it->second.getID() == 0){
            continue;
        }
        airport_id[x] = (it->second.getID());
        x++;     
    }
    
    x = 0;
    for(auto it = vertices.begin(); it != vertices.end(); ++it){
        if(x == size) break;
        if(it->second.getID() == 0){
            continue;
        }

        //check the flights of the current vertices/airport
        for(auto flight = it->second.destAPs.begin(); flight != it->second.destAPs.end(); ++flight){
            int y = 0;
            //find out the proper place for the weight of the current flight according to the namelist
            for (auto temp = airport_id.begin(); temp != airport_id.end(); ++temp) {
                if (*temp == flight->second.getDestId()) break;
                y++;
            } 
            if(y == size) break;
            adjWeighted[y][x] = flight->second.getWeight();
            
        }
        x++;
    }

}