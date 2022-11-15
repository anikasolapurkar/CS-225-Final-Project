
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

#include "../Airport.h"

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
