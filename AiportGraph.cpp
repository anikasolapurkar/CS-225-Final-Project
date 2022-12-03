#include "AirportGraph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>

Graph::Graph(){}
        
Graph::Graph(std::string & airportFile, std::string & routesFile) {
    insertAllVertices(airportFile);
    insertAllEdge(routesFile);
}
        
void Graph::insertVertex(int v, Airport ap) {
    vertices[v] = ap;

}

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
        
vector<std::string> Graph::_createEdge(std::string & line){
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

}
Route Graph::createEdge(vector<std::string> flightVector) {

}   
void Graph::insertEdge(Route f){}


void Graph::insertAllEdge(std::string & fileName){
    std::fstream file;
    //open the file
    file.open(fileName, ios::in);
    if (file.is_open()){   
        std::string currLine;
                    
        //iterate through each line of the file
        while(getline(file, currLine)){ 
            std::vector<std::string> currVect = _createEdge(currLine); //each line as a vector in the aiport.dat
            
            if(currVect != std::vector<std::string>()){
                Route f = createEdge(currVect);
                Route defaultF = Route();
                if(!(f == defaultF))
                    insertEdge(f);
            }
        }
        file.close(); 
    }
}
