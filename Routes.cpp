#include "Routes.h"



Route::Route() {
    sourceAirport = -1;
    destAirport = -1;
    weight = -1;

}
Route::Route(int s, int d) {
    sourceAirport = s;
    destAirport = d;
    weight = -1;
}
Route::Route(int s, int d, double w) {
    sourceAirport = s;
    destAirport = d;
    weight = w;
}

        
int Route::getSourceId() {
    return sourceAirport;
}      
int Route::getDestId() {
    return destAirport;
}        
double Route::getWeight() {
    return weight;
}
       
        
void Route::setWeight(double w) {
    weight = w;
}
void Route::setSource(double s) {
    sourceAirport = s;
}
void Route::setDestination(double d) {
    destAirport = d;
}

bool Route::operator<(const Route& other) const {
    return weight < other.weight;
}
bool Route::operator==(Route& other) const {
    bool toreturn = true;
    if (sourceAirport != other.sourceAirport) {
        toreturn = false;
    }
    if (destAirport != other.destAirport) {
        toreturn = false;
    }
    return toreturn;
}