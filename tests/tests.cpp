#include <iostream>
#include <vector>
#include <string>

#include "../Airport.h"
#include "../Djikstras.h"
#include "../BFS.h"

#include "../catch/catch.hpp"

using namespace std;

TEST_CASE("Testing Airport constructor with vector") { 
    cout<<"Testing vector constructor with Goroka Airport"<<endl;
    vector<string> data = {"1","Goroka Airport","","", "", "", "-6.081689834590001,", "145.391998291"};
    arr["Goroka Airport"] = Airport(data);
    string name = arr["Goroka Airport"].getName();
    int id = arr["Goroka Airport"].getID();
    int latitude = (int)arr["Goroka Airport"].getLatitude();
    int longitude = (int)arr["Goroka Airport"].getLongitude();

    REQUIRE(1 == id);
    REQUIRE("Goroka Airport" == name);
    REQUIRE(-6 == latitude);
    REQUIRE(145 == longitude);
}

TEST_CASE("Testing Airport constructor with string") { 
    cout<<"Testing string constructor with Madang Airport"<<endl;
    string madang = "2,\"Madang Airport\",\"Madang",\"Papua New Guinea\",\"MAG\",\"AYMD\",-5.20707988739,145.789001465,20,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
    vec["Madang Airport"] = Airport(madang);
    int id = (vec["Madang Airport"].getID());
    string name = (vertices["Madang Airport"].getName());
    int latitude = (int)vertices["Madang Airport"].getLatitude();
    int longitude = (int)vertices["Madang Airport"].getLongitude();
    
    REQUIRE(2 == id);
    REQUIRE("Madang Airport" == name);
    REQUIRE(-5 == latitude);
    REQUIRE(145 == longitude);
}

std::vector<Airport> readAirportCSV(std::string filename) {
    std::vector<Airport> airports;
    std::vector<std::string> test;
    std::fstream infile(filename);

     // Make sure the file is open
    if(!infile.is_open()) throw std::runtime_error("Could not open file");
    
    std::string line, field;
    while (std::getline(infile,line)) {
        test.push_back(line);
        std::stringstream ss(line);
        std::vector<std::string> fields;
        while (std::getline(ss,field,',')) {
            fields.push_back(field);
            //std::cout << field << std::endl;
        }
        
        // int id = std::stoi(fields[0]);
        // std::cout << id << std::endl;
        // std::string name = fields[1];
        // double lat = std::stod(fields[6]);
        // double longi = std::stod(fields[7]);
        // Airport ap(id, name, lat, longi);
        // airports.push_back(ap);
    }
    // Close the File
    infile.close();
    return airports;
}

int main(int argc, char** argv)
{
    std::vector<Airport> aps = readAirportCSV("ap_small.dat");
    //std::vector<std::string> t = readAirportCSV("ap_small.dat");
    // for (auto ap : aps) {
    //     //std::cout << "id:" << ap.getID() << ", name:" << ap.getName() << ", lat:" << ap.getLatitude() << ", long:" << ap.getLongitude();
    //     std::cout << "hi" << std::endl;
    // }
    // for (auto str : t) {
    //     std::cout << str << std::endl;
    // }
    return 0;
}
