#include "Airport.h"
using namespace std;

Airport::Airport(){
    id_ = 0;
    name_ = "";
    latitude_ = 0.0;
    longitude_ = 0.0;
} 


Airport::Airport(string &line){
    
    bool flag = false;
    std::string currS = "";
    std::vector<std::string> vect;

    for(size_t i = 0; i < line.size(); ++i){
        char current = line[i];

        if(flag == false) {
            
            if(current == ',') {
                vect.push_back(currS);
                currS = "";
            }
            
            else if(current == '"') {
                flag = true;
            }
    
            else {
                currS += current;
            }
        }
        
        else{
            
            if(current == '"' && i+1 < line.size()) {
                if(line[i+1] == '"') {
                    currS += '"';
                    i++;
                }
                
                else {
                    flag = false;
                }
            }
            else
                currS = currS + current;
        }
    }
    
    //updating private variables
    id_ = stoi(vect[0]);
    name_ = vect[1];
    latitude_ = stod(vect[6]);
    longitude_ = stod(vect[7]);
}


Airport::Airport(int id, std::string name, double latitude, double longitude) {
    id_ = id;
    name_ = name;
    latitude_ = latitude;
    longitude_ = longitude;
}

std::string Airport::getName() {
    return name_;
}

int Airport::getID() {
    return id_;
}

double Airport::getLatitude() {
    return latitude_;
}

double Airport::getLongitude() {
    return longitude_;
}

void Airport::setId(int id) {
    id_ = id;

}
void Airport::setName(std::string name) {
    name_ = name;
}
void Airport::setLatitude(int latitude) {
    latitude_ = latitude;
}
void Airport::setLongitude(int longitude) {
    longitude_ = longitude;
}

 