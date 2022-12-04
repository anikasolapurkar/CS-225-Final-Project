#include "AirportGraph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>

//DONE
Graph::Graph(){}

//DONE    
Graph::Graph(std::string & airportFile, std::string & routesFile) {
    insertAllVertices(airportFile);
    insertAllEdge(routesFile);
}

//DONE    
void Graph::insertVertex(int v, Airport ap) {
    vertices[v] = ap;
}


//DONE
//traverses airport.dat and inserts a vertex for each Airport
void Graph::insertAllVertices(std::string & fileName) {
    std::fstream file;
    file.open(fileName, ios::in);
    if (file.is_open()){   
        std::string currLine;
        while(getline(file, currLine)){ 
            //if a line has insufficient information, then just discard it, only add if it has 13 lines
            int comma = 0;
            for(unsigned i = 0; i < currLine.size(); ++i){
                char current = currLine[i];
                if(current == ',')
                    comma++;
            }
            if(comma == 13){
                //create and insert an airport object from current line in file
                Airport ap(currLine);
                insertVertex(ap.getID(), ap);
            }
        }
        file.close(); 
    }

}


//DONE     
vector<std::string> Graph::createEdgeHelper(std::string & line){
    std::string currString = "";
    std::vector<std::string> flightVector;

    //if a line has insufficient information, 
    //discard the line by returning default vector
    int comma = 0;
    for(size_t i = 0; i < line.size(); ++i){
        char current = line[i];
        if(current == '\\')
            return flightVector;
        if(current == ',')
            comma++;
    }
    if(comma != 8) {
        return flightVector;
    }

   //push back each string into a vector of each line in the data file
    for(size_t i = 0; i < line.size(); ++i){
        char current = line[i];
        //if a comma exists, then push the string into the vector
        if(current == ',') {
            flightVector.push_back(currString);
            currString = "";
        }
        else {
            currString += current;
        }
    }
    return flightVector;
}


//DONE
Route Graph::createEdge(vector<std::string> flightVector) {
    int source = std::stoi(flightVector[3]);
    int destination = std::stoi(flightVector[5]);
    auto svertex = vertices.find(source);
    auto dvertex = vertices.find(destination);
    //check if the source and dest airports are already inserted
    //only inserts when the route does not exist already
    if (svertex != vertices.end() && dvertex != vertices.end()) {
        double weight = calcWeight(source, destination);
        return Route(source, destination, weight);
    } else {
        return Route();
    }

}   

//DONE
void Graph::insertEdge(Route r){
    int source = r.getSourceId();
    int destination = r.getDestId();

    if (vertices[source].destAPs.find(destination) == vertices[source].destAPs.end())   
        (vertices[source].destAPs)[destination] = r;

}


//DONE
void Graph::insertAllEdge(std::string & fileName){
    std::fstream file;
    //open the file
    file.open(fileName, ios::in);
    if (file.is_open()){   
        std::string currLine;
                    
        //iterate through each line of the file
        while(getline(file, currLine)){ 
            std::vector<std::string> currVect = createEdgeHelper(currLine); //each line as a vector in the aiport.dat
            
            if(currVect != std::vector<std::string>()){
                Route f = createEdge(currVect);
                Route defaults = Route();
                if(!(f == defaults))
                    insertEdge(f);
            }
        }
        file.close(); 
    }
}

//DONE
double calcWeight(long double lat1, long double long1, long double lat2, long double long2) {
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
    long double R = 6371;
    ans = ans * R;
    return ans;
}

//DONE
double radianConvert(double degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
