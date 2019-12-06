//
// Created by Raniery Costa Mendes on 11/23/19.
//
#include "Data.h"
#include <iostream>


 bool Data::operator<(Data obj) {

    return this->numberOfInjured < obj.numberOfInjured;
}

ostream& ::operator<<(ostream &os, const Data &obj) {

    os <<"Incident ID: " << obj.id << " " << "Date: " << obj.date << " ";
    os << "State: " << obj.state<< " City or County: " << obj.cityOrCounty << endl;

    os << " Latitude: " << obj.latitude << " Longitude: " << obj.longitude << endl ;
    os << " # of killed: " << obj.numberOfKilled << " # of injured "  << obj.numberOfInjured << endl;

    return os;
}

//incident_id	date	state	city_or_county	address	n_killed	n_injured incident_characteristics	latitude	longitude

