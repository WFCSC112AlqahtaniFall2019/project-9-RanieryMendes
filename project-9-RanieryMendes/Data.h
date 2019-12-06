//
// Created by Raniery Costa Mendes on 11/23/19.
//

#include <string>
using namespace std;
#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H

class Data{
//incident_id	date	state	city_or_county	address	n_killed	n_injured incident_characteristics	latitude	longitude
public:
    int id;
    string date;
    string state;
    string cityOrCounty;
    string address;
    int numberOfKilled;
    int numberOfInjured;
    string incidentCharacteristics;
    double latitude;
    double longitude;
    bool operator<(Data obj);
    friend ostream& operator<<(ostream& os, const Data& obj);

};

#endif //PROJECT9_DATA_H
