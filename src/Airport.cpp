// #include "Airport.h"

// Airport::Airport(){
//     id_ = 0;
//     name_ = "";
//     latitude_ = 0.0;
//     longitude_ = 0.0;
// }

// Airport::Airport(string &line) {
//     std::string str = "";
//     std::vector<std::string> vector;
//     bool q = false;
//     for(size_t i = 0; i < line.size(); ++i){
//         char curr = line[i];
//         if(!q) {
//             if(curr == ',') {
//                 vector.push_back(str);
//                 str = "";
//             }
//             else if(curr == '"') {
//                      q = true;
//             }
//             str += curr;
//         }
//         else {
//             if (curr == '"' && i+1 < line.size()) {
//                 if(line[i+1] == '"') {
//                     str += '"';
//                     i++;
//                 }
//                 else {
//                     q = false;

//                 }
//             }
//             str += curr;
//         }
//     }
//     id_ = stoi(vector[0], nullptr);
//     name_ = vector[1];
//     latitude_ = stod(vector[6], nullptr);
//     longitude_ = stod(vector[7], nullptr);
// }

// Airport::Airport(int id, std::string name, double latitude, double longitude) {
//     id_ = id;
//     name_ = name;
//     latitude_ = latitude;
//     longitude = longitude_;
// }

// std::string Airport::getName() {
//     return name_;
// }

// int Airport::getID() {
//     return id_;
// }

// double Airport::getLatitude() {
//     return latitude_;
// }

// double Airport::getLongitude() {
//     return longitude_;
// }

// void Airport::setId(int id) {
//     id_ = id;

// }
// void Airport::setName(std::string name) {
//     name_ = name;
// }
// void Airport::setLatitude(int latitude) {
//     latitude_ = latitude;
// }
// void Airport::setLongitude(int longitude) {
//     longitude_ = longitude;
// }

 