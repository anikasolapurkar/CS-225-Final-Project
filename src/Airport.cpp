#include "Airport.h"

Airport::Airport(){
    id_ = 0;
    name_ = "";
    latitude_ = 0.0;
    longitude_ = 0.0;
}

Airport::Airport(int id, std::string name, double latitude, double longitude) {
    id_ = id;
    name_ = name;
    latitude_ = latitude;
    longitude = longitude_;
}

Airport::Airport(std::string &line){
    //constructing a vector of strings of the airport information seperated by comma
    //quotes are not included
    //if input line does not contain all 13 columns, call default constructor 
    bool quoteFlag = false;
    std::string currString = "";
    std::vector<std::string> airportVector;

    // Iterate through all characters in the line
    for(size_t i = 0; i < line.size(); ++i){
        char current = line[i];

        // if quotation mark has not occured before
        if(!quoteFlag) {
            //push the current string to the vector when encounters a ","
            //and reset current string
            if(current == ',') {
                airportVector.push_back(currString);
                currString = "";
            }
            //if current char is a quotation mark, turn on the quote flag
            else if(current == '"')
                quoteFlag = true;
            //if just a regular char, append it to the current string
            else
                currString += current;
        }
        // if there is a quotation mark from before
        else{
            //if we are at the second quotation mark
            if(current == '"' && i+1 < line.size()) {
                if(line[i+1] == '"') {
                    currString += '"';
                    i++;
                }
                //don't add this quotation and turn off the flag
                else
                    quoteFlag = false;
            }
            //if just a regular char, append it to the current string
            else
                currString += current;
        }
    }
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