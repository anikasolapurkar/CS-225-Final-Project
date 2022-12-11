#pragma once
#include <string>
#include <vector>


class Airport {
    public:
    Airport();
    Airport(int id, std::string name, double latitude, double longitude);
    std::string getName();
    int getID();
    double getLatitude();
    double getLongitude();
    void setId(int id);
    void setName(std::string name);
    void setLatitude(int latitude);
    void setLongitude(int longitude);
    unordered_map<int, Route> destAPs;
    Airport(std::string &line);

    private:
    int id_;
    std::string name_;
    double latitude_; 
    double longitude_;

};