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