#include "Airport.h"

Airport::Airport(){
    id = 0;
    name = "";
    latitude = 0.0;
    longitude = 0.0;
}

Airport::Airport(int id, string name, double latitude, double longitude) {
    id_ = id;
    name_ = name;
    latitude_ = latitude;
    longitude = longtitude_;
}

std::string Airport::getName() {
    return name_;
}

int Airport::getID() {
    return id_;
}

int Airport::getLatitude() {
    return latitude_;
}

int Airport::getLongitude() {
    return latitude_;
}

void Airport::setId(int id) {
    id_ = id;

}
void setName(std::string name) {
    name_ = name;
}
void setLatitude(int latitude) {
    latitude_ = latitude;
}
void setLongitude(int longitude) {
    longitude_ = longitude;
}